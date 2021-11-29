#pragma once

#include"Yng/Core/CoreMinimal.h"
#include"Yng/Core/Window.h"

namespace Yng {

	class RenderAPI {
		
	public:
		virtual ~RenderAPI() = default;

		static UniquePtr<RenderAPI> GetNativeAPI(const Window&);
		virtual bool InitializeHardware() = 0;

	};
}