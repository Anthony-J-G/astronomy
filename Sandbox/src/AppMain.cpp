#include <Astronomy.h>



class Sandbox : public Astronomy::Application 
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};


Astronomy::Application* Astronomy::CreateApplication() {
	return new Sandbox();

}