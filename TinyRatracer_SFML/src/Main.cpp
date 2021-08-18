#include "Window.h"

int main()
{
	constexpr unsigned int WIDTH = 1024;
	constexpr unsigned int HEIGHT = 768;
	constexpr unsigned int PREVIEW_WIDTH = 128;
	constexpr unsigned int PREVIEW_HEIGHT = 96;
	constexpr float FOV = 3.14f / 2.f;

	const Material shinyIvoryMaterial{ Vec2f{0.6f, 0.3f}, Vec3f{0.4f,0.4f,0.3f}, 50.0f };
	const Material dullRedMaterial{ Vec2f{0.7f, 0.1f}, Vec3f{0.5f,0.1f,0.1f}, 5.0f };
	
	Window window{ WIDTH, HEIGHT, FOV, PREVIEW_WIDTH, PREVIEW_HEIGHT };

	// Add sphere objects in scene
	window.AddSphere({ Vec3f(-3.0f, 0.0f, 0.0f), 2.0f, shinyIvoryMaterial });
	window.AddSphere({ Vec3f(-1.0f,-1.5f, 4.0f), 2.0f, dullRedMaterial });
	window.AddSphere({ Vec3f(1.5f,-0.5f, -2.0f), 3.0f, dullRedMaterial });
	window.AddSphere({ Vec3f(7.0f, 5.0f, -2.0f), 4.0f, shinyIvoryMaterial });

	// Add lights in scene
	window.AddLight({ Vec3f(-20.0f, 20.0f, 20.0f), 1.5f });
	window.AddLight({ Vec3f(30.0f, 50.0f,-25.0f), 1.8f });
	window.AddLight({ Vec3f(30.0f, 20.0f, 30.0f), 1.7f });

	window.Run();

	return 0;
}