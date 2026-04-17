// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TPN1/ItemLlave.h"

// Sets default values
AItemLlave::AItemLlave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	
	DesactivarLlave();

}

void AItemLlave::ActivarLlave()
{
	if (bActivo) return;
	bActivo = true;
	
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
}

void AItemLlave::DesactivarLlave()
{
	
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
	
}

// Called when the game starts or when spawned
void AItemLlave::BeginPlay()
{
	Super::BeginPlay();
	DesactivarLlave();
	
}



