#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/PA_DataAsset_InputConfig.h"
#include "PA_InputComponent.generated.h"

UCLASS()
class POA_API UPA_InputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UPA_DataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObejct, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void UPA_InputComponent::BindNativeInputAction(const UPA_DataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObejct, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("InputConfig data asset is null, can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{//해당 태그에 대해 FoundAction이 존재하면 Bind 
		BindAction(FoundAction, TriggerEvent, ContextObejct, Func);
	}
}
