#pragma once

#ifdef BLB_PLATFORM_WINDOWS

extern Bulb::Application* Bulb::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = Bulb::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif