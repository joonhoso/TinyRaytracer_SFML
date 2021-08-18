#pragma once

#include "Sphere.h"
#include "Light.h"

#include "SFML/Graphics.hpp"

class Renderer
{
private:
	const unsigned int width;
	const unsigned int height;
	const unsigned int previewWidth;
	const unsigned int previewHeight;
	const float fov;
	Vec3f mCameraPosition;

public:
	Renderer(unsigned int w, unsigned int h, float fov,
			unsigned int previewWidth, unsigned int previewHeight);
	sf::Int32 Render(std::vector<Vec3f>& frameBuffer, const std::vector<Sphere>& scene,
		const std::vector<Light>& lights, bool isPreview) const;

	bool EditCameraPosition();
	
private:
	Vec3f CastRay(const Vec3f& origin, const Vec3f& direction, const std::vector<Sphere>& scene,
		const std::vector<Light>& lights) const;
	float CalculateLighting(const std::vector<Light>& lights, const Vec3f & point, const Vec3f & normal) const;
};