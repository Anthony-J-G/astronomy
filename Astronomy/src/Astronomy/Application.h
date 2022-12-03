#pragma once

// Include Statements
#include "Core.h"



namespace Astronomy {
	
	class ASTRO_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

 	};

	// To be defined in Client
	Application* CreateApplication();

}

