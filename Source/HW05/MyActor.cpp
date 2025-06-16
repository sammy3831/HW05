// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StartLocation = {0.0, 0.0, 0.0 };
	CurrentLocation = StartLocation;
	EventCount = 0;
	TotalDistance = 0.0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 10; i++)
	{
		FVector BeforeLocation = CurrentLocation;
		
		Move();
		
		UE_LOG(LogTemp, Warning, TEXT("CurrentLocation: %f, %f, %f"), CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z);
		UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance(BeforeLocation, CurrentLocation));

		CreateEvent(50);
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------"));
		
	}
	
	TotalDistance = Distance(StartLocation, CurrentLocation);
	
	UE_LOG(LogTemp, Warning, TEXT("TotalDistance: %f"), TotalDistance);
	UE_LOG(LogTemp, Warning, TEXT("TotalEventCount: %d"), EventCount);
	UE_LOG(LogTemp, Warning, TEXT("---------------------------------------"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move()
{
	CurrentLocation.X += static_cast<double>(Step());
	CurrentLocation.Y += static_cast<double>(Step());
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0,1);
}

float AMyActor::Distance(const FVector& first, const FVector& second)
{
	float x = first.X - second.X;
	float y = first.Y - second.Y;
	return FMath::Sqrt(x*x + y*y);
}

void AMyActor::CreateEvent(int32 Probability)
{
	if (FMath::RandRange(1, 100) <= Probability)
	{
		EventCount++;
		UE_LOG(LogTemp, Warning, TEXT("Event created"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Event not created"));
	}
}

