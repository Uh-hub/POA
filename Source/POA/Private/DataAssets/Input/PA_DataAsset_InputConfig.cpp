#include "DataAssets/Input/PA_DataAsset_InputConfig.h"

UInputAction* UPA_DataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{//NativeInputActions 안에 저장된 InputActionConfig의 InputTag가 매개변수로 전달된 InInputTag와 같고
		 //그와 연결된 InputAction이 유효할 때 InputActionConfig.InputAction을 반환함
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
