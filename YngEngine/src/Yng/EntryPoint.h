#pragma once

#ifdef YNG_PLATFORM_WINDOWS

extern Yng::Application* Yng::CreateApplication();

int main(int argc, char** args) {

	auto app = Yng::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif


