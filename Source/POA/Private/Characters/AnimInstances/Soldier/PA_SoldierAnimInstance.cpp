#include "Characters/AnimInstances/Soldier/PA_SoldierAnimInstance.h"
#include "Characters/PA_Soldier.h"

void UPA_SoldierAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningSoldier = Cast<APA_Soldier>(OwningCharacter);
	}
}

void UPA_SoldierAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration)
	{//움직이는 중이라면,
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold) ? true : false;
	}
}
