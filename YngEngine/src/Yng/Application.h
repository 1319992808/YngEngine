#pragma once

#include"Core.h"

namespace Yng {

	 //Bug log: __declspec() must not write before class
 	 //Bug log: Check whether project settings are changed after modifying
	 class YNG_API Application
	 {
		public:
		Application();
		virtual ~Application();
		void Run();

	 };

	 Application* CreateApplication(); //Defined in client 
}

