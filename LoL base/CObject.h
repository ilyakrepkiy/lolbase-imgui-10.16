#pragma once
#include <Windows.h>
#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"
#include "CSpellBook.h"

enum class ObjectTypeFlags : int {
	GameObject = (1 << 0),  //0x1
	NeutralCamp = (1 << 1),  //0x2
	DeadObject = (1 << 4),  //0x10
	InvalidObject = (1 << 5),  //0x20
	AIBaseCommon = (1 << 7),  //0x80
	AttackableUnit = (1 << 9),  //0x200
	AI = (1 << 10), //0x400
	Minion = (1 << 11), //0x800
	Hero = (1 << 12), //0x1000
	Turret = (1 << 13), //0x2000
	Unknown0 = (1 << 14), //0x4000
	Missile = (1 << 15), //0x8000
	Unknown1 = (1 << 16), //0x10000
	Building = (1 << 17), //0x20000
	Unknown2 = (1 << 18), //0x40000
};

class CObject {
public:
	float CObject::GetEffectiveDamageOnTarget(CObject* target) {
		return this->GetTotalAttackDamage() * (100 / (100 + target->GetArmor()));
	}
	bool CObject::IsInvalidObject() {
		return CompareObjectTypeFlags(ObjectTypeFlags::InvalidObject);
	}
	float CObject::GetDistanceToMe();
	bool IsTurret();
	bool IsMinion();
	bool IsAlive();
	bool IsHero();
	bool IsMissile();
	bool IsNexus();

	bool IsInhibitor();
	bool IsTroyEnt();

	bool IsTargetable();
	bool CObject::CompareObjectTypeFlags(ObjectTypeFlags objectTypeFlag)
	{
		unsigned __int8* v2; // edi
		unsigned int v3; // edx
		unsigned int v4; // esi
		int* v5; // ecx
		int v6; // eax
		unsigned __int8 v7; // al
		unsigned int v8; // eax
		unsigned __int8* v9; // edx
		char v10; // cl
		int objectId; // [esp+8h] [ebp-4h]

		v2 = (unsigned __int8*)this;
		v3 = 0;
		v4 = *(BYTE*)(v2 + 81);

		objectId = *(DWORD*)&v2[4 * v2[88] + 92];
		if (v4)
		{
			v5 = (int*)(this + 84);
			do
			{
				v6 = *v5;
				++v5;
				*(&objectId + v3) ^= ~v6;
				++v3;
			} while (v3 < v4);
		}
		v7 = v2[82];
		if (v7)
		{
			v8 = 4 - v7;
			if (v8 < 4)
			{
				v9 = &v2[v8 + 84];
				do
				{
					v10 = *v9++;
					*((BYTE*)&objectId + v8++) ^= ~v10;
				} while (v8 < 4);
			}
		}

		return (objectId & (int)objectTypeFlag) != 0;
	}
	CObject* GetFirstObject()
	{
		typedef CObject* (__thiscall* fnGetFirst)(void*);
		return ((fnGetFirst)(baseAddr + oGetFirstObject))(*(void**)(baseAddr + oObjManager));
	}
	CObject* GetNextObject(CObject* object)
	{
		typedef CObject* (__thiscall* fnGetNext)(void*, CObject*);
		return ((fnGetNext)(baseAddr + oGetNextObject))(*(void**)(baseAddr + oObjManager), object);
	}

	short GetIndex() {
		return *(short*)((DWORD)this + oObjIndex);
	}

	DWORD GetNetworkID() {
		return *(DWORD*)((DWORD)this + oObjNetworkID);
	}

	Vector GetPos() {
		return *(Vector*)((DWORD)this + oObjPos);
	}

	int GetLevel() {
		return *(int*)((DWORD)this + oObjLevel);
	}

	float GetHealth() {
		return *(float*)((DWORD)this + oObjHealth);
	}

	float GetBaseAttackDamage() {
		return *(float*)((DWORD)this + oObjBaseAtk);
	}


	float GetBonusAttackDamage() {
		return *(float*)((DWORD)this + oObjBonusAtk);
	}

	float GetTotalAttackDamage() {
		return this->GetBonusAttackDamage() + this->GetBaseAttackDamage();
	}

	float GetArmor() {
		return *(float*)((DWORD)this + oObjArmor);
	}

	float GetMaxHealth() {
		return *(float*)((DWORD)this + oObjHealth + 0x10);
	}

	float GetAttackRange() {
		return *(float*)((DWORD)this + oObjAtkRange);
	}

	bool IsVisible() {
		return *(bool*)((DWORD)this + oObjVisibility);
	}

	float GetBoundingRadius() {
		typedef float(__thiscall* OriginalFn)(PVOID);
		return CallVirtual<OriginalFn>(this, 36)(this);
	}

	bool IsEnemyTo(CObject* Obj) {
		if (Obj->GetTeam() == 100 && this->GetTeam() == 200)
			return true;

		else if (Obj->GetTeam() == 200 && this->GetTeam() == 100)
			return true;

		return false;
	}

	bool Isjungle() {

		if (this->GetTeam() == 300)
			return true;
		return false;
	}

	bool Isjungle(CObject* Obj) {

		if (Obj->GetTeam() == 300)
			return true;
		return false;
	}



	char* GetName() {
		return GetStr((DWORD)this + oObjName);
	}

	char* GetChampionName() {
		return GetStr((DWORD)this + oObjChampionName);
	}

	int GetTeam() {
		return *(int*)((DWORD)this + oObjTeam);
	}
	
	CSpellBook * GetSpellBook () {  
		return (CSpellBook*) (( DWORD ) this + oObjSpellBook );  
	}


	float GetAttackDelay();

	float GetAttackCastDelay();
	float GetDistance(CObject* target, CObject* target2);
};
