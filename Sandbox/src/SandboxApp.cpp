#include <Yng.h>

//Bug Log: There types of inheritence in C plus plus
class Sandbox : public Yng::Application
{
public:
	Sandbox();
	~Sandbox();
	
};

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

//Bug Log: Get an linking error? Check the namespace
Yng::Application* Yng::CreateApplication() {

	return new Sandbox();

}
