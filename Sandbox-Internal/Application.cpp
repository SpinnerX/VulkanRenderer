#include <VulkanRenderer/Core/EntryPoint.h>
#include <VulkanRenderer/Core/Application.h>
#include <VulkanRenderer/Core/Layer.h>
#include <VulkanRenderer/Events/InputPoll.h>
#include <VulkanRenderer/Events/KeyCodes.h>

class ExampleLayer : public VulkanRenderer::Layer{
public:
	void onAttach() override{}

	void onDetach() override{}

	void onUpdate(VulkanRenderer::Timestep ts) override {
		coreLogInfo("Updating called!");
	}

	void onEvent(VulkanRenderer::Event& e) override{
		if(VulkanRenderer::InputPoll::isKeyPressed(ENGINE_KEY_ESCAPE)){
			coreLogInfo("Running onEvent()!");
			VulkanRenderer::Application::Get().close();
		}
	}
};


class MyApplication : public VulkanRenderer::Application{
public:
    MyApplication(VulkanRenderer::ApplicationCommandLineArgs args) : VulkanRenderer::Application(){
       pushLayer(new ExampleLayer()) ;
    }
};

namespace VulkanRenderer{
    Application* CreateApplication(const ApplicationCommandLineArgs& args){
        return new MyApplication(args);
    }
};
