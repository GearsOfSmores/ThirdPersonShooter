// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "AmmoType.h"
#include "WeaponType.h"
#include "Engine/DataTable.h"
#include "Weapon.generated.h"



USTRUCT(BlueprintType)
struct FWeaponDataTable : public FTableRowBase
{
	GENERATED_BODY()


		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmmoType AmmoType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 WeaponAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MagazingCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USoundCue* PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundCue* EquipSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* InventoryIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* AmmoIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ClipBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ReloadMontageSection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UAnimInstance> AnimBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* CrosshairsMiddle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* CrosshairsLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* CrosshairsRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* CrosshairsTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* CrosshairsBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AutoFireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName BoneToHide;


};
/**
 * 
 */
UCLASS()
class SHOOTER_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();

	virtual void Tick(float DeltaTime) override;
protected:
	
	void StopFalling();

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay() override;

	void FinishMovingSlide();

	void UpdateSlideDisplacement();


private:
	FTimerHandle ThrowWeaponTimer;
	float ThrowWeaponTime;
	bool bFalling;

	/* ammou count for weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	int32 Ammo;

	/* Maximum Ammo that our weapon can hold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	int32 MagazineCapacity;

	/* The type of Weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	EWeaponType WeaponType;

	/* AmmoType sets the starting ammotype for each weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	EAmmoType AmmoType;

	/* FName for the Reload Montage Section */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	FName ReloadMontageSection;

	/* true when moving the clip */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Properies", meta = (AllowPrivateAccess = "true"))
	bool bMovingClip;

	/* Name for the clip bone */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties", meta = (AllowPrivateAccess = "true"))
	FName ClipBoneName;

	/* Damgae caused by bullets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties", meta = (AllowPrivateAccess = "true"))
	float Damage;

	/* Damage when bullet hits Head */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties", meta = (AllowPrivateAccess = "true"))
	float HeadShotDamage;

	/** Data table for weapon properties */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UDataTable* WeaponDataTable;

	/*Crosshair Textures*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UTexture2D* CrosshairsMiddle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UTexture2D* CrosshairsLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UTexture2D* CrosshairsRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UTexture2D* CrosshairsTop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		UTexture2D* CrosshairsBottom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
	float AutoFireRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		class UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
		USoundCue* FireSound;

	/* Name of the bone to hide on the weapon mesh */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataTable, meta = (AllowPrivateAccess = "true"))
	FName BoneToHide;

	/* Amount that the slide is pushed back during pistol fire */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pistol, meta = (AllowPrivateAccess = "true"))
	float SlideDisplacement;

	/*Curve for SlideDisplacement*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pistol, meta = (AllowPrivateAccess = "true"))
	UCurveFloat* SlideDisplacementCurve;

	/*Time handle for updating SlideDisplacement*/
	FTimerHandle SlideTimer;

	/* Time for Displacing the slide */
	float SlideDisplacementTime;

	/* True when moving pistol slide*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pistol, meta = (AllowPrivateAccess = "true"))
	bool bMovingSlide;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pistol, meta = (AllowPrivateAccess = "true"))
	float MaxSlideDisplacement;

public:
	/* Adds an impluse to the weapon */
	void ThrowWeapon();

	FORCEINLINE int32 GetAmmo() const { return Ammo; }
	FORCEINLINE int32 GetMagazineCapacity() const{ return MagazineCapacity;  }

	/* decreases ammo when firing weapon */
	void DecreaseAmmo();

	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; }
	FORCEINLINE EAmmoType GetAmmoType() const { return AmmoType; }
	FORCEINLINE FName GetReloadMontagesection() const { return ReloadMontageSection; }
	FORCEINLINE void SetReloadMontagesection(FName Name)  {  ReloadMontageSection = Name; }
	FORCEINLINE FName GetClipBoneName() const { return ClipBoneName; }
	FORCEINLINE void SetClipBoneName(FName Name) { ClipBoneName = Name; }
	FORCEINLINE float GetDamage() const { return Damage; }
	FORCEINLINE float GetHeadShotDamage() const{ return HeadShotDamage; }
	FORCEINLINE float GetAutoFireRate() const { return AutoFireRate; }
	FORCEINLINE UParticleSystem* GetMuzzleFlash() const { return MuzzleFlash; }
	FORCEINLINE USoundCue* GetFireSound() const { return FireSound; }

	void StartSlideTimer();

	void ReloadAmmo(int32 Ammount);

	FORCEINLINE void SetMovingClip(bool Move) { bMovingClip = Move; }

	bool ClipIsFull();
};
