#include "Characters/AnimInstances/PA_CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPA_CharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<APA_CharacterBase>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UPA_CharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{//애니메이션 업데이트 함수 
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}
	//현재 속도 저장
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	//가속 중인지?
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
