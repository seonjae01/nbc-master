#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 PelletCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float SpreadAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float RecoilPitch;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire();
};
