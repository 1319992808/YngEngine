#include <Yng.h>
#include <Yng/Core/EntryPoint.h>

//Bug Log: Three types of inheritence in C plus plus
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
