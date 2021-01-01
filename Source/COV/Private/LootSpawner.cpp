// Fill out your copyright notice in the Description page of Project Settings.

#include "LootSpawner.h"


#include "LootDetails.h"
#include "UE4Helpers.h"
#include "Engine/SCS_Node.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(LogLootSpawner)

float FLootSpawnDefinition::GetSpawnProbabilityWeight() const
{
	ULootDetails* LootDetailsComponent = UE4CodeHelpers::FindDefaultComponentsByClass<ULootDetails>(LootType, ULootDetails::StaticClass());

	if(LootDetailsComponent)
	{
		return SpawnProbabilityWeight / LootDetailsComponent->Rarity;
	}
	
	return 1.0f;
}

FString FLootSpawnDefinition::ToString() const
{
	FString FinalString = FString("\n......[LootType = ") + GetNameSafe(LootType);
	
	FinalString = FinalString + FString(", SpawnProbabilityWeight = ") + FString::SanitizeFloat(SpawnProbabilityWeight);
	FinalString = FinalString + FString(", Modulated SpawnProbabilityWeight = ") + FString::SanitizeFloat(GetSpawnProbabilityWeight());
	FinalString = FinalString + FString(", bIgnoreLootRarityModulation = ") + ((bIgnoreLootRarityModulation)?(FString("TRUE")):(FString("FALSE")));
	
	FinalString = FinalString  + FString("]");
	return FinalString;
}

FString FLootProfile::ToString() const
{
	FString FinalString("...[Amount of loot to spawn (min ");

	FinalString = FinalString + FString::FromInt(AmountOfLootToSpawn.MinimumAmountToSpawn);
	FinalString = FinalString + FString(", max ");
	FinalString = FinalString + FString::FromInt(AmountOfLootToSpawn.MaximumAmountToSpawn);

	FinalString = FinalString + FString(")");
	
	for(const FLootSpawnDefinition& LSD : LootSpawnDefinitions)
	{
		FinalString = FinalString + LSD.ToString();
	}

	return FinalString;
}

// Sets default values
ALootSpawner::ALootSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

bool ALootSpawner::SpawnLoot(FLootProfile LootProfileToSpawn)
{	
	UE_LOG(LogLootSpawner, Log, TEXT("Beginning loot spawning event of profile =\n%s"), *LootProfileToSpawn.ToString());
	UWorld* World = GetWorld();
	check(IsValid(World));

	if(!ensureAlwaysMsgf(LootProfileToSpawn.LootSpawnDefinitions.Num() > 0, TEXT("No loot definitions defined. Did you forget to define some? (%s) can't spawn any loot."), *GetNameSafe(this)))
	{
		return false;
	}
	
	int32 LootSpawned = 0;
	int32 FailedSpawned = 0;
	FLootSpawnDefinition* LootSelectedForSpawn = nullptr;
	const int32 AmountOfLootToSpawn = UKismetMathLibrary::RandomIntegerInRange(LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, LootProfileToSpawn.AmountOfLootToSpawn.MaximumAmountToSpawn);

	//	Spawn loot...
	do
	{
		//	See which loot will spawn next...
		LootSelectedForSpawn = SelectLootFromDefinition(LootProfileToSpawn);

		//	Spawn loot now
		if(LootSelectedForSpawn && IsValid(LootSelectedForSpawn->LootType))
		{
			FActorSpawnParameters SpawnParams;
			const FVector& Location = GetLootSpawnLocation(*LootSelectedForSpawn);
			const FRotator& Rotation = GetLootSpawnRotation(*LootSelectedForSpawn);
			AActor* SpawnedActor = World->SpawnActor(LootSelectedForSpawn->LootType, &Location, &Rotation, SpawnParams);
		
			if(IsValid(SpawnedActor))
			{
				Cast<UPrimitiveComponent>(SpawnedActor->GetRootComponent())->AddImpulse(SpawnedActor->GetActorForwardVector() * 100.0f);
				Cast<UPrimitiveComponent>(SpawnedActor->GetRootComponent())->AddAngularImpulseInRadians(GetActorRightVector() * 20.0f);
				
				UE_LOG(LogLootSpawner, Verbose, TEXT("(%s) spawned loot (%s). "), *GetNameSafe(this), *GetNameSafe(SpawnedActor));
				LootSpawned++;
				LootSelectedForSpawn->TimesAlreadySpawned++;

				//	If the loot can no longer be spawned, remove it from the definitions
				if(LootSelectedForSpawn->MaximumNumberOfSpawns > 0 && LootSelectedForSpawn->MaximumNumberOfSpawns == LootSelectedForSpawn->TimesAlreadySpawned)
				{
					const int32 IndexToRemove = LootProfileToSpawn.LootSpawnDefinitions.Find(*LootSelectedForSpawn);
					LootProfileToSpawn.LootSpawnDefinitions.RemoveAt(IndexToRemove);
					UE_LOG(LogLootSpawner, Verbose, TEXT("Maximum number of loot (%s) spawned by (%s). It will no longer spawn in this loot spawn event."), *GetNameSafe(LootSelectedForSpawn->LootType), *GetNameSafe(this));
				}
			}
			else
			{
				FailedSpawned++;
			}
		}
		else
		{
			FailedSpawned++;
		}

		LootSelectedForSpawn = nullptr;
	}
	while((LootSpawned < AmountOfLootToSpawn) && (LootProfileToSpawn.LootSpawnDefinitions.Num() > 0));

	ensureAlwaysMsgf(LootSpawned >= LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, TEXT("Loot spawner (%s) could not spawn the required amount (%d) of loot. Successful spawns (%d)"), *GetNameSafe(this), LootProfileToSpawn.AmountOfLootToSpawn.MinimumAmountToSpawn, LootSpawned);
	
	UE_LOG(LogLootSpawner, Log, TEXT("...loot spawning event done. Successful spawns = %d, failures = %d"), LootSpawned, FailedSpawned);

	return FailedSpawned > 0;
}

FLootSpawnDefinition* ALootSpawner::SelectLootFromDefinition(FLootProfile& LootProfileIn) const
{
	//	1.
	float TotalWeightOfAllLoot = 0.0f;
	for(const FLootSpawnDefinition& LootDefinition : LootProfileIn.LootSpawnDefinitions)
	{
		TotalWeightOfAllLoot += LootDefinition.GetSpawnProbabilityWeight();
	}

	//	2.
	//	Throw dart...
	const float Dart = UKismetMathLibrary::RandomFloatInRange(0.0f, TotalWeightOfAllLoot);

	//	3.
	//	See where dart landed
	float LandingLocation = 0.0f;
	int32 Index = 0;
	for(FLootSpawnDefinition& LootDefinition : LootProfileIn.LootSpawnDefinitions)
	{
		LandingLocation += LootDefinition.GetSpawnProbabilityWeight();
			
		if(LandingLocation >= Dart)
		{
			ensureAlwaysMsgf(IsValid(LootDefinition.LootType), TEXT("LootDefinition is missing loot type. Can't spawn loot in the definition of index (%d) on (%s) spawner."), Index, *GetNameSafe(this));
			return &LootDefinition;
		}

		Index++;
	}

	return nullptr;
}

FRotator ALootSpawner::GetLootSpawnRotation(const FLootSpawnDefinition& LootDefinition) const
{
	return UKismetMathLibrary::RandomRotator(true);
}

FVector ALootSpawner::GetLootSpawnLocation(const FLootSpawnDefinition& LootDefinition) const
{
	return GetActorLocation();
}

// Called when the game starts or when spawned
void ALootSpawner::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ALootSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}