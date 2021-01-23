#include "CObject.h"
#include <cmath>
#include "ImRender.hpp"
#include "Hooks.h"

extern ImFont* g_font;

c_renderer render;

void c_renderer::init(LPDIRECT3DDEVICE9 device)
{
	if (!device)
		return;

	if (!m_device)
		m_device = device;

	ImGui::CreateContext();

	ImGui_ImplWin32_Init(m_hwnd);
	ImGui_ImplDX9_Init(device);

	if (!m_default)
		m_default = ImGui::GetIO().Fonts->AddFontDefault();

}

void c_renderer::free(void)
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();
}

void c_renderer::begin_draw(void)
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();
	
	const auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs;

	ImGui::GetStyle().AntiAliasedFill = true;
	ImGui::GetStyle().AntiAliasedLines = true;

	ImGui::Begin("##overlay", nullptr, flags);

	ImGui::SetWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);

	m_width = ImGui::GetIO().DisplaySize.x;
	m_height = ImGui::GetIO().DisplaySize.y;
}

void c_renderer::end_draw(void)
{
	ImGui::GetOverlayDrawList()->PushClipRectFullScreen();

	ImGui::End();

	ImGui::EndFrame();

	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void c_renderer::draw_text(float_t x, float_t y, const char* text, bool outlined, ImColor color, e_flags flags, ImFont* font, ...)
{	
	switch (flags)
	{
	case c_renderer::text_normal:

		if (outlined)
		{
			ImGui::GetWindowDrawList()->AddText(ImVec2(x, y + 1.0f), ImColor(0, 0, 0, 255), text);
			ImGui::GetWindowDrawList()->AddText(ImVec2(x + 1.0f, y), ImColor(0, 0, 0, 255), text);
		}

		ImGui::GetWindowDrawList()->AddText(ImVec2(x, y), color, text);
		break;
	case c_renderer::text_with_font:

		if (outlined)
		{
			ImGui::GetWindowDrawList()->AddText(font, font->FontSize, ImVec2(x, y + 1.0f), ImColor(0, 0, 0, 255), text);
			ImGui::GetWindowDrawList()->AddText(font, font->FontSize, ImVec2(x + 1.0f, y), ImColor(0, 0, 0, 255), text);
		}

		ImGui::GetWindowDrawList()->AddText(font, font->FontSize, ImVec2(x, y), color, text);
		break;
	default:
		break;
	}
}

void c_renderer::draw_line(float_t x1, float_t y1, float_t x2, float_t y2, ImColor color, float_t thickness)
{
	ImGui::GetWindowDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), color, thickness);
}

void c_renderer::draw_rect(float_t x, float_t y, float_t w, float_t h, ImColor color, e_flags flags, float_t rounding, uintptr_t points, float_t thickness)
{
	switch (flags)
	{
	case c_renderer::rect_normal:
		ImGui::GetWindowDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), color, rounding, points, thickness);
		break;
	case c_renderer::rect_filled:
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, rounding, points);
		break;
	default:
		break;
	}
}

void c_renderer::draw_triangle(float_t x1, float_t y1, float_t x2, float_t y2, float_t x3, float_t y3, ImColor color, e_flags flags, float_t thickness)
{
	switch (flags)
	{
	case c_renderer::rect_normal:
		ImGui::GetWindowDrawList()->AddTriangle(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), color, thickness);
		break;
	case c_renderer::rect_filled:
		ImGui::GetWindowDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), color);
		break;
	default:
		break;
	}
}

void c_renderer::draw_circle(Vector Position, float_t radius, ImColor color, e_flags flags, uintptr_t points, float_t thickness)
{
	switch (flags)
	{
	case circle_normal:
		ImGui::GetWindowDrawList()->AddCircle(ImVec2(Position.X, Position.Y), radius, color, points, thickness);
		break;
	case circle_filled:
		ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(Position.X, Position.Y), radius, color, points);
		break;
	case circle_3d:
	{
		/*
			credits to masterben2432 @ unknowncheats for this gem
		*/
		static const float PI = 3.14159265358979323846f;
		static const float DELTA_THETA = 2 * PI / points;

		Vector first_point = Position + Vector(radius, 0, 0);
		
		for (float i = 1; i <= points; ++i)
		{
			Vector orientation = Vector(std::cos(DELTA_THETA * i), 0, std::sin(DELTA_THETA * i));
			Vector next_point = Position + (orientation * radius);
			Vector first_point_w2s, next_point_w2s;

			Functions.WorldToScreen(m_device, &first_point, &first_point_w2s);
			Functions.WorldToScreen(m_device, &next_point, &next_point_w2s);

			this->draw_line(first_point_w2s.X, first_point_w2s.Y, next_point_w2s.X, next_point_w2s.Y, color, thickness);

			first_point = next_point;
		}
		break;
	}
	default:
		break;
	}
}