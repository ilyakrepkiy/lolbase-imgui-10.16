#include "CObject.h"
#include "Hooks.h"
#include "Engine.h"

bool CObject::IsAlive() {
	return Functions.IsAlive(this) && this->GetHealth() > 0.0f;
}

bool CObject::IsMinion() {
	return this->CompareObjectTypeFlags(ObjectTypeFlags::Minion);
}

float CObject::GetDistanceToMe() {
	return this->GetPos().DistTo(Engine::GetLocalObject()->GetPos());
}

bool CObject::IsTurret() {
	return this->CompareObjectTypeFlags(ObjectTypeFlags::Turret);
}

bool CObject::IsHero() {
	return CompareObjectTypeFlags(ObjectTypeFlags::Hero);
}

bool CObject::IsMissile() {
	return this->CompareObjectTypeFlags(ObjectTypeFlags::Missile);
}

bool CObject::IsTargetable() {
	return this->CompareObjectTypeFlags(ObjectTypeFlags::AttackableUnit);
}

float CObject::GetAttackDelay()
{
	return Functions.GetAttackDelay(this);
}

float CObject::GetAttackCastDelay()
{
	return Functions.GetAttackCastDelay(this);
}

bool CObject::IsNexus() {
	return Functions.IsNexus(this);
}

bool CObject::IsInhibitor() {
	return Functions.IsInhibitor(this);
}

bool CObject::IsTroyEnt() {
	return Functions.IsTroyEnt(this);
}
