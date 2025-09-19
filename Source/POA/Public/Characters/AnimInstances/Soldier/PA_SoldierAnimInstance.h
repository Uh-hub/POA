#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstances/PA_CharacterAnimInstance.h"
#include "PA_SoldierAnimInstance.generated.h"

class APA_Soldier;
UCLASS()
class POA_API UPA_SoldierAnimInstance : public UPA_CharacterAnimInstance
{
	GENERATED_BODY()
	
public:

	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;


protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	APA_Soldier* OwningSoldier;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;


	float IdleElapsedTime;
};
