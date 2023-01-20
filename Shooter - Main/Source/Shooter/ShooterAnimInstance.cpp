// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Weapon.h"
#include "WeaponType.h"

UShooterAnimInstance::UShooterAnimInstance() :
	Speed(0.f),
	bIsInAir(false),
	MovementOffsetYaw(0.f),
	LastMovementOffsetYaw(0.f),
	bAiming(false),
	CharacterRotation(0.f),
	CharacterRotationLastFrame(0.f),
	TurnInPlaceYaw(0.f),
	TurnInPlaceYawLF(0.f),
	YawDelta(0.f),
	RootYawOffSet(0.f),
	Pitch(0.f),
	bReloading(false),
	OffsetState(EOffsetState::EOS_Hip),
	EquipedWeaponType(EWeaponType::EWT_MAX),
	bShouldUseFABRIK(false)

{

}


void  UShooterAnimInstance::UpdateAnimationPorperties(float DeltaTime) 
{


	if (ShooterCharacter == nullptr) 
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	if (ShooterCharacter)
	{
		bReloading = ShooterCharacter->GetCombatState() == ECombatState::ECS_Reloading;
		/*bEquipping for recoil weight when needed*/
		bEquipping = ShooterCharacter->GetCombatState() == ECombatState::ECS_Equipping;
		bShouldUseFABRIK = ShooterCharacter->GetCombatState() == ECombatState::ECS_Unoccupied || ShooterCharacter->GetCombatState() == ECombatState::ECS_FireTimerInProgress;

		// Get the lateral speed of the character from velocity
		FVector Velocity{ ShooterCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// Is the character in the air?
		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();

		// Is the character accelerating?
		if (ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.0f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}

		FRotator AimRotation = ShooterCharacter->GetBaseAimRotation();
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(ShooterCharacter->GetVelocity());

		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;

		if (ShooterCharacter->GetVelocity().Size() > 0.f) 
		{
			LastMovementOffsetYaw = MovementOffsetYaw;
		}

		bAiming = ShooterCharacter->GetAiming();
		
		if (bReloading)
		{
			OffsetState = EOffsetState::EOS_Reloading;
		}
		else if (bIsInAir)
		{
			OffsetState = EOffsetState::EOS_InAir;
		}
		else if (ShooterCharacter->GetAiming())
		{
			OffsetState = EOffsetState::EOS_Aiming;
		}
		else
		{
			OffsetState = EOffsetState::EOS_Hip;
		}
		// Check if ShooterCharacter has a valid EquippedWeapon
		if (ShooterCharacter->GetEquippedWeapon())
		{
			EquipedWeaponType = ShooterCharacter->GetEquippedWeapon()->GetWeaponType();
		}
	}
	TurnInPlace();
	Lean(DeltaTime);
}

void UShooterAnimInstance::NativeInitializeAnimation()
{

	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());

}

void UShooterAnimInstance::TurnInPlace()
{
	if (ShooterCharacter == nullptr) return;

	Pitch = ShooterCharacter->GetBaseAimRotation().Pitch;

	if (Speed > 0 || bIsInAir)
	{
		// If Chracter is moving we don't want the Character to move in place
		RootYawOffSet = 0.f;
		TurnInPlaceYaw = ShooterCharacter->GetActorRotation().Yaw;
		TurnInPlaceYawLF = TurnInPlaceYaw;
		RotationCurveLastFrame = 0.f;
		RotationCurve = 0.f;
	}
	else
	{
		TurnInPlaceYawLF = TurnInPlaceYaw;
		TurnInPlaceYaw = ShooterCharacter->GetActorRotation().Yaw;

		const float TIPYawDelta{ TurnInPlaceYaw - TurnInPlaceYawLF };

		// Root Yaw Offset, updated and clamped to [-180.180]
		RootYawOffSet = UKismetMathLibrary::NormalizeAxis( RootYawOffSet - TIPYawDelta);

		// 1.0 if turning, 0.0 if not
		const float Turning{ GetCurveValue(TEXT("Turning")) };
		if (Turning > 0)
		{
			RotationCurveLastFrame = RotationCurve;
			RotationCurve = GetCurveValue(TEXT("Rotation"));
			const float DeltaRotation{ RotationCurve - RotationCurveLastFrame };

			// if RootYawOffset > 0, we are TurningLeft. RootYawOffset < 0, we are TurningRight
			RootYawOffSet > 0 ? RootYawOffSet -= DeltaRotation : RootYawOffSet += DeltaRotation;

			const float AbsRootYawOffSet{ FMath::Abs(RootYawOffSet) };
			if (AbsRootYawOffSet > 90.f)
			{
				const float YawExcess{ AbsRootYawOffSet - 90.f };
				RootYawOffSet > 0 ? RootYawOffSet -= YawExcess : RootYawOffSet += YawExcess;
			}
		}
		
	}
}

void UShooterAnimInstance::Lean(float DeltaTime)
{
	if (ShooterCharacter == nullptr) return;

	CharacterRotationLastFrame = CharacterRotation;
	CharacterRotation = ShooterCharacter->GetActorRotation();

	FRotator Delta{ UKismetMathLibrary::NormalizedDeltaRotator(CharacterRotation, CharacterRotationLastFrame) };

	const float Target{ Delta.Yaw / DeltaTime };

	const float Interp{ FMath::FInterpTo(YawDelta, Target, DeltaTime, 6.f) };
	
	YawDelta = FMath::Clamp(Interp, -90.f, 90.f);

	//if (GEngine) GEngine->AddOnScreenDebugMessage(1, -1, FColor::Red, FString::Printf(TEXT("Yaw Delta: %f"), YawDelta));
	//if (GEngine) GEngine->AddOnScreenDebugMessage(2, -1, FColor::Blue, FString::Printf(TEXT("Delta.Yaw: %f"), Delta.Yaw));
}
