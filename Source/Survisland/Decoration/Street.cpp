


#include "Street.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AStreet::AStreet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(RootComponent);
	TangentLength = 900.0;
	EndTangentLength = 75.0;
}

void AStreet::SpawnEndMesh()
{
	if(EndMesh)
	{
		EndComponent = NewObject<UStaticMeshComponent>(this);
		EndComponent->RegisterComponent();
		EndComponent->SetStaticMesh(EndMesh);
		EndComponent->SetWorldTransform(Spline->GetTransformAtSplinePoint(Spline->GetNumberOfSplinePoints()-1, ESplineCoordinateSpace::World));
	}
}

void AStreet::SpawnEndActor()
{
	if(EndActor)
	{
		UWorld* World = GetWorld();
		FTransform PointTransform = Spline->GetTransformAtSplinePoint(Spline->GetNumberOfSplinePoints() - 1, ESplineCoordinateSpace::World);
		World->SpawnActor(EndActor, &PointTransform);
	}
}

void AStreet::UpdateMesh()
{
	if(MeshReference)
	{
		// Length of one UStaticMeshComponent
		float Spacing = MeshReference->GetBounds().BoxExtent.X * 2;

		float Remainder;
		int32 NumberOfMeshes = UKismetMathLibrary::FMod(Spline->GetNumberOfSplinePoints(), Spacing, Remainder);
		for(int i = 0; i <= NumberOfMeshes; i++)
		{
			USplineMeshComponent* NewSplineMesh = NewObject<USplineMeshComponent>();
			NewSplineMesh->SetStaticMesh(MeshReference);

			FVector StartPosition = Spline->GetLocationAtDistanceAlongSpline(i*Spacing, ESplineCoordinateSpace::Local);
			FVector EndPosition = Spline->GetLocationAtDistanceAlongSpline(i*Spacing+Spacing, ESplineCoordinateSpace::Local);
			FVector StartTangent;
			FVector EndTangent;
			if(NumberOfMeshes == i)
			{
				StartTangent = Spline->GetLocationAtDistanceAlongSpline(i*Spacing, ESplineCoordinateSpace::Local) * EndTangentLength;
				EndTangent = Spline->GetLocationAtDistanceAlongSpline(i*Spacing+Spacing, ESplineCoordinateSpace::Local) * EndTangentLength;
			}
			else
			{
				StartTangent = Spline->GetLocationAtDistanceAlongSpline(i*Spacing, ESplineCoordinateSpace::Local) * TangentLength;
				EndTangent = Spline->GetLocationAtDistanceAlongSpline(i*Spacing+Spacing, ESplineCoordinateSpace::Local) * TangentLength;
			}
			NewSplineMesh->SetStartAndEnd(StartPosition, StartTangent, EndPosition, EndTangent ,false);
			FVector2D StartScale = FVector2D(Spline->GetScaleAtDistanceAlongSpline(i*Spacing).X, Spline->GetScaleAtDistanceAlongSpline(i*Spacing).Y);
			NewSplineMesh->SetStartScale(StartScale, false);
			FVector2D EndScale = FVector2D(Spline->GetScaleAtDistanceAlongSpline(i*Spacing+Spacing).X, Spline->GetScaleAtDistanceAlongSpline(i*Spacing+Spacing).Y);
			NewSplineMesh->SetEndScale(EndScale, false);
			NewSplineMesh->UpdateMesh();
		}
	}
}