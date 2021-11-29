#pragma once

#ifdef YNG_PLATFORM_WINDOWS

extern Yng::Application* Yng::CreateApplication();

int main(int argc, char** args) {
	
	//Bug Log: Whether the compiler can find a symbol in a .h file depends on where the file is pasted.
	//Whether the compiler can find a symbol in a .cpp file depends on what is "in" it.
	Yng::Log::Init();
	auto app = Yng::CreateApplication();
	app->Run();
	delete app;
	
	return 0;
}
#endif

