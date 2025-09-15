#include "Character/POA_AnimInstance.h"
#include "Character/POA_Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPOA_AnimInstance::NativeInitializeAnimation()
{
	Super::NativePostEvaluateAnimation();

	POACharacter = Cast<APOA_Character>(TryGetPawnOwner());
}

void UPOA_AnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (POACharacter == nullptr)
	{
		POACharacter = Cast<APOA_Character>(TryGetPawnOwner());
	}
	if (POACharacter == nullptr) return;

	FVector Velocity = POACharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = POACharacter->GetCharacterMovement()->IsFalling();

	bIsAccelerating = POACharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
