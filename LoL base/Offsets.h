#pragma once
#define TARGET_GAMEVERSION "Version 10.23.343.2792 [PUBLIC]" //

#define oRetAddr 0x6E502 // // find addr : ret // opcode : C3
#define oDrawCircleRetAddr 0x6E4FF // // find addr : add esp, 28 ret // opcode : 83 C4 1C C3
#define oNetClient 0x351446C // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset] // this addy us for IsTargetable as per chinese tool but nah~
#define oPingInstance 0x351446C // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset]
#define oChatClientPtr 0x1C6E030 // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 // dword_[offset] // 8B ?? ?? ?? ?? ?? 6A ?? 50 E8 ?? ?? ?? ?? 33 C0 5F C2 // dword_[offset]
#define oObjManager 0x1C706B0 // 8B 0D ? ? ? ? 89 74 24 14 // dword_[offset]
#define oZoomClass 0x3504AFC // A3 ? ? ? ? 83 FA 10 72 32 // dword_[offset]
#define oGameInfo 0x35064AC // A1 ? ? ? ? 83 78 08 02 0F 94 C0 // dword_[offset]
#define oHudInstance 0x1C706E8 // 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0 // dword_[offset]
#define oRenderer 0x3535C3C // 8B 15 ? ? ? ? 83 EC 08 F3 // dword_[offset]
#define oUnderMouseObject 0x1C100F0 // 8B 0D ? ? ? ? 89 0D // dword_[offset] //
#define oD3DRenderer 0x35389E0 // A1 ? ? ? ? 89 54 24 18 // dword_[offset]
#define oLocalPlayer 0x350D168 // A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56 // dword_[offset]
#define oGameTime 0x3505318 // F3 0F 11 05 ? ? ? ? 8B 49 // dword_[offset]
#define oMenuGUI 0x350CC38 // 8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7 // dword_[offset]

// FUNCTIONS
#define oOnprocessSpell 0x50B730 // E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 80 BE ?? ?? ?? ?? ?? D8 // sub_[offset]
#define oGetNextObject 0x28BB30 // E8 ? ? ? ? 8B F0 85 F6 75 E4 // sub_[offset]
#define oGameVersion 0x55C300 // E8 ? ? ? ? 50 FF 36 8D 84 // sub_[offset]
#define oGetFirstObject 0x28A910 // E8 ? ? ? ? 8B F8 85 FF 0F 84 ? ? ? ? 53 8B 5C // sub_[offset]
#define oWorldToScreen 0x97BE80 // 83 EC 10 56 E8 ? ? ? ? 8B 08 // fn
#define oCastSpell 0x509AA0 // xref: ERROR: Client Tried to cast a spell from an invalid slot: %d.\n
#define oDrawCircle 0x519D70 // E8 ? ? ? ? 83 C4 1C 80 7F // sub_[offset]
#define oGetBasicAttack 0x1681E0 // 53 8B D9 B8 ? ? ? ? 8B 93 // fn
#define oGetAttackCastDelay 0x2A0EE0 // 83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90 // fn // E8 ?? ?? ?? ?? D9 ?? ?? ?? ?? ?? 56 E8 // sub_[offset]
#define oGetAttackDelay 0x2A0FE0 // E8 ? ? ? ? 8B 44 24 1C 83 C4 0C 8B CE // sub_[offset] // this addy is for oGetPing as per chinese tool but nah~
#define oGetPing 0x332FF0 // E8 ? ? ? ? 8B 4F 2C 85 C9 0F // sub_[offset]
#define oGetSpellState 0x4FB1F0 // E8 ? ? ? ? 8B F8 8B CB 89 // sub_[offset] // this addy us for IsTargetable as per chinese tool but nah~
#define oIsTargetable 0x1D6300 // 56 8B F1 E8 ? ? ? ? 84 C0 74 2E // fn
#define oIsAlive 0x19F580 // 56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19 // fn
#define oIsBaron 0x175320 // E8 ? ? ? ? 84 C0 74 0A BB // sub_[offset]
#define oIsTurret 0x1AE030 // E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F // sub_[offset]
#define oIsInhib 0x1ADC40 // E8 ? ? ? ? 83 C4 04 84 C0 74 38 // sub_[offset]
#define oIsHero 0x1ADDC0 // E8 ? ? ? ? 83 C4 04 84 C0 74 2B 57 // sub_[offset]
#define oIsMinion 0x1ADE00 // E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F // sub_[offset]
#define oIsDragon 0x173470 // E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9 // sub_[offset]
#define oIsMissile 0x1ADE20 // E8 ?? ?? ?? ?? 83 C4 04 84 C0 74 60 // sub_[offset]
#define oIsNexus 0x1ADD40 // E8 ? ? ? ? 83 C4 04 84 C0 0F 95 C0 C3 CC 8A // sub_[offset]
#define oIsNotWall 0x8F8AB0 // E8 ? ? ? ? 33 C9 83 C4 0C 84 // sub_[offset]
#define oIsTroy 0x1ADCC0 // E8 ? ? ? ? 8B E8 83 C4 04 85 ED 0F 84 ? ? ? ? 6A 08 // go to sub_XXX then sub_[offset]
#define oIssueOrder 0x1753D0 // 81 EC ? ? ? ? 56 57 8B F9 C7 // fn // E8 ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 8B 84 ?? ?? ?? ?? ?? 8B CF F3 0F 7E 00 // sub_[offset]
#define oPrintChat 0x5A5730 // E8 ? ? ? ? 33 C0 5F C2 // sub_[offset]
#define oSendChat 0x5EF540 // A1 ? ? ? ? 56 6A FF // fn
#define oGetTimerExpiry 0x12DB30 // E8 ? ? ? ? 51 D9 1C 24 E8 ? ? ? ? 8B // sub_[offset]
#define oHealthBarPosition 0x58F550 // E8 ?? ?? ?? ?? 8B 4E ?? 8D 54 ?? ?? 52 8B 01 FF ?? ?? 5E 83 ?? ?? C3 // sub_[offset]
#define oBaseDrawPosition 0x16A480 // E8 ?? ?? ?? ?? EB ?? 8B 01 8B 40 // sub_[offset]

//functions - skinChanger
#define translateString_UNSAFE_DONOTUSE 0xAADEE0 // E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 04 8B F0 6A 0B // sub_[offset] // 83 EC 0C 56 8B 74 24 14 56 E8 ? ? ? ? 83 C4 04 89 74 24 04 89 44 24 08 A8 01 // fn
#define CharacterDataStack__Push 0x114110 // E8 ? ? ? ? 8D 4C 24 10 E8 ? ? ? ? 8B 44 24 44 // fn // 10.22 -> 13 Params, 10.23 -> 14 Params
#define CharacterDataStack__Update 0x10A680 // 83 EC 18 53 56 57 8D 44 24 20 // fn
#define GetOwnerObject 0x169F00 // E8 ? ? ? ? 39 44 24 1C 5F // sub_[offset]
#define CharacterData__GetCharacterPackage 0x237070 // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 56 8B B4 24 ? ? ? ? 8B C6 // fn // E8 ? ? ? ? 8B 54 24 30 83 C4 08 89 44 24 10 // sub_[offset]
#define GetAiManager 0x16CA90 // E8 ?? ?? ?? ?? 50 8B CE E8 ?? ?? ?? ?? 80 BB ?? ?? ?? ?? ?? // sub_[offset]
#define SetBaseCharacterData 0x199DB0 // E8 ?? ?? ?? ?? 8B 54 ?? ?? 83 ?? ?? 72 ?? 8B 4C ?? ?? 42 8B C1 81 ?? ?? ?? ?? ?? 72 ?? 8B 49 ?? 83 ?? ?? 2B C1 83 ?? ?? 83 ?? ?? 0F ?? ?? ?? ?? ?? 52 51 E8 ?? ?? ?? ?? 83 ?? ?? 8B 06 8B CE FF ?? ?? ?? ?? ?? 8B CE F3 0F // sub_[offset]
#define IsLaneMinion 0x37C0 // 8A 87 ? ? ? ? 88 4C 24 0F 33 C9 0F B6 D0 84 C0 74 12 // edi+[offset]h - 1

// ai_base - skinChanger
#define CharacterDataStack 0x2F78 // 8D 8E ? ? ? ? FF 74 24 5C // esi+[offset]h
#define SkinId 0xED4 // 80 BE ? ? ? ? ? 75 50 0F 31 33 C9 66 C7 86 ? ? ? ? ? ? 89 44 24 18 // esi+[offset]h

//global - skinChanger
#define ChampionManager 0x3506498 // 89 1D ? ? ? ? 56 8D 4B 04 // 8B 0D ? ? ? ? 83 C1 0C 89 14 24 // 8B 0D ? ? ? ? 57 FF 74 24 08 E8 ? ? ? ? 8B F8 // dword_[offset]
#define ManagerTemplate_AIMinionClient_ 0x28BCCB8 // A1 ? ? ? ? 53 55 8B 6C 24 1C // A1 ? ? ? ? F3 0F 10 40 ? F3 0F 11 44 24 // dword_[offset]
#define ManagerTemplate_AIHero_ 0x1C6E60C // 8B 0D ? ? ? ? 50 8D 44 24 18 // 8B 35 ? ? ? ? C7 44 24 ? ? ? ? ? C7 44 24 ? ? ? ? ? E8 // dword_[offset]

//events
#define OnCreateObject 0x291FF0 // E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 84 C0 74 ?? 32 C9 EB // sub_[offset]
#define OnDeleteObject 0x11D64D5 // E8 ?? ?? ?? ?? 57 E8 ?? ?? ?? ?? 83 ?? ?? 5F 5E C3 // sub_[offset]

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC //
#define oObjPos 0x220
#define oObjVisibility 0x270
#define oObjHealth 0xDC4
#define oObjMana 0x298
#define oObjMaxMana 0x2A8
#define oObjArmor 0x12B0
#define oObjMagicRes 0x12B8
#define oObjBonusMagicRes 0x12BC
#define oObjBaseAtk 0x1288
#define oObjBonusAtk 0x1208
#define oObjMoveSpeed 0x12C8
#define oObjAtkRange 0x12D0
#define oObjBuffMgr 0x2174
#define oObjSpellBook 0x2720
#define oObjChampionName 0x314C
#define oObjLevel 0x36BC
#define oObjSourceIndex 0x290
#define oObjPerk1 0x3880 // 8D 8E ? ? ? ? E8 ? ? ? ? 8B CE E8 ? ? ? ? A1 // esi+[offset]h // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 8B 9C 24 ? ? ? ? 56 8B F1 88 5C 24 0C // fn + 19F
#define oObjPerk2 0x2C8 // 8D 8B ? ? ? ? E8 ? ? ? ? 5F 5E 8D // ebx+[offset]h // E8 ? ? ? ? 8D B3 ? ? ? ? C7 83 ? ? ? ? ? ? ? ? C7 83 ? ? ? ? ? ? ? ? 8B CE // sub_XXX + 44

//ObjectManager
#define objectArray 0x14

//MissileInfo
#define oMissileSpellInfo 0x230
#define oMissileTargetIndex 0x2E8
#define oMissileStartPos 0x2A8
#define oMissileEndPos 0x2B4


//Buff
#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
#define O_BUFFMGR_flBUFFCOUNT 0x130
#define O_BUFFMGR_iBUFFCOUNT 0x74
#define oBuffType 0x4
#define oBuffCountAlt 0x24
#define oBuffCountAlt2 0x20

//Zoom
#define oMaxZoom 0x28

//oSpellSlot
#define oSpellSlotRemainingCharge 0x58
#define oSpellSlotLevel 0x20
#define oSpellSlotRemainingRechargeCD 0x64
#define oSpellSlotTime 0x28
#define oSpellSlotCD 0x18
#define oSpellSlotDamage 0x90
#define oSpellSlotSpellInfo 0x134
#define oSpellSlotRemainingCD 0x28

//oSpellInfoSpellData
#define oSpellInfoSpellData 0x44

//SpellData
#define oSpellDataMissileName 0x0058
#define oSpellDataSpellName 0x007C
#define oSpellDataSpellName2 0x007C
#define oSpellDataDescription 0x0088
#define oSpellDataEffectAmount 0xD0
#define oSpellDataIncreaseDamage 0xEC
#define oSpellDataSpellDuration 0x108
#define oSpellDataRootDuration 0x15C
#define oSpellDataIncreaseDamageBonus 0x178
#define oSpellDataCoefficient 0x200
#define oSpellDataCoefficient2 0x204
#define oSpellDataMaxHighlightTargets 0x208
#define oSpellDataCooldownTime 0x280
#define oSpellDataDelayCastOffsetPercent 0x29C
#define oSpellDataDelayTotalTimePercent 0x2A0
#define oSpellDataMaxAmmo 0x31C
#define oSpellDataAmmoUsed 0x338
#define oSpellDataAmmoRechargetime 0x354
#define oSpellDataMissileSpeed 0x450
#define oSpellDataSpellWidth 0x458
#define oSpellDataSpellRange 0x3D0
#define oSpellDataEffectSpellRange 0x10C // starts from F4
#define oSpellDataEffectSpellRangeAfterEffect 0xB8 // starts from A0

//champion_manager
#define oChampionManagerChampionList 0xC
#define oChampionCount 153
#define oGetChampionSkins 0x58
#define oGetChampionName 0x4
