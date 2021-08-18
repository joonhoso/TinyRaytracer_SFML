#pragma once

#include "Sphere.h"

#include "SFML/Graphics.hpp"

class Renderer
{
private:
	const unsigned int width;
	const unsigned int height;
	const unsigned int previewWidth;
	const unsigned int previewHeight;
	const float fov;

public:
	Renderer(unsigned int w, unsigned int h, float fov,
			unsigned int previewWidth, unsigned int previewHeight);
	sf::Int32 Render(std::vector<Vec3f>& frameBuffer, const Sphere& sphere, bool isPreview);

private:
	Vec3f CastRay(const Vec3f& origin, const Vec3f& direction, const Sphere& sphere);
};