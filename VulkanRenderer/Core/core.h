#pragma once
#include <type_traits>
#include <memory>

// if we are on the Windows OS (since windows uses dll files)
#ifdef ENGINE_PLATFORM_WINDOWS
    #ifdef ENGINE_BUILD_DLL
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else // If we are on either Linux/Mac OS, since they use __attributes__
    #define ENGINE_API __attribute__((visibility("default")))
#endif

// Hence, why we are using a bitfield.
constexpr uint64_t bit(uint64_t x){
    return (1 << x);
}

namespace VulkanRenderer{
    static auto bind_function(auto* instance, auto member_bound_function){
        return [instance, member_bound_function](auto&& arg1){
            return (instance->*member_bound_function)(std::forward<decltype(arg1)>(arg1));
        };
    }

    /**
     * @brief 
     * 
     * @note Scope - because std::unique_ptr means that the type we pass will only live in the lifetime of its declaration
     * @tparam T (template) - takes a typename as template arg
	 *
	 * NOTE: Using Scope<T> because of potential memory leakages in the codebase
     */
    template<typename T>
    using Scope = std::unique_ptr<T>;
	
	template<typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args&&... args){
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

    /**
     * @brief 
     * 
     * @note Ref - is shared ptr that allows an object to live both inside and other areas the objects is used  (in terms of lifetime)
     * 
     * @tparam T 
     */

    template<typename T>
    using Ref = std::shared_ptr<T>;

	template<typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args&&... args){
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
};