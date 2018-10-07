// Fill out your copyright notice in the Description page of Project Settings.

#include "COVConsoleVariables.h"

static TAutoConsoleVariable<int32> CVarShowEchoProfilerDebugSphere(TEXT("COV.ShowEchoProfilerDebugSphere"),
	0,
	TEXT("Show the aproximate size of the echo profile as volume."));

COVConsoleVariables::COVConsoleVariables()
{
}

COVConsoleVariables::~COVConsoleVariables()
{
}
