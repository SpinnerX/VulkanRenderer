#pragma once
#include <cstdint>

namespace VulkanRenderer{
	typedef enum class KeyCode : uint16_t {
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;
}

// From glfw3.h
#define ENGINE_KEY_SPACE           ::VulkanRenderer::Key::Space
#define ENGINE_KEY_APOSTROPHE      ::VulkanRenderer::Key::Apostrophe    /* ' */
#define ENGINE_KEY_COMMA           ::VulkanRenderer::Key::Comma         /* , */
#define ENGINE_KEY_MINUS           ::VulkanRenderer::Key::Minus         /* - */
#define ENGINE_KEY_PERIOD          ::VulkanRenderer::Key::Period        /* . */
#define ENGINE_KEY_SLASH           ::VulkanRenderer::Key::Slash         /* / */
#define ENGINE_KEY_0               ::VulkanRenderer::Key::D0
#define ENGINE_KEY_1               ::VulkanRenderer::Key::D1
#define ENGINE_KEY_2               ::VulkanRenderer::Key::D2
#define ENGINE_KEY_3               ::VulkanRenderer::Key::D3
#define ENGINE_KEY_4               ::VulkanRenderer::Key::D4
#define ENGINE_KEY_5               ::VulkanRenderer::Key::D5
#define ENGINE_KEY_6               ::VulkanRenderer::Key::D6
#define ENGINE_KEY_7               ::VulkanRenderer::Key::D7
#define ENGINE_KEY_8               ::VulkanRenderer::Key::D8
#define ENGINE_KEY_9               ::VulkanRenderer::Key::D9
#define ENGINE_KEY_SEMICOLON       ::VulkanRenderer::Key::Semicolon     /* ; */
#define ENGINE_KEY_EQUAL           ::VulkanRenderer::Key::Equal         /* = */
#define ENGINE_KEY_A               ::VulkanRenderer::Key::A
#define ENGINE_KEY_B               ::VulkanRenderer::Key::B
#define ENGINE_KEY_C               ::VulkanRenderer::Key::C
#define ENGINE_KEY_D               ::VulkanRenderer::Key::D
#define ENGINE_KEY_E               ::VulkanRenderer::Key::E
#define ENGINE_KEY_F               ::VulkanRenderer::Key::F
#define ENGINE_KEY_G               ::VulkanRenderer::Key::G
#define ENGINE_KEY_H               ::VulkanRenderer::Key::H
#define ENGINE_KEY_I               ::VulkanRenderer::Key::I
#define ENGINE_KEY_J               ::VulkanRenderer::Key::J
#define ENGINE_KEY_K               ::VulkanRenderer::Key::K
#define ENGINE_KEY_L               ::VulkanRenderer::Key::L
#define ENGINE_KEY_M               ::VulkanRenderer::Key::M
#define ENGINE_KEY_N               ::VulkanRenderer::Key::N
#define ENGINE_KEY_O               ::VulkanRenderer::Key::O
#define ENGINE_KEY_P               ::VulkanRenderer::Key::P
#define ENGINE_KEY_Q               ::VulkanRenderer::Key::Q
#define ENGINE_KEY_R               ::VulkanRenderer::Key::R
#define ENGINE_KEY_S               ::VulkanRenderer::Key::S
#define ENGINE_KEY_T               ::VulkanRenderer::Key::T
#define ENGINE_KEY_U               ::VulkanRenderer::Key::U
#define ENGINE_KEY_V               ::VulkanRenderer::Key::V
#define ENGINE_KEY_W               ::VulkanRenderer::Key::W
#define ENGINE_KEY_X               ::VulkanRenderer::Key::X
#define ENGINE_KEY_Y               ::VulkanRenderer::Key::Y
#define ENGINE_KEY_Z               ::VulkanRenderer::Key::Z
#define ENGINE_KEY_LEFT_BRACKET    ::VulkanRenderer::Key::LeftBracket   /* [ */
#define ENGINE_KEY_BACKSLASH       ::VulkanRenderer::Key::Backslash     /* \ */
#define ENGINE_KEY_RIGHT_BRACKET   ::VulkanRenderer::Key::RightBracket  /* ] */
#define ENGINE_KEY_GRAVE_ACCENT    ::VulkanRenderer::Key::GraveAccent   /* ` */
#define ENGINE_KEY_WORLD_1         ::VulkanRenderer::Key::World1        /* non-US #1 */
#define ENGINE_KEY_WORLD_2         ::VulkanRenderer::Key::World2        /* non-US #2 */

/* Function keys */
#define ENGINE_KEY_ESCAPE          ::VulkanRenderer::Key::Escape
#define ENGINE_KEY_ENTER           ::VulkanRenderer::Key::Enter
#define ENGINE_KEY_TAB             ::VulkanRenderer::Key::Tab
#define ENGINE_KEY_BACKSPACE       ::VulkanRenderer::Key::Backspace
#define ENGINE_KEY_INSERT          ::VulkanRenderer::Key::Insert
#define ENGINE_KEY_DELETE          ::VulkanRenderer::Key::Delete
#define ENGINE_KEY_RIGHT           ::VulkanRenderer::Key::Right
#define ENGINE_KEY_LEFT            ::VulkanRenderer::Key::Left
#define ENGINE_KEY_DOWN            ::VulkanRenderer::Key::Down
#define ENGINE_KEY_UP              ::VulkanRenderer::Key::Up
#define ENGINE_KEY_PAGE_UP         ::VulkanRenderer::Key::PageUp
#define ENGINE_KEY_PAGE_DOWN       ::VulkanRenderer::Key::PageDown
#define ENGINE_KEY_HOME            ::VulkanRenderer::Key::Home
#define ENGINE_KEY_END             ::VulkanRenderer::Key::End
#define ENGINE_KEY_CAPS_LOCK       ::VulkanRenderer::Key::CapsLock
#define ENGINE_KEY_SCROLL_LOCK     ::VulkanRenderer::Key::ScrollLock
#define ENGINE_KEY_NUM_LOCK        ::VulkanRenderer::Key::NumLock
#define ENGINE_KEY_PRINT_SCREEN    ::VulkanRenderer::Key::PrintScreen
#define ENGINE_KEY_PAUSE           ::VulkanRenderer::Key::Pause
#define ENGINE_KEY_F1              ::VulkanRenderer::Key::F1
#define ENGINE_KEY_F2              ::VulkanRenderer::Key::F2
#define ENGINE_KEY_F3              ::VulkanRenderer::Key::F3
#define ENGINE_KEY_F4              ::VulkanRenderer::Key::F4
#define ENGINE_KEY_F5              ::VulkanRenderer::Key::F5
#define ENGINE_KEY_F6              ::VulkanRenderer::Key::F6
#define ENGINE_KEY_F7              ::VulkanRenderer::Key::F7
#define ENGINE_KEY_F8              ::VulkanRenderer::Key::F8
#define ENGINE_KEY_F9              ::VulkanRenderer::Key::F9
#define ENGINE_KEY_F10             ::VulkanRenderer::Key::F10
#define ENGINE_KEY_F11             ::VulkanRenderer::Key::F11
#define ENGINE_KEY_F12             ::VulkanRenderer::Key::F12
#define ENGINE_KEY_F13             ::VulkanRenderer::Key::F13
#define ENGINE_KEY_F14             ::VulkanRenderer::Key::F14
#define ENGINE_KEY_F15             ::VulkanRenderer::Key::F15
#define ENGINE_KEY_F16             ::VulkanRenderer::Key::F16
#define ENGINE_KEY_F17             ::VulkanRenderer::Key::F17
#define ENGINE_KEY_F18             ::VulkanRenderer::Key::F18
#define ENGINE_KEY_F19             ::VulkanRenderer::Key::F19
#define ENGINE_KEY_F20             ::VulkanRenderer::Key::F20
#define ENGINE_KEY_F21             ::VulkanRenderer::Key::F21
#define ENGINE_KEY_F22             ::VulkanRenderer::Key::F22
#define ENGINE_KEY_F23             ::VulkanRenderer::Key::F23
#define ENGINE_KEY_F24             ::VulkanRenderer::Key::F24
#define ENGINE_KEY_F25             ::VulkanRenderer::Key::F25

/* Keypad */
#define ENGINE_KEY_KP_0            ::VulkanRenderer::Key::KP0
#define ENGINE_KEY_KP_1            ::VulkanRenderer::Key::KP1
#define ENGINE_KEY_KP_2            ::VulkanRenderer::Key::KP2
#define ENGINE_KEY_KP_3            ::VulkanRenderer::Key::KP3
#define ENGINE_KEY_KP_4            ::VulkanRenderer::Key::KP4
#define ENGINE_KEY_KP_5            ::VulkanRenderer::Key::KP5
#define ENGINE_KEY_KP_6            ::VulkanRenderer::Key::KP6
#define ENGINE_KEY_KP_7            ::VulkanRenderer::Key::KP7
#define ENGINE_KEY_KP_8            ::VulkanRenderer::Key::KP8
#define ENGINE_KEY_KP_9            ::VulkanRenderer::Key::KP9
#define ENGINE_KEY_KP_DECIMAL      ::VulkanRenderer::Key::KPDecimal
#define ENGINE_KEY_KP_DIVIDE       ::VulkanRenderer::Key::KPDivide
#define ENGINE_KEY_KP_MULTIPLY     ::VulkanRenderer::Key::KPMultiply
#define ENGINE_KEY_KP_SUBTRACT     ::VulkanRenderer::Key::KPSubtract
#define ENGINE_KEY_KP_ADD          ::VulkanRenderer::Key::KPAdd
#define ENGINE_KEY_KP_ENTER        ::VulkanRenderer::Key::KPEnter
#define ENGINE_KEY_KP_EQUAL        ::VulkanRenderer::Key::KPEqual

#define ENGINE_KEY_LEFT_SHIFT      ::VulkanRenderer::Key::LeftShift
#define ENGINE_KEY_LEFT_CONTROL    ::VulkanRenderer::Key::LeftControl
#define ENGINE_KEY_LEFT_ALT        ::VulkanRenderer::Key::LeftAlt
#define ENGINE_KEY_LEFT_SUPER      ::VulkanRenderer::Key::LeftSuper
#define ENGINE_KEY_RIGHT_SHIFT     ::VulkanRenderer::Key::RightShift
#define ENGINE_KEY_RIGHT_CONTROL   ::VulkanRenderer::Key::RightControl
#define ENGINE_KEY_RIGHT_ALT       ::VulkanRenderer::Key::RightAlt
#define ENGINE_KEY_RIGHT_SUPER     ::VulkanRenderer::Key::RightSuper
#define ENGINE_KEY_MENU            ::VulkanRenderer::Key::Menu