// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Project.h"
#include "ProjectGameMode.h"
#include "ProjectPawn.h"

AProjectGameMode::AProjectGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AProjectPawn::StaticClass();
}
