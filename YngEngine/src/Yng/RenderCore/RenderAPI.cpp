#pragma once
#include"Yng/RenderCore/RenderAPI.h"

#if YNG_PLATFORM_WINDOWS
#include "Yng/D3D12/D3D12Context.h"
#endif 

namespace Yng {
#if YNG_PLATFORM_WINDOWS
		UniquePtr<RenderAPI> RenderAPI::GetNativeAPI(const Window& window) {

			return MakeUnique<D3D12API>(window);
#endif
		
	};
}