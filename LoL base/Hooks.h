#pragma once
#include <d3d9.h>
#include <D3dx9math.h>
#include "CObject.h"
#include "SpellSlot.h"

class Typedefs {
public:
	typedef void(__thiscall* tPrintChat)(DWORD ChatClient, const char* Message, int Color);
	typedef int*(__thiscall* fnIssueOrder)(void *thisPtr, int Order, Vector *Loc, CObject *Target, bool IsAttackMove, bool IsMinion, DWORD Unknown);
	typedef float(__cdecl* fnGetAttackCastDelay)(CObject* pObj);
	typedef float(__cdecl* fnGetAttackDelay)(CObject* pObj);
	typedef int* (__thiscall* fnCastSpell)(DWORD spellbook_addr, SpellSlot* spellslot, int SlotID, Vector* targetpos, Vector* startpos, DWORD NetworkID);
	typedef void(__thiscall* fnPrintChat)(DWORD ChatClient, const char* Message, int Color);

	typedef bool(__cdecl* fnIsHero)(CObject* pObj);
	typedef bool(__cdecl* fnIsMissile)(CObject* pObj);
	typedef bool(__cdecl* fnIsMinion)(CObject* pObj);
	typedef bool(__cdecl* fnIsTurret)(CObject* pObj);
	typedef bool(__cdecl* fnIsInhibitor)(CObject* pObj);
	typedef bool(__cdecl* fnIsTroyEnt)(CObject* pObj);
	typedef bool(__cdecl* fnIsNexus)(CObject* pObj);
	typedef float(__cdecl* fnGetAttackCastDelay)(CObject* pObj);
	typedef float(__cdecl* fnGetAttackDelay)(CObject* pObj);
	typedef bool(__thiscall* fnIsAlive)(CObject* pObj);
	typedef bool(__thiscall* fnIsTargetable)(CObject* pObj);
	typedef bool(__thiscall* fnGetPing)(CObject* pObj);

	typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
	typedef HRESULT(WINAPI* Prototype_Reset)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
};

class CFunctions {
public:
	LPDIRECT3DDEVICE9 pDevice;
	Typedefs::fnIsTurret IsTurret;
	Typedefs::fnIsMinion IsMinion;
	Typedefs::fnIsHero IsHero;
	Typedefs::fnIsMissile IsMissile;
	Typedefs::fnIsTroyEnt IsTroyEnt;
	Typedefs::fnIsNexus IsNexus;
	Typedefs::fnIsInhibitor IsInhibitor;
	Typedefs::fnIsTargetable IsTargetable;
	Typedefs::fnIsAlive IsAlive;

	Typedefs::fnGetPing GetPing;


	Typedefs::fnIssueOrder IssueOrder;
	Typedefs::fnGetAttackCastDelay GetAttackCastDelay;
	Typedefs::fnGetAttackDelay GetAttackDelay;
	Typedefs::fnCastSpell CastSpell;
	Typedefs::fnPrintChat PrintChat;

	Typedefs::Prototype_Reset Original_Reset;
	Typedefs::Prototype_Present Original_Present;

	bool WorldToScreen(LPDIRECT3DDEVICE9 pDevice, Vector* pos, Vector* out) {
		D3DXVECTOR3* PosConvert, * OutConvert;
		PosConvert->x = pos->X;
		PosConvert->y = pos->Y;
		PosConvert->z = pos->Z;
		D3DVIEWPORT9 viewPort;
		D3DXMATRIX view, projection, world;

		pDevice->GetViewport(&viewPort);
		pDevice->GetTransform(D3DTS_VIEW, &view);
		pDevice->GetTransform(D3DTS_PROJECTION, &projection);
		D3DXMatrixIdentity(&world);

		D3DXVec3Project(PosConvert, OutConvert, &viewPort, &projection, &view, &world);
		out->X = OutConvert->x;
		out->Y = OutConvert->y;
		out->Z = OutConvert->z;
		if (out->Z < 1) {
			return true;
		}
		return false;
	}
};

extern CFunctions Functions;