// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/ActivablesComponent.h"

#include "TP2/AltarBase.h"


// Sets default values for this component's properties
UActivablesComponent::UActivablesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	TiempoActivacionAuxiliar = TiempoActivacion;
}


// Called when the game starts
void UActivablesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivablesComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}





void UActivablesComponent::IniciarActivacion()
{
	if (!bSeEstaActivando && !bEstaActivado)
	{
		bSeEstaActivando = true;
		
		GetWorld()->GetTimerManager().SetTimer(
		ActivableTimerHandle,
		this,
		&UActivablesComponent::Activar,
		TiempoIntervaloActivacion,
		true
		);
	}
}

void UActivablesComponent::Activar()
{
	TiempoActivacionAuxiliar -= TiempoIntervaloActivacion;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("TiempoActivacion: %.2f"), TiempoActivacionAuxiliar));
	if (TiempoActivacionAuxiliar <= 0)
	{		
		FinalizarActivacion();
	}

}

void UActivablesComponent::FinalizarActivacion()
{
	bEstaActivado = true;
	bSeEstaActivando = false;	
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Altar Activado"));
	GetWorld()->GetTimerManager().ClearTimer(ActivableTimerHandle);
		
	
	
	OnAltarActivated.Broadcast();
	
	if (AAltarBase* Altar = Cast<AAltarBase>(GetOwner()))
	{
		Altar->AlFinalizarActivacion();
	}else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("No se pudo castear"));
	}
	
	
}

void UActivablesComponent::ResetActivacion()
{
	if (!bEstaActivado)
	{		
		bEstaActivado = false;
		bSeEstaActivando = false;	
		
		GetWorld()->GetTimerManager().ClearTimer(ActivableTimerHandle);
		TiempoActivacionAuxiliar = TiempoActivacion;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ACTIVACION CANCELADA"));
	}
}

