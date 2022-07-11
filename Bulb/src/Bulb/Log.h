#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Bulb {

	class BULB_API Log
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

// Core log macros
#define BLB_CORE_TRACE(...) ::Bulb::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BLB_CORE_INFO(...)	::Bulb::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BLB_CORE_WARN(...)	::Bulb::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BLB_CORE_ERROR(...) ::Bulb::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BLB_CORE_CRITICAL(...) ::Bulb::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BLB_TRACE(...)	::Bulb::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BLB_INFO(...)	::Bulb::Log::GetClientLogger()->info(__VA_ARGS__)
#define BLB_WARN(...)	::Bulb::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BLB_ERROR(...)	::Bulb::Log::GetClientLogger()->error(__VA_ARGS__)
#define BLB_CRITICAL(...)	::Bulb::Log::GetClientLogger()->critical(__VA_ARGS__)
