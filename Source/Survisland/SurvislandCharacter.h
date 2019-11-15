// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SurvislandCharacter.generated.h"

class UInventoryComponent;

UCLASS(config=Game)
class ASurvislandCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ASurvislandCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY()
	class UInventoryComponent* Inventory;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


protected:

	UPROPERTY(BlueprintReadOnly)
	float Health;

	UPROPERTY(BlueprintReadOnly)
	float HealthMultiply;

public:

	/**
	 * Changes the health level
	 * Input will be clamped
	 * @param delta Absolute change from -100 to 100
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
	void ChangeHealth(float delta);

	/**
	 * Changes the health multiplier
	 * Input will be clamped
	 * @param delta Absolute change
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats|Health")
	void ChangeMultiplier(float delta);

protected:

	UPROPERTY(BlueprintReadOnly)
	float Water;

public:

	/**
	 * Changes the water level
	 * Input will be clamped
	 * @param delta Absolute change from -100 to 100
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ChangeWater(float delta);

protected:

	UPROPERTY(BlueprintReadOnly)
	float Food;

public:

	/**
	 * Changes the food level
	 * Input will be clamped
	 * @param delta Absolute change (-100 to 100)
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ChangeFood(float delta);

protected:

	void UpdateStats();

};