#pragma once
//Dependencies----------------------------
#include <d3d12.h>
#include <d3dx12.h>
#include<dxgi1_4.h>
#include<wrl.h>
#include <Windows.h>
#include <d3d12sdklayers.h>
//----------------------------------------
#include "Yng/RenderCore/RenderAPI.h"
#include"Yng/Windows/WindowsWindow.h"
namespace Yng {

	class D3D12API : public RenderAPI {

	public:
		D3D12API(const Window&);
		bool InitializeHardware() override;
	
	private:
		bool CreateCommandObjects();
		bool CreateSwapChain();
		bool CreateDescriptorHeaps();

	private:
		//Hardware Context
		Microsoft::WRL::ComPtr<IDXGIFactory4>  m_DXGIFactory;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain;
		Microsoft::WRL::ComPtr<ID3D12Device>   m_D3D12Device;
		Microsoft::WRL::ComPtr<ID3D12Fence>	   m_Fence;
		HWND m_WindowHandle;
		uint32_t m_WindowWidth;
		uint32_t m_WindowHeight;

		uint32_t m_RtvDescriptorSize;
		uint32_t m_DsvDescriptorSize;
		uint32_t m_CbvSrvUavDescriptorSize;
		uint32_t m_4xMsaaQuality;
		bool m_4xMsaaState = true;

		DXGI_FORMAT m_BackBufferFormat = DXGI_FORMAT_R8G8B8A8_UINT;
		
		//Command Objects
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_CommandQueue;
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_DirectCmdListAlloc;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_CommandList;

		//Descriptor Heaps
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_RtvHeap;
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_DsvHeap;
	};

}