// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "AltarBase.generated.h"


class USphereComponent;
class UStaticMeshComponent;
class UActivablesComponent;
class UMaterialInstanceDynamic;



UCLASS()
class ENTREGASPRACTICAS_API AAltarBase : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAltarBase();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation(AActor* Actor) override;
	virtual void BreakInteract_Implementation(AActor* Actor) override;
	
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MaterialDinamicoAltar;
	
	UFUNCTION()
	void PintarAltar();
	
	UFUNCTION()
	void AlFinalizarActivacion();
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Component", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent>  SphereCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Component", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent>  Mesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<UActivablesComponent>  ActivablesComponent;
};
