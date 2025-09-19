#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstances/PA_AnimInstanceBase.h"
#include "Characters/PA_CharacterBase.h"
#include "PA_CharacterAnimInstance.generated.h"

class APA_CharacterBase;
class UCharacterMovementComponent;

UCLASS()
class POA_API UPA_CharacterAnimInstance : public UPA_AnimInstanceBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	APA_CharacterBase* OwningCharacter;
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
