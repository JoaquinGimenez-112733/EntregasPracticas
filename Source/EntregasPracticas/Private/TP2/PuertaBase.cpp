// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/PuertaBase.h"

#include "Kismet/GameplayStatics.h"
#include "TP2/ActivablesComponent.h"
#include "TP2/AltarBase.h"


// Sets default values
APuertaBase::APuertaBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Hoja = CreateDefaultSubobject<UStaticMeshComponent>("Hoja");
	Marco = CreateDefaultSubobject<UStaticMeshComponent>("Marco");
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	
	SetRootComponent(Root);
	
	Hoja->SetupAttachment(Root);
	Marco->SetupAttachment(Root);

}

void APuertaBase::NotifyAltarActivado()
{
	AltaresActivados++;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("ALTAR ACTIVADO"));
	if (AltaresActivados >= AltaresTotales && !GetWorldTimerManager().IsTimerActive(PuertaHandle))
	{
		GetWorldTimerManager().SetTimer(PuertaHandle, this,&APuertaBase::AbrirPuerta, IntervaloRotacionHoja / 5, true);
	}
}

void APuertaBase::AbrirPuerta()
{
	//algo
	
	if (!bAbierta)
	{		
		FRotator Rotator = Hoja->GetRelativeRotation();
		float nuevaYaw = Rotator.Yaw - 1.0f;
		nuevaYaw = FMath::Min(nuevaYaw, MaximoRotacion);
		
		Hoja->SetRelativeRotation(FRotator(Rotator.Pitch, nuevaYaw, Rotator.Roll));
		
		if (nuevaYaw <= -MaximoRotacion)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("TODOS LOS ALTARES ACTIVADOS"));
			bAbierta = true;
			GetWorldTimerManager().ClearTimer(PuertaHandle);
		}
	}
}

// Called when the game starts or when spawned
void APuertaBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> Altares;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AAltarBase::StaticClass(), Altares);

	for (AActor* Actor : Altares)
		
	{
		AAltarBase* Altar = Cast<AAltarBase>(Actor);
		if (!Altar) continue;
		
		if (UActivablesComponent* ActivablesComponent = Altar->FindComponentByClass<UActivablesComponent>())
		{
			ActivablesComponent->OnAltarActivated.AddDynamic(this, &APuertaBase::NotifyAltarActivado);
			AltaresTotales++;
		};
	}
	
	if (AltaresActivados == AltaresTotales)
	{
		GetWorldTimerManager().SetTimer(PuertaHandle, this,&APuertaBase::AbrirPuerta, IntervaloRotacionHoja, true);
	}
	
}

// Called every frame
void APuertaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

