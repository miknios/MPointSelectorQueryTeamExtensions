// Copyright (c) Miknios. All rights reserved.


#include "MPointSelectorQueryFilter_TeamAffiliation.h"

#include "Team/MTeamLibrary.h"

bool UMPointSelectorQueryFilter_TeamAffiliation::FilterPoint_Impl_Implementation(
	const UObject* ContextObject,
	const FVector& ReferenceLocation,
	const FVector& ReferenceDirection,
	const UMPointSelectorQuerySettingsAsset* QuerySettings,
	const TScriptInterface<IMSelectorQueryPointInterface>& LookAtPoint) const
{
	const AActor* LookAtPointActorOwner;
	if (const UActorComponent* LookAtPointComponent = Cast<UActorComponent>(LookAtPoint.GetObject()))
	{
		LookAtPointActorOwner = LookAtPointComponent->GetOwner();
	}
	else
	{
		LookAtPointActorOwner = Cast<AActor>(LookAtPoint.GetObject());
	}

	if (LookAtPointActorOwner == nullptr)
	{
		return false;
	}

	const AActor* ContextActor;
	if (const UActorComponent* ContextComponent = Cast<UActorComponent>(ContextObject))
	{
		ContextActor = ContextComponent->GetOwner();
	}
	else
	{
		ContextActor = Cast<AActor>(ContextObject);
	}

	if (ContextActor == nullptr)
	{
		return false;
	}

	const bool FilterResult = UMTeamLibrary::EvaluateAffiliationFilterForActors(TeamAffiliationFilter, LookAtPointActorOwner, ContextActor);
	return FilterResult;
}
