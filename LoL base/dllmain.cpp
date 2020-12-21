#include <time.h>
#include "stdafx.h"
#include "Windows.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include "ImRender.hpp"
#include "COrbWalker.h"
#include <mutex>

#include "imgui\imgui.h"
#include "imgui\imgui_internal.h"
#include "imgui\dx9\imgui_impl_dx9.h"
#include "imgui\win32\imgui_impl_win32.h"

#pragma comment(lib, "detours.lib")
using namespace std;
#define DO_ONCE(todo) do { \
   static std::once_flag _flag ;\
   std::call_once(_flag, todo); \
} while (false)

CObjectManager* ObjManager;
CFunctions Functions;
COrbWalker orbWalker;

HMODULE g_module = nullptr;
HWND g_hwnd = nullptr;
WNDPROC g_wndproc = nullptr;
IDirect3DDevice9* myDevice;
clock_t lastmove = NULL;

bool g_menu_opened = true;
bool g_range = true;
bool g_unload = false;
bool g_2range_objmanager = false;
bool g_champ_info = false;
bool g_move_to_mouse = false;
bool g_w2s_line = false;
bool OnStartMessage = false;
bool g_interface = false;

IMGUI_IMPL_API LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param);

typedef HRESULT(WINAPI* Prototype_Present)(LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
typedef HRESULT(WINAPI* Prototype_Reset)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
Prototype_Reset Original_Reset;
Prototype_Present Original_Present;

HRESULT WINAPI Hooked_Present(LPDIRECT3DDEVICE9 Device, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion)
{
	myDevice = Device;
		DO_ONCE([&]()
	{
		render.init(Device);
	});

		ImGui::CreateContext();											
		render.begin_draw();//begin for draw rende.drawline.... and etc

	if (ImGui_ImplWin32_Init(g_hwnd))
	{
		if (ImGui_ImplDX9_Init(Device))
		{
			if (g_menu_opened)
			{
				ImGui::Begin("kmsmym::unknowncheats.me", &g_menu_opened, ImGuiWindowFlags_NoSavedSettings);
				{
					ImGui::BeginChild("##child", ImVec2(450.0f, 450.0f), false, ImGuiWindowFlags_NoSavedSettings);
					{
						ImGui::Checkbox("My range demostration", &g_range);
						ImGui::Checkbox("All hero range demostration", &g_2range_objmanager);
						ImGui::Checkbox("Move to mouse demostration", &g_move_to_mouse);
						ImGui::Checkbox("W2S/Line demostration", &g_w2s_line);
						ImGui::Checkbox("Text champ info demostration", &g_champ_info);

						ImGui::Checkbox("Orbwalker: Last Hit", &orbWalker.lastHitOnly);
					}
					ImGui::EndChild();
				}
				ImGui::End();
			}
		}
	}

	if (me && me->IsAlive()) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			orbWalker.drawEvent();
		}
	}

	if (g_range == true) {
		if (me) {

			if (me->IsAlive()) {
				auto color = ImColor(0, 255, 0);
				render.draw_circle(me->GetPos(), me->GetAttackRange() + me->GetBoundingRadius(), color, c_renderer::circle_3d, 20, 3.0f);
			}
		}
	}

	if (g_w2s_line == true) {
		Vector me_pos = me->GetPos();
		Vector mepos_w2s;
		Functions.WorldToScreen(&me_pos, &mepos_w2s);
		Vector mouse_pos_w2s;
		Vector mouse_pos = Engine::GetMouseWorldPosition();
		Functions.WorldToScreen(&mouse_pos, &mouse_pos_w2s);
		render.draw_line(mepos_w2s.X, mepos_w2s.Y, mouse_pos_w2s.X, mouse_pos_w2s.Y, ImColor(15, 150, 40, 255), 5.0f);
	}

	if (g_move_to_mouse == true) {
		if (lastmove == NULL || clock() - lastmove > 30.0f) {
			lastmove = clock();
			Engine::IssueMove(&Engine::GetMouseWorldPosition());
		}
	}

	if (g_2range_objmanager == true) {
		CObject holzer;
		auto obj = holzer.GetFirstObject();
		while (obj)
		{
			if (obj->IsHero())
			{ 
				auto color = createRGB(255, 0, 0);
				render.draw_circle(obj->GetPos(), obj->GetAttackRange(), color, c_renderer::circle_3d, 20, 1.0f);
			}
			obj = holzer.GetNextObject(obj);
		}
	}

	if (g_champ_info == true) {
		CObject holzer;
		auto obj = holzer.GetFirstObject();
		while (obj)
		{
			if (obj->IsHero())
			{
				Vector obj_pos = obj->GetPos();
				Vector objpos_w2s;
				Functions.WorldToScreen(&obj_pos, &objpos_w2s);
				render.draw_text(objpos_w2s.X, objpos_w2s.Y + 15, obj->GetName(), true, ImColor(255, 0, 0, 255));
				render.draw_text(objpos_w2s.X, objpos_w2s.Y + 30, obj->GetChampionName(), true, ImColor(255, 0, 0, 255));

				char Get_Health[10];				
				sprintf(Get_Health, "%f", obj->GetHealth());

				render.draw_text(objpos_w2s.X, objpos_w2s.Y + 45, Get_Health, true, ImColor(255, 0, 0, 255));

			}
			obj = holzer.GetNextObject(obj);
		}
	}

	render.end_draw();
	return Original_Present(Device, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}

HRESULT WINAPI Hooked_Reset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	HRESULT result = Original_Reset(pDevice, pPresentationParameters);

	if (result >= 0)
		ImGui_ImplDX9_CreateDeviceObjects();

	return result;
}

DWORD FindDevice(DWORD Len)
{
	DWORD dwObjBase = 0;

	dwObjBase = (DWORD)LoadLibrary("d3d9.dll");
	while (dwObjBase++ < dwObjBase + Len)
	{
		if ((*(WORD*)(dwObjBase + 0x00)) == 0x06C7
			&& (*(WORD*)(dwObjBase + 0x06)) == 0x8689
			&& (*(WORD*)(dwObjBase + 0x0C)) == 0x8689
			) {
			dwObjBase += 2; break;
		}
	}
	return(dwObjBase);
}

DWORD GetDeviceAddress(int VTableIndex)
{
	PDWORD VTable;
	*(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);
	return VTable[VTableIndex];
}

void __stdcall Start() {
	while (Engine::GetGameTime() < 1.0f || !me)
		Sleep(1);

	g_hwnd = FindWindowA(nullptr, "League of Legends (TM) Client");
	g_wndproc = WNDPROC(SetWindowLongA(g_hwnd, GWL_WNDPROC, LONG_PTR(WndProc)));

	ObjManager = (CObjectManager*)(*(DWORD*)(baseAddr + oObjManager));

	Functions.PrintChat = (Typedefs::fnPrintChat)(baseAddr + oPrintChat);
	Functions.IsTargetable = (Typedefs::fnIsTargetable)(baseAddr + oIsTargetable);
	Functions.IsAlive = (Typedefs::fnIsAlive)(baseAddr + oIsAlive);

	Functions.IsMinion = (Typedefs::fnIsMinion)(baseAddr + oIsMinion);
	Functions.IsTurret = (Typedefs::fnIsTurret)(baseAddr + oIsTurret);
	Functions.IsHero = (Typedefs::fnIsHero)(baseAddr + oIsHero);
	Functions.IsMissile = (Typedefs::fnIsMissile)(baseAddr + oIsMissile);
	Functions.IsNexus = (Typedefs::fnIsNexus)(baseAddr + oIsNexus);
	Functions.IsInhibitor = (Typedefs::fnIsInhibitor)(baseAddr + oIsInhib);
	Functions.IsTroyEnt = (Typedefs::fnIsTroyEnt)(baseAddr + oIsTroy);

	Functions.IssueOrder = (Typedefs::fnIssueOrder)((DWORD)GetModuleHandle(NULL) + oIssueOrder);
	Functions.WorldToScreen = (Typedefs::WorldToScreen)(baseAddr + (DWORD)oWorldToScreen);

	Functions.GetAttackCastDelay = (Typedefs::fnGetAttackCastDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackCastDelay);
	Functions.GetAttackDelay = (Typedefs::fnGetAttackDelay)((DWORD)GetModuleHandle(NULL) + oGetAttackDelay);

	Original_Present = (Prototype_Present)DetourFunction((PBYTE)GetDeviceAddress(17), (PBYTE)Hooked_Present);
	Original_Reset = (Prototype_Reset)DetourFunction((PBYTE)GetDeviceAddress(16), (PBYTE)Hooked_Reset);

	while (!g_unload)
		Sleep(1);

	ImGui_ImplWin32_Shutdown();
	ImGui_ImplDX9_Shutdown();

	g_wndproc = WNDPROC(SetWindowLongA(g_hwnd, GWL_WNDPROC, LONG_PTR(g_wndproc)));
	DetourRemove((PBYTE)Original_Reset, (PBYTE)Hooked_Reset);
	DetourRemove((PBYTE)Original_Present, (PBYTE)Hooked_Present);

	ImGui::DestroyContext(ImGui::GetCurrentContext());

	FreeLibraryAndExitThread(g_module, 0);
}

LRESULT WINAPI WndProc(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param)
{
	switch (u_msg)
	{
	case WM_KEYDOWN:
		if (w_param == VK_END)
			g_menu_opened = !g_menu_opened;
		break;
	default:
		break;
	}

	if (g_menu_opened && ImGui_ImplWin32_WndProcHandler(hwnd, u_msg, w_param, l_param))
		return true;

	return CallWindowProcA(g_wndproc, hwnd, u_msg, w_param, l_param);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (hModule != nullptr)
		DisableThreadLibraryCalls(hModule);

	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		g_module = hModule;
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Start, 0, 0, 0);
		return TRUE;
	}

	else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
		g_unload = true;
		return TRUE;
	}

	return FALSE;
}