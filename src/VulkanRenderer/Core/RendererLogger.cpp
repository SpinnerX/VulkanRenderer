#include <VulkanRenderer/Core/RendererLogger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace VulkanRenderer{
    std::shared_ptr<spdlog::logger> RendererLogger::coreLogger;
    std::shared_ptr<spdlog::logger> RendererLogger::clientLogger;

    void RendererLogger::Init(){
        spdlog::set_pattern( "%^[%T - %n] %v%$");
        coreLogger = spdlog::stdout_color_mt("Renderer");
        coreLogger->set_level(spdlog::level::trace);

        clientLogger = spdlog::stdout_color_mt("Application");
        clientLogger->set_level(spdlog::level::trace);
    }

};