#pragma once

#include <memory>


#include "Core.h"
#include "spdlog/spdlog.h"


namespace Astronomy {
	
	class ASTRO_API Log {
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> EngineLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;

	};

}


// Engine Logging Macros
#ifdef ASTRO_ENABLE_ENGINE_LOG
	#define ASTRO_ENGINE_INFO(...)	::Astronomy::Log::GetEngineLogger()->info(__VA_ARGS__)
	#define ASTRO_ENGINE_TRACE(...) ::Astronomy::Log::GetEngineLogger()->trace(__VA_ARGS__)
	#define ASTRO_ENGINE_WARN(...)	::Astronomy::Log::GetEngineLogger()->warn(__VA_ARGS__)
	#define ASTRO_ENGINE_ERROR(...) ::Astronomy::Log::GetEngineLogger()->error(__VA_ARGS__)
	#define ASTRO_ENGINE_FATAL(...) ::Astronomy::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#else
	// If disabled, map macro to nothing as to not break everything
	#define ASTRO_ENGINE_INFO
	#define ASTRO_ENGINE_TRACE
	#define ASTRO_ENGINE_WARN
	#define ASTRO_ENGINE_ERROR
	#define ASTRO_ENGINE_FATAL

#endif // ASTRO_ENABLE_ENGINE_LOG


// Client Logging Macros
#ifdef ASTRO_ENABLE_CLIENT_LOG
	#define ASTRO_CLIENT_INFO(...)	::Astronomy::Log::GetClientLogger()->info(__VA_ARGS__)
	#define ASTRO_CLIENT_TRACE(...) ::Astronomy::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define ASTRO_CLIENT_WARN(...)	::Astronomy::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define ASTRO_CLIENT_ERROR(...) ::Astronomy::Log::GetClientLogger()->error(__VA_ARGS__)
	#define ASTRO_CLIENT_FATAL(...) ::Astronomy::Log::GetClientLogger()->fatal(__VA_ARGS__)

#else
	// Same as Engine logs
	#define ASTRO_CLIENT_INFO
	#define ASTRO_CLIENT_TRACE
	#define ASTRO_CLIENT_WARN
	#define ASTRO_CLIENT_ERROR
	#define ASTRO_CLIENT_FATAL

#endif // ASTRO_ENABLE_CLIENT_LOG










