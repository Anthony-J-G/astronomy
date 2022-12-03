#pragma once

#ifdef ASTRO_PLATFORM_WINDOWS

	extern Astronomy::Application* Astronomy::CreateApplication();

	int main(int argc, char** argv) {
		Astronomy::Log::Initialize();
		ASTRO_ENGINE_WARN("Intialized Engine Logging");
		ASTRO_CLIENT_INFO("Intialized Client Logging");

		auto app = Astronomy::CreateApplication();
		app->Run();
		delete app;

	}

#endif // ASTRO_PLATFORM_WINDOWS

