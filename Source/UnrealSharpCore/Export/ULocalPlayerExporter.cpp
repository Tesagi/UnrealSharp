﻿#include "ULocalPlayerExporter.h"
#include "UnrealSharpCore/CSManager.h"

void UULocalPlayerExporter::ExportFunctions(FRegisterExportedFunction RegisterExportedFunction)
{
	EXPORT_FUNCTION(GetLocalPlayerSubsystem)
}

void* UULocalPlayerExporter::GetLocalPlayerSubsystem(UClass* SubsystemClass, APlayerController* PlayerController)
{
	if (!IsValid(PlayerController) || !IsValid(SubsystemClass))
	{
		return nullptr;
	}

	ULocalPlayerSubsystem* LocalPlayerSubsystem = PlayerController->GetLocalPlayer()->GetSubsystemBase(SubsystemClass);
	return UCSManager::Get().FindManagedObject(LocalPlayerSubsystem).GetIntPtr();
}