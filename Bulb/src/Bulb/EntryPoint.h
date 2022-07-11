#pragma once

#ifdef BLB_PLATFORM_WINDOWS
#include "Application.h"

extern Bulb::Application* Bulb::CreateApplication();

int main(int argc, char** argv) 
{
	Bulb::Log::Init();

	BLB_CORE_CRITICAL("EROOR");
	int a = 54;
	BLB_INFO("HELLO! var={0}", a);

	auto app = Bulb::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif