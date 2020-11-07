#pragma once
#define TARGET_GAMEVERSION "Version 10.22.341.643 [PUBLIC]"

// Offsets
#define oGetTimerExpiry 0x0012c310            // 56 8B F1 83 BE ? ? ? ? ? 74 6F
#define oGetBasicAttack 0x00166970            // 53 8B D9 B8 ? ? ? ? 8B 93
#define oBaseDrawPosition 0x00168c00          // 30 44 14 10 42 3B D1 72 F0 8B 74 24 14 83 7C 24 ? ? 74
#define oIsDragon 0x00171c70                  // 83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 81
#define oIsBaron 0x00173b20                   // 56 81 C1 ? ? ? ? E8 ? ? ? ? 68
#define oIssueOrder 0x00173bd0                // 56 57 8B F9 C7 84 24 ? ? ? ? ? ? ? ? 8B 87
#define oIsAlive 0x0019f2a0                   // 56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19
#define oIsInhib 0x001ad930                   // E8 ? ? ? ? 55 88 44 24 1F
#define oIsNexus 0x001ada30                   // E8 ? ? ? ? 55 88 44 24 20
#define oIsHero 0x001adab0                    // E8 ? ? ? ? 83 C4 04 84 C0 74 52
#define oIsMinion 0x001adaf0                  // E8 ? ? ? ? 83 C4 04 80 7F 26 06
#define oIsMissile 0x001adb10                 // E8 ? ? ? ? 83 C4 04 84 C0 74 3F
#define oIsTurret 0x001add20                  // E8 ? ? ? ? 83 C4 04 84 C0 75 22
#define oIsTargetable 0x001d4070              // 56 8B F1 E8 ? ? ? ? 84 C0 74 2E 8D
#define oGetFirstObject 0x00288160            // 8B 41 14 8B 51 18
#define oGetNextObject 0x00289140             // 8B 44 24 04 56 8B 71 18
#define oGetAttackCastDelay 0x002a5020        // 83 EC 0C 53 8B 5C 24 14 8B CB 56
#define oGetAttackDelay 0x002a5120            // 8B 44 24 04 51 F3
#define oGetPing 0x00335730                   // 55 8B EC 83 EC 08 0F B6
#define oGetSpellState 0x005004f0             // 83 EC 14 8B 44 24 1C 55
#define oDrawCircle 0x00503470                // 33 C4 89 84 24 ? ? ? ? F3 0F 10 84 24 ? ? ? ? 8D 0C
#define oCastSpell 0x0050f1d0                 // 50 6A 02 E8 ? ? ? ? 83 C4 14 5B 5F 5D 83 C4 34 C2 14
#define oGameVersion 0x0056c740               // E8 ? ? ? ? 50 FF 36 8D 44 24 6C
#define oPrintChat 0x0057ea20                 // 83 EC 44 A1 ? ? ? ? 33 C5 89 45 FC 53 8B 5D 0C 56 8B
#define oHealthBarPosition 0x005a5fe0         // 83 EC 28 53 55 56 57 8B F9 6A
#define oSendChat 0x005fb9d0                  // A1 ? ? ? ? 56 6A FF
#define oIsNotWall 0x008fe4a0                 // 85 FF 0F 48 C3 0F AF C8 8B 86 ? ? ? ? 5F 5E 5B 03 CA 8D
#define oIsTroy 0x1AD9B0					  // E8 ? ? ? ? 8B E8 83 C4 04 85 ED 0F 84 ? ? ? ? 6A 08
#define oWorldToScreen 0x00986720             // 83 EC 10 56 E8 ? ? ? ? 8B 08
#define oUnderMouseObject 0x01c1b0f0          // 8B 0D ? ? ? ? 89 0D
#define oChatClientPtr 0x01c79590             // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33
#define oObjManager 0x01c7bb18                // 8B 0D ? ? ? ? 89 74 24 14
#define oHudInstance 0x01c7bb54               // 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0 01 C2
#define oZoomClass 0x0350ff54                 // A3 ? ? ? ? 83 FA 10 72 32
#define oGameTime 0x03510778                  // F3 0F 11 05 ? ? ? ? 8B 49
#define oGameInfo 0x035118b0                  // A1 ? ? ? ? 83 78 08 02 0F 94
#define oMenuGUI 0x03518004                   // 8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7
#define oLocalPlayer 0x03518034               // A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
#define oPingInstance 0x0351f884              // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oNetClient 0x0351f884                 // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oRenderer 0x03540c74                  // 8B 15 ? ? ? ? 83 EC 08
#define oD3DRenderer 0x035439b8               // A1 ? ? ? ? 89 54 24 18

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC
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

#define oMissileSpellInfo 0x230
#define oMissileTargetIndex 0x2E8
#define oMissileStartPos 0x2A8
#define oMissileEndPos 0x2B4

// ObjectArray
#define objectArray 0x14

// BuffManager
#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
#define O_BUFFMGR_flBUFFCOUNT 0x130 
#define O_BUFFMGR_iBUFFCOUNT 0x74 
#define oBuffType 0x4
#define oBuffCountAlt 0x24
#define oBuffCountAlt2 0x20