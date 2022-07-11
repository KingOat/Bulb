#include "Application.h"

#include "Bulb/Events/MouseEvent.h"
#include "Bulb/Log.h"

namespace Bulb {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		MouseButtonPressed e(5);

		if (e.IsInCategory(EventCategoryApplication)) {
			BLB_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			BLB_CRITICAL(e);
		}

		while (true);
	}

}