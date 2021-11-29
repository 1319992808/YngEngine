#pragma once

#include<memory>
#include"spdlog/spdlog.h"

namespace Yng {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	
	};
}

//... means a variable of arguments
//Core Log Macros
#define YNG_CORE_ERROR(...) ::Yng::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YNG_CORE_INFO(...) ::Yng::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YNG_CORE_TRACE(...) ::Yng::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YNG_CORE_WARN(...) ::Yng::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YNG_CORE_FATAL(...) ::Yng::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log Macros
#define YNG_ERROR(...) ::Yng::Log::GetClientLogger()->error(__VA_ARGS__)
#define YNG_INFO(...) ::Yng::Log::GetClientLogger()->info(__VA_ARGS__)
#define YNG_TRACE(...) ::Yng::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YNG_WARN(...) ::Yng::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YNG_FATAL(...) ::Yng::Log::GetClientLogger()->fatal(__VA_ARGS__)