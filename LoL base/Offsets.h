#pragma once
#define TARGET_GAMEVERSION "Version 11.1.351.8352 [PUBLIC]"
 
#define oRetAddr 0x41D6
#define oObjManager 0x1C52490
#define oHudInstance 0x1C524D0
#define oLocalPlayer 0x34EEDE4
#define oGameTime 0x34E6FD4

// FUNCTIONS
#define oGetNextObject 0x290480
#define oGetFirstObject 0x290480
#define oIssueOrder 0x176590
#define oIsTargetable 0x1D9380
#define oIsAlive 0x1A1BF0
#define oIsMinion 0x1B0CB0
#define oIsTurret 0x1B0EE0
#define oIsHero 0x1B0C70
#define oIsMissile 0x1B0CD0
#define oIsNexus 0x1B0BF0
#define oIsInhib 0x1B0AF0
#define oIsTroy 0x1B0B70
#define oWorldToScreen 0x961840
#define oGetAttackCastDelay 0x2A4920
#define oGetAttackDelay 0x2A4A20
 
//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC
#define oObjPos 0x1D8
#define oObjVisibility 0x270
#define oObjHealth 0xD98
#define oObjArmor 0x1298
#define oObjBaseAtk 0x1270
#define oObjBonusAtk 0x11F0
#define oObjAtkRange 0x12B8
#define oObjSpellBook 0x2708
#define oObjChampionName 0x3134
#define oObjLevel 0x36BC

//ObjectManager
#define objectArray 0x14
 
//MissileInfo
#define oMissileSpellInfo 0x230
#define oMissileSourceIndex 0x290
#define oMissileStartPos 0x2A8
#define oMissileEndPos 0x2B4