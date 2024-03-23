#include <VulkanRenderer/Core/EntryPoint.h>
#include <VulkanRenderer/Core/Application.h>
#include <VulkanRenderer/Core/RendererLogger.h>

// if we are on the Windows OS (since windows uses dll files)

// We move this entry point hhere
// How this is able to happen is because with __attribute__((visibility("default")))
// that allows us to create different entry points when creating game engines, and stuff

#ifdef ENGINE_PLATFORM_WINDOWS
  extern VulkanRenderer::Application* VulkanRenderer::CreateApplication();

  int main(int argc, char** argv){

      auto app = VulkanRenderer::CreateApplication();
      app->Run();
      delete app;
  }
#else
  extern VulkanRenderer::Application* VulkanRenderer::CreateApplication(const VulkanRenderer::ApplicationCommandLineArgs& args);

  int main(int argc, char** argv){
    VulkanRenderer::RendererLogger::Init(); 
    auto app = VulkanRenderer::CreateApplication({argc, argv});
    app->Run();
    delete app;
}
#endif