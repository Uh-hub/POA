#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "POA_Character.generated.h"

UCLASS()
class POA_API APOA_Character : public ACharacter
{
	GENERATED_BODY()

public:
	APOA_Character();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
private:
	UPROPERTY(VisibleAnywhere, Category= Camera)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;


public:	


};
