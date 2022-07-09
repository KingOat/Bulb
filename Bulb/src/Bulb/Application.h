#pragma once

#include "Core.h"

namespace Bulb {

	class BULB_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in CLIENT
	Application* CreateApplication();
}

