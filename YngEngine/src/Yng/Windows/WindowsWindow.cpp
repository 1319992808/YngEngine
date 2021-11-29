#include "WindowsWindow.h"

namespace Yng {

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		m_hInstance = GetModuleHandle(0);
		WNDCLASS wc;
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInstance;
		wc.hIcon = LoadIcon(0, IDI_APPLICATION);
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
		wc.lpszMenuName = 0;
		wc.lpszClassName = props.Title.c_str();

		if (!RegisterClass(&wc))
		{
			MessageBox(0, "RegisterClass Failed.", 0, 0);
		}

		// Compute window rectangle dimensions based on requested client area dimensions.
		RECT R = { 0, 0, props.Width,  props.Height};
		AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
		int width = R.right - R.left;
		int height = R.bottom - R.top;

		m_hWnd = CreateWindow(props.Title.c_str(), props.Title.c_str(),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, 0, 0, m_hInstance, 0);
		if (!m_hWnd)
		{
			MessageBox(0, "CreateWindow Failed.", 0, 0);
		}

		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);

	}
	WindowsWindow::~WindowsWindow()
	{
	}
	void WindowsWindow::OnUpdate()
	{
	}
	int WindowsWindow::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;

				// The WM_MENUCHAR message is sent when a menu is active and the user presses 
				// a key that does not correspond to any mnemonic or accelerator key. 
			case WM_MENUCHAR:
				// Don't beep when we alt-enter.
				return MAKELRESULT(0, MNC_CLOSE);

				// Catch this message so to prevent the window from becoming too small.
			case WM_GETMINMAXINFO:
				((MINMAXINFO*)lParam)->ptMinTrackSize.x = 200;
				((MINMAXINFO*)lParam)->ptMinTrackSize.y = 200;
				return 0;
		
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
	}
	void WindowsWindow::Shutdown()
	{
	}
	LRESULT WindowsWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		
		return HandleMessage(hWnd, message, wParam, lParam);
			
	}
}