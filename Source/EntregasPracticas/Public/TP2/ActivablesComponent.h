// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivablesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAltarActivated);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ENTREGASPRACTICAS_API UActivablesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UActivablesComponent();
	UFUNCTION(BlueprintCallable, Category = "Activables")
	void IniciarActivacion();
	UFUNCTION(BlueprintCallable, Category = "Activables")
	void ResetActivacion();
	
	UPROPERTY(BlueprintAssignable)
	FOnAltarActivated OnAltarActivated;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activable", meta = (AllowPrivateAccess = true))
	bool bEstaActivado = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activable", meta = (AllowPrivateAccess = true))
	bool bSeEstaActivando = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activable", meta = (AllowPrivateAccess = true))
	float TiempoActivacion = 2.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activable", meta = (AllowPrivateAccess = true))
	float TiempoActivacionAuxiliar;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activable", meta = (AllowPrivateAccess = true))
	float TiempoIntervaloActivacion = 0.1f;
	
	UFUNCTION(BlueprintCallable, Category = "Activables")
	void Activar();
	
	UFUNCTION(BlueprintCallable, Category = "Activables")
	void FinalizarActivacion();
	

	

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activables", meta = (AllowPrivateAccess = true))
	FTimerHandle ActivableTimerHandle;
};
