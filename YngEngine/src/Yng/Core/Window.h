#pragma once
#include "Yng/Core/CoreMinimal.h"
#include "Yng/Events/Event.h"

namespace Yng {

	struct WindowProps {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const String& title = "Young's Engine!",
			uint32_t width = 1080,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{}
	};

	class Window
	{
	public:

		using EventCallbackFn = FuncPtr<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void* GetNativeWindow() const = 0;
		static UniquePtr<Window> Create(const WindowProps& props = WindowProps());

	};
}


