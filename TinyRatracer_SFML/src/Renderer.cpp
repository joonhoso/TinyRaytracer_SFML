#include "Renderer.h"

Renderer::Renderer(unsigned int w, unsigned int h, float fov)
	:width{ w }, height{ h }, fov{ fov }
{
}

sf::Int32 Renderer::Render(std::vector<Vec3f>& frameBuffer, const Sphere & sphere)
{
	// 현재는 Scene에 Sphere 하나만 있다고 가정
	sf::Clock clock;
	for (size_t j = 0; j < height; j++) {
		for (size_t i = 0; i < width; i++) {
			frameBuffer[i + j * width] = Vec3f(j / float(height), i / float(width), 0);
			float x = (2 * (i + 0.5f) / (float)width - 1) * tan(fov / 2.0f)*width / (float)height;
			float y = -(2 * (j + 0.5f) / (float)height - 1) * tan(fov / 2.0f);
			Vec3f dir = Vec3f(x, y, -1).normalize();
			frameBuffer[i + j * width] = CastRay(Vec3f(0, 0, 0), dir, sphere); //카메라는 0,0,0에 위치
		}
	}
	sf::Int32 elapsedTime = clock.getElapsedTime().asMilliseconds();
	return elapsedTime;
}

Vec3f Renderer::CastRay(const Vec3f & origin, const Vec3f & direction, const Sphere& sphere)
{
	float sphereDist = std::numeric_limits<float>::max();
	if (!sphere.rayIntersect(origin, direction, sphereDist))
	{
		return Vec3f(0.2f, 0.7f, 0.8f); // Not intersect
	}
	return Vec3f(0.4f, 0.4f, 0.3f); // Intersect
}