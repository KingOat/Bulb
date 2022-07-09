#include <Bulb.h>

class Sandbox : public Bulb::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Bulb::Application* Bulb::CreateApplication()
{
	return new Sandbox();
}
