#pragma once

#include "Geometry.h"

#include "../imgui-sfml/imgui.h"
#include "../imgui-sfml/imgui-SFML.h"

class Material
{
private:
	Vec2f albedo;
	Vec3f diffuseColor;
	float specularExponent;

public:
	Material(const Vec2f& a, const Vec3f& color, const float spec)
		: albedo{ a }, diffuseColor{ color }, specularExponent{ spec }
	{

	}

	Material()
		: albedo{ 1.0f, 0.0f }, diffuseColor{ 1.0f, 1.0f, 0.0f }, specularExponent{ 1.0f }
	{

	}

	inline float GetSpecularExponent() const { return specularExponent; }
	inline Vec3f GetDiffuseColor() const { return diffuseColor; }
	inline Vec2f GetAlbedo() const { return albedo; }

	bool EditMaterial()
	{
		bool e1 = ImGui::DragFloat2("albedo", &this->albedo.x, 0.01f, 0.0f, 1.0f);
		bool e2 = ImGui::DragFloat3("color(diffuse)", &this->diffuseColor.x, 0.01f, 0.0f, 1.0f);
		bool e3 = ImGui::SliderFloat("specular exponent", &this->specularExponent, 1.0f, 1000.0f);
		return e1 | e2 | e3;
	}
};