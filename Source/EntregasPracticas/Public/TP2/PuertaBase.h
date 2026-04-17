// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuertaBase.generated.h"

class UStaticMeshComponent;
class USceneComponent;
UCLASS()
class ENTREGASPRACTICAS_API APuertaBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuertaBase();
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>Marco;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Hoja;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAbierta;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AltaresTotales;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AltaresActivados;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float IntervaloRotacionHoja = 0.1f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaximoRotacion = 85.f;
	
	UFUNCTION(BlueprintCallable)
	void NotifyAltarActivado();
	
	UFUNCTION(BlueprintCallable)
	void AbrirPuerta();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTimerHandle PuertaHandle;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
