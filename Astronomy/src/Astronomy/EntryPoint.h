#pragma once

#ifdef ASTRO_PLATFORM_WINDOWS

	extern Astronomy::Application* Astronomy::CreateApplication();

	int main(int argc, char** argv) {
		auto app = Astronomy::CreateApplication();
		app->Run();
		delete app;

	}


#endif // ASTRO_PLATFORM_WINDOWS

