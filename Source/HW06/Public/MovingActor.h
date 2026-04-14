#pragma once
//A(Actor 계열), U(Object 계열), F(구조체), T(템플릿), E(열거형)

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Variable")
	float MoveSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Variable")
	float MaxRange = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor|Variable")
	FVector StartLocation = FVector::ZeroVector;

public:	
	virtual void Tick(float DeltaTime) override;

};
