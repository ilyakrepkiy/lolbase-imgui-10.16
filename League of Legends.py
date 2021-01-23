# Author: Uhrwerk (Inspired by eb's Offsets.py)
# Version: 1.3

# Imports
from idc import BADADDR, INF_BASEADDR, SEARCH_DOWN, FUNCATTR_START, FUNCATTR_END
import idc
import idaapi
import datetime

# Settings
definePrefix = "" # Prefix for the #define Output
functionPrefix = "fn" # Prefix for Function Renaming in IDA
offsetPrefix = "o" # Prefix for Offset Renaming in IDA

# Globals
Rename = -1

# Offsets // Patterns // xref's (Type:: 1 => Pattern, 2 => Call Pattern, 3 => Reference)
Functions = [
	["OnprocessSpell", "E8 ?? ?? ?? ?? 8B CE E8 ?? ?? ?? ?? 80 BE ?? ?? ?? ?? ?? D8", 2],
	["GetNextObject", "E8 ? ? ? ? 8B F0 85 F6 75 E4", 2],
	["GameVersion", "E8 ? ? ? ? 50 FF 36 8D 84", 2],
	["GetFirstObject", "E8 ? ? ? ? 8B F8 85 FF 0F 84 ? ? ? ? 53 8B 5C", 2],
	["WorldToScreen", "83 EC 10 56 E8 ? ? ? ? 8B 08", 1],
	["CastSpell", "50 6A 02 E8 ? ? ? ? 83 C4 14 5B 5F 5D 83 C4 34 C2 14", 1],
	["DrawCircle", "E8 ? ? ? ? 83 C4 1C 80 7F", 2],
	["GetBasicAttack", "53 8B D9 B8 ? ? ? ? 8B 93", 1],
	["GetAttackCastDelay", "83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90", 1],
	["GetAttackDelay", "E8 ? ? ? ? 8B 44 24 1C 83 C4 0C 8B CE", 2],
	["GetPing", "E8 ? ? ? ? 8B 4F 2C 85 C9 0F", 2],
	["GetSpellState", "E8 ? ? ? ? 8B F8 8B CB 89", 2],
	["IsTargetable", "56 8B F1 E8 ? ? ? ? 84 C0 74 2E", 1],
	["IsAlive", "56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19", 1],
	["IsBaron", "E8 ? ? ? ? 84 C0 74 0A BB", 2],
	["IsTurret", "E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F", 2],
	["IsInhib", "E8 ? ? ? ? 83 C4 04 84 C0 74 38", 2],
	["IsHero", "E8 ? ? ? ? 83 C4 04 84 C0 74 2B 57", 2],
	["IsMinion", "E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F", 2],
	["IsDragon", "E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9", 2],
	["IsMissile", "E8 ?? ?? ?? ?? 83 C4 04 84 C0 74 60", 2],
	["IsNexus", "E8 ? ? ? ? 83 C4 04 84 C0 0F 95 C0 C3 CC 8A", 2],
	["IsNotWall", "E8 ? ? ? ? 33 C9 83 C4 0C 84", 2],
	["IsTroy", "E8 ? ? ? ? 8B E8 83 C4 04 85 ED 0F 84 ? ? ? ? 6A 08", 2],
	["IssueOrder", "E8 ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 8B 84 ?? ?? ?? ?? ?? 8B CF F3 0F 7E 00", 2],
	["PrintChat", "E8 ? ? ? ? 33 C0 5F C2", 2],
	["SendChat", "A1 ? ? ? ? 56 6A FF", 1],
	["GetTimerExpiry", "E8 ? ? ? ? 51 D9 1C 24 E8 ? ? ? ? 8B", 2],
	["HealthBarPosition", "E8 ?? ?? ?? ?? 8B 4E ?? 8D 54 ?? ?? 52 8B 01 FF ?? ?? 5E 83 ?? ?? C3", 2],
	["BaseDrawPosition", "E8 ?? ?? ?? ?? EB ?? 8B 01 8B 40", 2],
	["translateString_UNSAFE_DONOTUSE", "E8 ? ? ? ? 8B 0D ? ? ? ? 83 C4 04 8B F0 6A 0B", 2],
	["CharacterDataStack__Push", "E8 ? ? ? ? 8D 4C 24 10 E8 ? ? ? ? 8B 44 24 44", 2],
	["CharacterDataStack__Update", "83 EC 18 53 56 57 8D 44 24 20", 1],
	["GetOwnerObject", "E8 ? ? ? ? 39 44 24 1C 5F", 2],
	["CharacterData__GetCharacterPackage", "81 EC ? ? ? ? A1 ? ? ? ? 33 C4 89 84 24 ? ? ? ? 56 8B B4 24 ? ? ? ? 8B C6", 1],
	["GetAiManager", "E8 ?? ?? ?? ?? 50 8B CE E8 ?? ?? ?? ?? 80 BB ?? ?? ?? ?? ??", 2],
	["SetBaseCharacterData", "E8 ?? ?? ?? ?? 8B 54 ?? ?? 83 ?? ?? 72 ?? 8B 4C ?? ?? 42 8B C1 81 ?? ?? ?? ?? ?? 72 ?? 8B 49 ?? 83 ?? ?? 2B C1 83 ?? ?? 83 ?? ?? 0F ?? ?? ?? ?? ?? 52 51 E8 ?? ?? ?? ?? 83 ?? ?? 8B 06 8B CE FF ?? ?? ?? ?? ?? 8B CE F3 0F", 2],
	
	["OnCreateObject", "E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 84 C0 74 ?? 32 C9 EB", 2],
	["OnDeleteObject", "E8 ?? ?? ?? ?? 57 E8 ?? ?? ?? ?? 83 ?? ?? 5F 5E C3", 2],
]

Offsets = [
    ["RetAddr", "C3", 2, 0],
    ["DrawCircleRetAddr", "83 C4 1C C3", 2, 0],
    ["NetClient", "8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B", 1, 1],
    ["ChatClientPtr", "8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33", 1, 1],
    ["ObjManager", "8B 0D ? ? ? ? 89 74 24 14", 1, 1],
    ["ZoomClass", "A3 ? ? ? ? 83 FA 10 72 32", 1, 0],
    ["GameInfo", "A1 ? ? ? ? 83 78 08 02 0F 94 C0", 1, 1],
    ["HudInstance", "8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0", 1, 1],
    ["Renderer", "8B 15 ? ? ? ? 83 EC 08 F3", 1, 1],
    ["UnderMouseObject", "8B 0D ? ? ? ? 89 0D", 1, 1],
    ["D3DRenderer", "A1 ? ? ? ? 89 54 24 18", 1, 1],
    ["LocalPlayer", "A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56", 1, 1],
    ["GameTime", "F3 0F 11 05 ? ? ? ? 8B 49", 1, 0],
    ["MenuGUI", "8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7", 1, 1],
    ["ChampionManager", "89 1D ?? ?? ?? ?? 56 8D 4B 04", 1, 0],
    ["ManagerTemplate_AIMinionClient_", "A1 ?? ?? ?? ?? 53 55 8B 6C 24 1C", 1, 1],
    ["ManagerTemplate_AIHero_", "8B 0D ?? ?? ?? ?? 50 8D 44 24 18", 1, 1],
]

# Finder Functions
def FindFuncPattern(Pattern): # Find's Func. by Pattern
	addr = idc.FindBinary(0, SEARCH_DOWN, Pattern)
	if addr == BADADDR: return 0
	
	try:
		return idaapi.get_func(addr).startEA
	except Exception:
		return 0
		
def FindFuncCall(Pattern): # Find's Func. by Pattern to a Call
	addr = idc.FindBinary(0, SEARCH_DOWN, Pattern)
	if addr == BADADDR: return 0
	return idc.GetOperandValue(addr, 0)
	
def FindFuncFirstReference(Reference): # Find's Func. by Reference, Returns first 
	addr = idc.FindBinary(0, SEARCH_DOWN, "\"" + Reference + "\"")
	if addr == BADADDR: return 0
	
	dword = -1
	xrefs = XrefsTo(addr)
	for xref in xrefs:
		dword = xref.frm
		
	try:
		return idaapi.get_func(dword).startEA
	except Exception:
		return 0

def FindStringByReference(Reference): # Extracts String out of Reference (//addr)
	addr = idc.FindBinary(0, SEARCH_DOWN, "\"" + Reference + "\"")
	if addr == BADADDR: return 0
	return idc.GetString(addr)
	
def FindOffsetPattern(Pattern, Operand): # Find Offset by Pattern
	addr = idc.FindBinary(0, SEARCH_DOWN, Pattern)
	if addr == BADADDR: return 0
	
	return idc.GetOperandValue(addr, Operand)

def FindOffsetPattern2(Pattern, Operand): # Find Offset by Pattern
	addr = idc.FindBinary(0, SEARCH_DOWN, Pattern)
	if addr == BADADDR: return 0
	
	return addr

# Helpers
def DecToHex(Addr):
	return "0x%0.2X" % Addr
	
def PrintWrapper(Alias, Addr, Type): # Type: 1 => Function, 2 => Offset
	if Addr == BADADDR or Addr == 0 or Addr == 0x00:
		print(Alias + " -> Error")
		return
		
	if Type == 1: print("#define " + functionPrefix + Alias + " " + DecToHex(Addr-idaapi.get_imagebase()))
	if Type == 2: print("#define " + offsetPrefix + Alias + " " + DecToHex(Addr-idaapi.get_imagebase()))
	
	if Rename == 1:
		if Type == 1: MakeName(Addr, str(functionPrefix + Alias))
		if Type == 2: MakeName(Addr, str(offsetPrefix + Alias))
		
	return
	
# Main
def Initialize():
	global Rename
	Rename = idc.AskYN(0, "Automaticly Update Names? (sub_549570 => PrintChat)")
	if Rename == -1:
		print("Exiting...")
		return
		
	print("")
	print("++ Uhrwerk: Offsets (%s)" % datetime.datetime.now())
	print("Why do they keep breaking...")
	print("")
	
	print("++ Functions")
	for Alias, Reference, Type in Functions:
		if Type == 1: PrintWrapper(Alias, FindFuncPattern(Reference), 1)
		if Type == 2: PrintWrapper(Alias, FindFuncCall(Reference), 1)
		if Type == 3: PrintWrapper(Alias, FindFuncFirstReference(Reference), 1)
	print("")
	
	print("++ Offsets")
	for Alias, Reference, Type, Operand in Offsets:
		if Type == 1: PrintWrapper(Alias, FindOffsetPattern(Reference, Operand), 2)
		if Type == 2: PrintWrapper(Alias, FindOffsetPattern2(Reference, Operand), 2)
	print("")
	
Initialize()