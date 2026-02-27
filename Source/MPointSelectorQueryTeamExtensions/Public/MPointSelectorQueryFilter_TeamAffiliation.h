// Copyright (c) Miknios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "MPointSelectorQueryFilter.h"
#include "MPointSelectorQueryLibrary.h"
#include "Team/MTeamTypes.h"
#include "MPointSelectorQueryFilter_TeamAffiliation.generated.h"

UCLASS(DisplayName = "Team Affiliation")
class UMPointSelectorQueryFilter_TeamAffiliation : public UMPointSelectorQueryFilter_Base
{
	GENERATED_BODY()

public:
	// UMPointSelectorQueryFilter_Base
	virtual bool FilterPoint_Impl_Implementation(const UObject* ContextObject,
	                                             const FVector& ReferenceLocation,
	                                             const FVector& ReferenceDirection,
	                                             const UMPointSelectorQuerySettingsAsset* QuerySettings,
	                                             const TScriptInterface<IMSelectorQueryPointInterface>& LookAtPoint) const override;
	// ~ UMPointSelectorQueryFilter_Base

protected:
	UPROPERTY(EditAnywhere, Category = "Filter")
	FMTeamAffiliationFilter TeamAffiliationFilter;
};
