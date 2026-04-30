#include "WeaponBase.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	PelletCount = 10;
	SpreadAngle = 5.0f;
	RecoilPitch = 2.0f;
}

void AWeaponBase::Fire()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return;

	FVector StartLocation = WeaponMesh->GetSocketLocation(TEXT("Muzzle"));
	FVector ForwardDir = OwnerPawn->GetControlRotation().Vector();

	for (int32 i = 0; i < PelletCount; ++i)
	{
		FVector RandomizedDir = FMath::VRandCone(ForwardDir, FMath::DegreesToRadians(SpreadAngle));
		FVector EndLococation = StartLocation + (RandomizedDir * 5000.0f);

		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(OwnerPawn);

		bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLococation, ECC_Visibility, Params);

		if (bHit)
		{
			DrawDebugLine(GetWorld(), StartLocation, Hit.ImpactPoint, FColor::Green, false, 2.0f, 0, 1.0f);
			DrawDebugPoint(GetWorld(), Hit.ImpactPoint, 10.0f, FColor::Green, false, 2.0f);
		}
		else
		{
			DrawDebugLine(GetWorld(), StartLocation, EndLococation, FColor::Red, false, 2.0f, 0, 1.0f);
		}
	}

	if (OwnerPawn)
	{
		OwnerPawn->AddControllerPitchInput(-RecoilPitch);
		OwnerPawn->AddControllerYawInput(FMath::FRandRange(-1.0f, 1.0f));
	}
}
