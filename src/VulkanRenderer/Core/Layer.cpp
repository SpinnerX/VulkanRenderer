#include <VulkanRenderer/Core/Layer.h>


namespace VulkanRenderer{
    Layer::Layer(const std::string& name) : _debugName(name){}

    Layer::~Layer(){}
};