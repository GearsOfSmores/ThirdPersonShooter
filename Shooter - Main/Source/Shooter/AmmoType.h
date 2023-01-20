#pragma once

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	EAT_9mm UMETA(DisplayNAme = "9mm"),
	EAT_AR UMETA(DisplayName = "AssaultRifle"),

	ECS_NAX UMETA(DisplayName = "DefaultMAX")
};