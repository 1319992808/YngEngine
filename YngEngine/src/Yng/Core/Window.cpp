#include"Yng/Core/Window.h"

#ifdef YNG_PLATFORM_WINDOWS
	#include "Yng/Windows/WindowsWindow.h"
#endif // YNG_PLATFORM_WINDOWS

namespace Yng {

	UniquePtr<Window> Window::Create(const WindowProps& props) {

#ifdef YNG_PLATFORM_WINDOWS
		return MakeUnique<WindowsWindow>(props);
#endif // YNG_PLATFORM_WINDOWS
	}
}
