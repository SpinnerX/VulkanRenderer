#include <VulkanRenderer/Core/EntryPoint.h>
#include <VulkanRenderer/Core/Application.h>

class MyApplication : public VulkanRenderer::Application{
public:
    MyApplication(VulkanRenderer::ApplicationCommandLineArgs args) : VulkanRenderer::Application(){
        
    }
};

namespace VulkanRenderer{
    Application* CreateApplication(const ApplicationCommandLineArgs& args){
        return new MyApplication(args);
    }
};