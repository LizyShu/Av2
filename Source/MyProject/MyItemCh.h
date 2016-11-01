// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemCh.h"
#include "MyItemCh.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyItemCh : public AItemCh
{
	GENERATED_BODY()
	
public:
	AMyItemCh();	

	virtual int Use() override;
	
};
