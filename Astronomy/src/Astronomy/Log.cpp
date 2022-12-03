#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"



namespace Astronomy {

	std::shared_ptr<spdlog::logger> Log::EngineLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;


	void Log::Initialize() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		EngineLogger = spdlog::stdout_color_mt("ASTRONOMY");
		EngineLogger->set_level(spdlog::level::trace);

		ClientLogger = spdlog::stdout_color_mt("CLIENT");
		ClientLogger->set_level(spdlog::level::trace);

	}


}