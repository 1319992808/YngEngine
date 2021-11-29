#include "Application.h"
#if YNG_PLATFORM_WINDOWS
#include<Windows.h>
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")
#endif
namespace Yng {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		
		
	}

	Application:: ~Application() {
		
	}

	void Application::Run() {

		Initialize();
		GameLoop();
	}

	void Application::GameLoop() {

		//Hard code here, later move to event-------------
		MSG msg = { 0 };
		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				Sleep(100);
			}
		}
		//-------------------------------------------------
	}

	void Application::Initialize() {

		s_Instance = this;
		m_Window = Window::Create();
		m_Renderer = RenderAPI::GetNativeAPI(*m_Window.get());
		m_Renderer->InitializeHardware();

	}
}