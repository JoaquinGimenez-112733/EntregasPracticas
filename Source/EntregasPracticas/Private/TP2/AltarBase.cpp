// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/AltarBase.h"

#include "Components/SphereComponent.h"
#include "TP2/ActivablesComponent.h"


// Sets default values
AAltarBase::AAltarBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	ActivablesComponent = CreateDefaultSubobject<UActivablesComponent>(TEXT("ActivablesComponent"));
	
	
}

void AAltarBase::AlFinalizarActivacion()
{
	PintarAltar();
}

void AAltarBase::PintarAltar()
{
	if (MaterialDinamicoAltar)
	{
	MaterialDinamicoAltar->SetVectorParameterValue(TEXT("EmissiveFactor"), FLinearColor::Green);		
	}
}



// Called when the game starts or when spawned
void AAltarBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (Mesh)
	{
		MaterialDinamicoAltar = Mesh->CreateDynamicMaterialInstance(0);
	}else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("No tiene mesh"));
	}
	
}

// Called every frame
void AAltarBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAltarBase::Interact_Implementation(AActor* Actor)
{
	if (IsValid(ActivablesComponent))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Actor->GetActorNameOrLabel());
		ActivablesComponent->IniciarActivacion();
	}
}

void AAltarBase::BreakInteract_Implementation(AActor* Actor)
{
	if (IsValid(ActivablesComponent))
	{
		
		ActivablesComponent->ResetActivacion();
	}
}

