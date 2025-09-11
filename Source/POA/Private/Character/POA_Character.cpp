#include "Character/POA_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APOA_Character::APOA_Character()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}


void APOA_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void APOA_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &APOA_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APOA_Character::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APOA_Character::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APOA_Character::LookUp);
	
}

void APOA_Character::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void APOA_Character::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

void APOA_Character::Turn(float Value)
{
	AddControllerYawInput(Value);
}
void APOA_Character::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}




void APOA_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




