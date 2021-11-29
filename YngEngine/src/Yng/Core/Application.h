#pragma once

#include "Yng/Core/CoreMinimal.h"
#include "Yng/RenderCore/RenderAPI.h"
#include "Yng/Core/Window.h"

int main(int argc, char** args);

namespace Yng {

	 //Bug log: __declspec() must not write before class
 	 //Bug log: Check whether project settings are changed after modifying
	 class Application
	 {
		public:

			Application();
			virtual ~Application();
			void Run();
			void Initialize();
			void GameLoop();

		 private:
			 UniquePtr<Window> m_Window;
			 UniquePtr<RenderAPI> m_Renderer;

			 bool bIsRunning;
		 private:
			 static Application* s_Instance;
			 friend int ::main(int argc, char** argv);
	 };

	 Application* CreateApplication(); //Defined in client 
}

