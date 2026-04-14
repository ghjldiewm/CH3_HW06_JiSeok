#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorLocalOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
		//UE_LOG(LogTemp, Warning, TEXT("%s +Y"), *GetName());

		if (GetActorLocation().Y >= StartLocation.Y + MaxRange)
		{
			MoveSpeed = -MoveSpeed;
			//UE_LOG(LogTemp, Warning, TEXT("%s -Y"), *GetName());
		}
		else if (GetActorLocation().Y <= StartLocation.Y)
		{
			MoveSpeed = FMath::Abs(MoveSpeed);
		}

	}

}