#pragma once

#include "Yng/Core/Window.h"

#include<Windows.h>


namespace Yng{

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return Data.Width; }
		unsigned int GetHeight() const override { return Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { Data.EventCallback = callback; }

		void* GetNativeWindow() const { return m_hWnd;}

		static int HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:

		HWND m_hWnd;
		HINSTANCE m_hInstance;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowData Data;
	};
}
