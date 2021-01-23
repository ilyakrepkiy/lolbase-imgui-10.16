#pragma once
#define TARGET_GAMEVERSION "Version 11.1.351.8352 [PUBLIC]"  // 

#define oRetAddr 0x6E502 // 				// find addr : ret // opcode : C3
#define oDrawCircleRetAddr 0x6E4FF // 		// find addr : add esp, 28 ret // opcode : 83 C4 1C C3
#define oNetClient 0x34F615C // 			8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset] // this addy us for IsTargetable as per chinese tool but nah~
#define oPingInstance 0x34F615C //			8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset]
#define oChatClientPtr 0x289EE80 //			8B 0D ? ? ? ? 6A 01 FF 74 24 08 // dword_[offset] // 8B ?? ?? ?? ?? ?? 6A ?? 50 E8 ?? ?? ?? ?? 33 C0 5F C2 // dword_[offset]
#define oObjManager 0x1C52490 //			8B 0D ? ? ? ? 89 74 24 14 // dword_[offset]
#define oZoomClass 0x34E67B4 //				A3 ? ? ? ? 83 FA 10 72 32 // dword_[offset]
#define oGameInfo 0x289E910 // 				A1 ? ? ? ? 83 78 08 02 0F 94 C0 // dword_[offset]
#define oHudInstance 0x1C524D0 //			8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0 // dword_[offset]
#define oRenderer 0x35179E4 // 				8B 15 ? ? ? ? 83 EC 08 F3 // dword_[offset]
#define oUnderMouseObject 0x1BF2168 // 		8B 0D ? ? ? ? 89 0D // dword_[offset]
#define D3DRenderer 0x35179E4 // 				8B 15 ? ? ? ? 83 EC 08 F3 // dword_[offset]
#define oLocalPlayer 0x34EEDE4 //			A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56 // dword_[offset]
#define oGameTime 0x34E6FD4 // 				F3 0F 11 05 ? ? ? ? 8B 49 // dword_[offset]
#define oMenuGUI 0x34EE8C8 // 				8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7 // dword_[offset]

// FUNCTIONS
#define oReturnAddressCheck 0x1D5310 //
#define oGetNextObject 0x290480 //			E8 ? ? ? ? 8B F0 85 F6 75 E4 // sub_[offset]
#define oGameVersion 0x545C30 //			E8 ? ? ? ? 50 68 ? ? ? ? 6A 00 6A 01 6A 02 E8 ? ? ? ? E8 ? ? ? ? // sub_[offset]
#define oGetFirstObject 0x28F260 //			E8 ? ? ? ? 8B F8 85 FF 0F 84 ? ? ? ? 53 8B 5C // sub_[offset]
#define oWorldToScreen 0x961840 // 			83 EC 10 56 E8 ? ? ? ? 8B 08 // fn
#define oCastSpell 0x509110 // 				xref: ERROR: Client Tried to cast a spell from an invalid slot: %d.\n
#define oDrawCircle 0x502FC0 //			 	E8 ? ? ? ? 83 C4 1C 8B 7C 24 28 // sub_[offset]
#define oGetBasicAttack 0x169520 // 	 	53 8B D9 B8 ? ? ? ? 8B 93 // fn
#define oGetAttackCastDelay 0x2A4920 // 	83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90 // fn // E8 ?? ?? ?? ?? D9 ?? ?? ?? ?? ?? 56 E8 // sub_[offset]
#define oGetAttackDelay 0x2A4A20 // 		E8 ? ? ? ? 8B 44 24 1C 83 C4 0C 8B CE // sub_[offset] // this addy is for oGetPing as per chinese tool but nah~
#define oGetPing 0x336D20 // 				E8 ? ? ? ? 8B 4F 2C 85 C9 0F // sub_[offset]
#define oGetSpellState 0x4FD5F0 // 			E8 ? ? ? ? 8B F8 8B CB 89 // sub_[offset] // this addy us for IsTargetable as per chinese tool but nah~
#define oIsTargetable 0x1D9380 //			56 8B F1 E8 ? ? ? ? 84 C0 74 2E // fn
#define oIsAlive 0x1A1BF0  // 				56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19 // fn
#define oIsBaron 0x1764E0 //				E8 ? ? ? ? 84 C0 74 0A BB // sub_[offset]
#define oIsTurret 0x1B0EE0 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F // sub_[offset]
#define oIsInhib 0x1B0AF0 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 38 // sub_[offset]
#define oIsHero 0x1B0C70 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 2B 57 // sub_[offset]
#define oIsMinion 0x1B0CB0 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F // sub_[offset]
#define oIsDragon 0x174710 //  				E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9 // sub_[offset]
#define oIsMissile 0x1B0CD0 //		   		E8 ?? ?? ?? ?? 83 C4 04 84 C0 74 60 // sub_[offset]
#define oIsNexus 0x1B0BF0 //				E8 ? ? ? ? 83 C4 04 84 C0 0F 95 C0 C3 CC 8A // sub_[offset]
#define oIsNotWall 0x8DED80 // 				E8 ? ? ? ? 33 C9 83 C4 0C 84 // sub_[offset]
#define oIsTroy 0x1B0B70  // 				E8 ? ? ? ? 8B D8 83 C4 04 85 DB 0F 84 ? ? ? ? 6A 08 // go to sub_XXX then sub_[offset]
#define oIssueOrder 0x176590 // 			81 EC ? ? ? ? 56 57 8B F9 C7 // fn // E8 ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 8B 84 ?? ?? ?? ?? ?? 8B CF F3 0F 7E 00 // sub_[offset]
#define oPrintChat 0x590060 //				E8 ? ? ? ? 6A 00 68 ? ? ? ? E8 ? ? ? ? 83 C4 04 // sub_[offset]
#define oSendChat 0x5D4950 //				A1 ? ? ? ? 56 6A FF // fn
#define oGetTimerExpiry 0x12E730 // 		E8 ? ? ? ? 51 D9 1C 24 E8 ? ? ? ? 8B // sub_[offset]
#define oHealthBarPosition 0x577660 //		E8 ?? ?? ?? ?? 8B 4E ?? 8D 54 ?? ?? 52 8B 01 FF ?? ?? 5E 83 ?? ?? C3 // sub_[offset]
#define oBaseDrawPosition 0x16B860 //		E8 ?? ?? ?? ?? EB ?? 8B 01 8B 40 // sub_[offset]

//functions - skinChanger
#define translateString_UNSAFE_DONOTUSE 0xA90CB0 //		E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 04 8B F0 6A 0B // sub_[offset] // 83 EC 0C 56 8B 74 24 14 56 E8 ? ? ? ? 83 C4 04 89 74 24 04 89 44 24 08 A8 01 // fn
#define CharacterDataStack__Push 0x114750 //		E8 ? ? ? ? 8D 4C 24 10 E8 ? ? ? ? 8B 44 24 44 // fn // 10.22 -> 13 Params, 10.23 -> 14 Params
#define CharacterDataStack__Update 0x10ACE0 //		83 EC 18 53 56 57 8D 44 24 20 // fn
#define GetOwnerObject 0x16B2E0 //		E8 ? ? ? ? 39 44 24 1C 5F // sub_[offset]
#define CharacterData__GetCharacterPackage 0x23AC60 //		81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 56 8B B4 24 ? ? ? ? 8B C6 // fn // E8 ? ? ? ? 8B 54 24 30 83 C4 08 89 44 24 10 // sub_[offset]
#define GetAiManager 0x16DCF0 // E8 ?? ?? ?? ?? 50 8B CE E8 ?? ?? ?? ?? 80 BB ?? ?? ?? ?? ?? // sub_[offset]
#define SetBaseCharacterData 0x19C290 // E8 ?? ?? ?? ?? 8B 54 ?? ?? 83 ?? ?? 72 ?? 8B 4C ?? ?? 42 8B C1 81 ?? ?? ?? ?? ?? 72 ?? 8B 49 ?? 83 ?? ?? 2B C1 83 ?? ?? 83 ?? ?? 0F ?? ?? ?? ?? ?? 52 51 E8 ?? ?? ?? ?? 83 ?? ?? 8B 06 8B CE FF ?? ?? ?? ?? ?? 8B CE F3 0F // sub_[offset]
#define IsLaneMinion 0x37A8 //		8A 87 ? ? ? ? 88 4C 24 0B // edi+[offset]h - 1

// ai_base  - skinChanger
#define CharacterDataStack 0x2F60 //		E8 ? ? ? ? 8D 4C 24 10 E8 ? ? ? ? 8B 44 24 64 // go to fn xref to operand, go to 1 result, lea ecx, [esi+[offset]h]
#define SkinId 0x0EBC //		E8 ? ? ? ? 83 C4 0C 80 BF // scroll down, instruction: cmp byte ptr [xxx+[offset]h], 0

//global - skinChanger
#define ChampionManager 0x34E80F8 //		89 1D ? ? ? ? 56 8D 4B 04 // 8B 0D ? ? ? ? 83 C1 0C 89 14 24 // 8B 0D ? ? ? ? 57 FF 74 24 08 E8 ? ? ? ? 8B F8 // dword_[offset]
#define ManagerTemplate_AIMinionClient_ 0x289E8EC //		A1 ? ? ? ? 53 55 8B 6C 24 1C // A1 ? ? ? ? F3 0F 10 40 ? F3 0F 11 44 24 // dword_[offset]
#define ManagerTemplate_AIHero_ 0x1C50400 // 8B 0D ? ? ? ? 50 8D 44 24 18 // 8B 35 ? ? ? ? C7 44 24 ? ? ? ? ? C7 44 24 ? ? ? ? ? E8 // dword_[offset]

//events
#define oOnprocessSpell 0x4F5570 // 		E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 80 BE ?? ?? ?? ?? ?? D8 // sub_[offset]
#define OnCreateObject 0x296700 // 		E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 84 C0 74 ?? 32 C9 EB // E8 ? ? ? ? 0F B6 47 35 // sub_[offset]
#define oOnDeleteObject 0x28D760 // 		E8 ? ? ? ? 8B 4E 20 85 C9 74 0F // E8 ? ? ? ? 83 C7 04 3B FB 75 E2 // sub_[offset]
#define oOnNewPath 0x2969E0 // 		83 EC 18 56 8B 74 24 20 8B CE 57 // fn // E8 ? ? ? ? 8B 74 24 4C 83 C4 30 // sub_[offset]

//lol
#define Riot__g_window 0x34EEDC4 // 3B 05 ? ? ? ? 75 72 // dword_[offset]
#define GfxWinMsgProc 0x350DD48 // A1 ? ? ? ? 55 57 53 // off_[offset]
#define GameClient 0x289E910 // A1 ? ? ? ? 68 ? ? ? ? 8B 70 08 // dword_[offset]
#define D3DDevice 0x208 //8B 86 ? ? ? ? 89 4C 24 08 // mov eax, [esi+[offset]h]
#define SwapChain 0x10C // 8B 8E ? ? ? ? 52 57 // mov ecx, [esi+[offset]h]
#define Riot__Renderer__MaterialRegistry__GetSingletonPtr 0x9AF1D0 // A1 ? ? ? ? 85 C0 75 0B 8B 0D ? ? ? ? 8B 01 FF 60 14 // fn
#define GetGoldRedirectTarget 0x16B2E0 // E8 ? ? ? ? 39 44 24 1C 5F // E8 ? ? ? ? 8B F8 3B F7 0F 84 // sub_[offset]
#define SummonerEmoteUserComponent__GetSummonerEmoteData 0x25A540 // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 56 FF B4 24 ? ? ? ? 8D 44 24 14 // fn // E8 ? ? ? ? 83 C4 04 85 C0 74 65 57 // sub_[offset]
#define SummonerEmoteUserComponent__SetEmoteIdForSlot 0x260DF0 // 83 EC 08 56 57 FF 74 24 14 // fn

//CObject
#define oObjIndex 0x20 //11.1 serge
#define oObjTeam 0x4C // 11.1 jingz
#define oObjName 0x6C // 11.1 jingz
#define oObjNetworkID 0xCC // 11.1 jingz
#define oObjPos 0x1D8 // 11.1 jingz
#define oObjVisibility 0x270 // 11.1 jingz
#define oObjHealth 0xD98 // 11.1 jingz
#define oObjMana 0x298 // 11.1 serge
#define oObjMaxMana (oObjMana + 0x10);
#define oObjArmor 0x1298 // 11.1 jingz
#define oObjMagicRes 0x12A0 // 11.1 leryss
#define oObjBonusMagicRes 0x1284 // ?
#define oObjBaseAtk 0x1270 // 11.1 jingz
#define oObjBonusAtk 0x11F0 // 11.1 jingz
#define oObjMoveSpeed 0x1290 // 11.1 jingz
#define oObjAtkRange 0x12B8 // 11.1 jingz
#define oObjBuffMgr 0x2160 // 11.1 quakehero123
#define oObjSpellBook 0x2708 // 11.1 jingz (0x2B80 - 0x478)
#define oObjChampionName 0x3134 // 11.1 jingz
#define oObjLevel 0x36BC // 11.1 jingz
#define oObjIsOnScreen 0x01A8 // 11.1 
#define oObjSourceIndex 0x290 // 11.1 quakehero123
#define oObjMovementSpeed 0x1290 // 11.1 jingz
#define oObjPerk1 0x38A8  // 8D 8E ? ? ? ? E8 ? ? ? ? 8B CE E8 ? ? ? ? A1 // esi+[offset]h // 81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 53 8B 9C 24 ? ? ? ? 56 8B F1 88 5C 24 0C // fn + 19F
#define oObjPerk2 0x2C8 // 51 53 8B D9 33 C9 + 18C // go to sub_XXXX then  + 44
#define oInhiRemainingRespawnTime 0x1014 // 11.1 

//ObjectManager
#define objectArray 0x14

//SpellBook
#define oSpellBookOwner 0x1c

//MissileInfo
#define oMissileSpellInfo 0x230
#define oMissileSourceIndex 0x290
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

//ChatClient
#define oChatClientStruct 0x4

//ChatClientStruct
#define oIsChatOpen 0x614 // 11.1 quakehero123
#define oCurrentChatWideString 0x5E4
#define oCurrentChatLength 0x5F4
#define oCurrentChatBoxIteration 0x61C
#define oChatBoxTopLeft 0x630
#define oChatBoxBottomRight 0x638
#define oChatBoxActive 0x645

//oSpellSlot
#define oSpellSlotRemainingCharge 0x58
#define oSpellSlotLevel 0x20
#define oSpellSlotRemainingRechargeCD 0x64
#define oSpellSlotTime 0x28
#define oSpellSlotCD 0x18
#define oSpellSlotDamage 0x94
#define oSpellSlotSpellInfo 0x134
#define oSpellSlotRemainingCD 0x28

//oSpellInfoSpellData
#define oSpellInfoSpellData 0x44

//SpellData
#define oSpellDataMissileName 0x0058
#define oSpellDataSpellName 0x0064
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
#define oSpellDataMissileSpeed 0x440  // 11.1 jingz
#define oSpellDataSpellWidth 0x474 // 11.1 quakehero123
#define oSpellDataSpellRange 0x3B4 // 11.1 quakehero123
#define oSpellDataEffectSpellRange 0x10C // starts from F4
#define oSpellDataEffectSpellRangeAfterEffect 0xB8 // starts from A0

//champion_manager
#define oChampionManagerChampionList 0xC
#define oChampionCount 153
#define oGetChampionSkins 0x58
#define oGetChampionName 0x4