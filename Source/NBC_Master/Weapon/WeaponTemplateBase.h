#pragma once

#include "CoreMinimal.h"
#include "Weapon/WeaponBase.h"
#include "WeaponTemplateBase.generated.h"

UCLASS()
class NBC_MASTER_API AWeaponTemplateBase : public AWeaponBase
{
	GENERATED_BODY()

public:
	virtual void Fire() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reload();

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool CheckAmmo();

	UFUNCTION(BlueprintImplementableEvent)
	void ProcessFiring();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayEffects();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateAmmo();
};
