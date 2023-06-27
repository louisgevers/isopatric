#include "Input.h"

#include <SDL.h>
#include <isopatric/input/Input.h>

namespace isopatric::input
{
	Scope<Input> Input::create()
	{
		return isopatric::createScope<SDLInput>();
	}

	SDLInput::~SDLInput() = default;

	bool SDLInput::isKeyPressed(KeyCode keyCode) const
	{
		auto keyboardState = SDL_GetKeyboardState(nullptr);
		int sdlKeyCode = keyCodeToSDL(keyCode);
		return keyboardState[sdlKeyCode];
	}

	bool SDLInput::isMouseButtonPressed(MouseCode mouseButton) const
	{
		auto mouseState = SDL_GetMouseState(nullptr, nullptr);
		int sdlMouseCode = mouseCodeToSDL(mouseButton);
		return mouseState & SDL_BUTTON(sdlMouseCode);
	}

	int SDLInput::getMouseX() const
	{
		int x = 0;
		SDL_GetMouseState(&x, nullptr);
		return x;
	}

	int SDLInput::getMouseY() const
	{
		int y = 0;
		SDL_GetMouseState(nullptr, &y);
		return y;
	}

	std::pair<int, int> SDLInput::getMousePosition() const
	{
		int x, y = 0;
		SDL_GetMouseState(&x, &y);
		return std::make_pair(x, y);
	}

	KeyCode keyCodeFromSDL(int keyCode)
	{
		switch (keyCode)
		{
		case SDLK_TAB:
			return Tab;
		case SDLK_LEFT:
			return LeftArrow;
		case SDLK_RIGHT:
			return RightArrow;
		case SDLK_UP:
			return UpArrow;
		case SDLK_DOWN:
			return DownArrow;
		case SDLK_PAGEUP:
			return PageUp;
		case SDLK_PAGEDOWN:
			return PageDown;
		case SDLK_HOME:
			return Home;
		case SDLK_END:
			return End;
		case SDLK_INSERT:
			return Insert;
		case SDLK_DELETE:
			return Delete;
		case SDLK_BACKSPACE:
			return Backspace;
		case SDLK_SPACE:
			return Space;
		case SDLK_RETURN:
			return Enter;
		case SDLK_ESCAPE:
			return Escape;
		case SDLK_QUOTE:
			return Apostrophe;
		case SDLK_COMMA:
			return Comma;
		case SDLK_MINUS:
			return Minus;
		case SDLK_PERIOD:
			return Period;
		case SDLK_SLASH:
			return Slash;
		case SDLK_SEMICOLON:
			return Semicolon;
		case SDLK_EQUALS:
			return Equal;
		case SDLK_LEFTBRACKET:
			return LeftBracket;
		case SDLK_BACKSLASH:
			return Backslash;
		case SDLK_RIGHTBRACKET:
			return RightBracket;
		case SDLK_BACKQUOTE:
			return GraveAccent;
		case SDLK_CAPSLOCK:
			return CapsLock;
		case SDLK_SCROLLLOCK:
			return ScrollLock;
		case SDLK_NUMLOCKCLEAR:
			return NumLock;
		case SDLK_PRINTSCREEN:
			return PrintScreen;
		case SDLK_PAUSE:
			return Pause;
		case SDLK_KP_0:
			return Keypad0;
		case SDLK_KP_1:
			return Keypad1;
		case SDLK_KP_2:
			return Keypad2;
		case SDLK_KP_3:
			return Keypad3;
		case SDLK_KP_4:
			return Keypad4;
		case SDLK_KP_5:
			return Keypad5;
		case SDLK_KP_6:
			return Keypad6;
		case SDLK_KP_7:
			return Keypad7;
		case SDLK_KP_8:
			return Keypad8;
		case SDLK_KP_9:
			return Keypad9;
		case SDLK_KP_PERIOD:
			return KeypadDecimal;
		case SDLK_KP_DIVIDE:
			return KeypadDivide;
		case SDLK_KP_MULTIPLY:
			return KeypadMultiply;
		case SDLK_KP_MINUS:
			return KeypadSubtract;
		case SDLK_KP_PLUS:
			return KeypadAdd;
		case SDLK_KP_ENTER:
			return KeypadEnter;
		case SDLK_KP_EQUALS:
			return KeypadEqual;
		case SDLK_LCTRL:
			return LeftCtrl;
		case SDLK_LSHIFT:
			return LeftShift;
		case SDLK_LALT:
			return LeftAlt;
		case SDLK_LGUI:
			return LeftSuper;
		case SDLK_RCTRL:
			return RightCtrl;
		case SDLK_RSHIFT:
			return RightShift;
		case SDLK_RALT:
			return RightAlt;
		case SDLK_RGUI:
			return RightSuper;
		case SDLK_APPLICATION:
			return Menu;
		case SDLK_0:
			return D0;
		case SDLK_1:
			return D1;
		case SDLK_2:
			return D2;
		case SDLK_3:
			return D3;
		case SDLK_4:
			return D4;
		case SDLK_5:
			return D5;
		case SDLK_6:
			return D6;
		case SDLK_7:
			return D7;
		case SDLK_8:
			return D8;
		case SDLK_9:
			return D9;
		case SDLK_a:
			return A;
		case SDLK_b:
			return B;
		case SDLK_c:
			return C;
		case SDLK_d:
			return D;
		case SDLK_e:
			return E;
		case SDLK_f:
			return F;
		case SDLK_g:
			return G;
		case SDLK_h:
			return H;
		case SDLK_i:
			return I;
		case SDLK_j:
			return J;
		case SDLK_k:
			return K;
		case SDLK_l:
			return L;
		case SDLK_m:
			return M;
		case SDLK_n:
			return N;
		case SDLK_o:
			return O;
		case SDLK_p:
			return P;
		case SDLK_q:
			return Q;
		case SDLK_r:
			return R;
		case SDLK_s:
			return S;
		case SDLK_t:
			return T;
		case SDLK_u:
			return U;
		case SDLK_v:
			return V;
		case SDLK_w:
			return W;
		case SDLK_x:
			return X;
		case SDLK_y:
			return Y;
		case SDLK_z:
			return Z;
		case SDLK_F1:
			return F1;
		case SDLK_F2:
			return F2;
		case SDLK_F3:
			return F3;
		case SDLK_F4:
			return F4;
		case SDLK_F5:
			return F5;
		case SDLK_F6:
			return F6;
		case SDLK_F7:
			return F7;
		case SDLK_F8:
			return F8;
		case SDLK_F9:
			return F9;
		case SDLK_F10:
			return F10;
		case SDLK_F11:
			return F11;
		case SDLK_F12:
			return F12;
		}
		return None;
	}

	int keyCodeToSDL(KeyCode keyCode)
	{
		switch (keyCode)
		{
		case Tab:
			return SDLK_TAB;
		case LeftArrow:
			return SDLK_LEFT;
		case RightArrow:
			return SDLK_RIGHT;
		case UpArrow:
			return SDLK_UP;
		case DownArrow:
			return SDLK_DOWN;
		case PageUp:
			return SDLK_PAGEUP;
		case PageDown:
			return SDLK_PAGEDOWN;
		case Home:
			return SDLK_HOME;
		case End:
			return SDLK_END;
		case Insert:
			return SDLK_INSERT;
		case Delete:
			return SDLK_DELETE;
		case Backspace:
			return SDLK_BACKSPACE;
		case Space:
			return SDLK_SPACE;
		case Enter:
			return SDLK_RETURN;
		case Escape:
			return SDLK_ESCAPE;
		case Apostrophe:
			return SDLK_QUOTE;
		case Comma:
			return SDLK_COMMA;
		case Minus:
			return SDLK_MINUS;
		case Period:
			return SDLK_PERIOD;
		case Slash:
			return SDLK_SLASH;
		case Semicolon:
			return SDLK_SEMICOLON;
		case Equal:
			return SDLK_EQUALS;
		case LeftBracket:
			return SDLK_LEFTBRACKET;
		case Backslash:
			return SDLK_BACKSLASH;
		case RightBracket:
			return SDLK_RIGHTBRACKET;
		case GraveAccent:
			return SDLK_BACKQUOTE;
		case CapsLock:
			return SDLK_CAPSLOCK;
		case ScrollLock:
			return SDLK_SCROLLLOCK;
		case NumLock:
			return SDLK_NUMLOCKCLEAR;
		case PrintScreen:
			return SDLK_PRINTSCREEN;
		case Pause:
			return SDLK_PAUSE;
		case Keypad0:
			return SDLK_KP_0;
		case Keypad1:
			return SDLK_KP_1;
		case Keypad2:
			return SDLK_KP_2;
		case Keypad3:
			return SDLK_KP_3;
		case Keypad4:
			return SDLK_KP_4;
		case Keypad5:
			return SDLK_KP_5;
		case Keypad6:
			return SDLK_KP_6;
		case Keypad7:
			return SDLK_KP_7;
		case Keypad8:
			return SDLK_KP_8;
		case Keypad9:
			return SDLK_KP_9;
		case KeypadDecimal:
			return SDLK_KP_PERIOD;
		case KeypadDivide:
			return SDLK_KP_DIVIDE;
		case KeypadMultiply:
			return SDLK_KP_MULTIPLY;
		case KeypadSubtract:
			return SDLK_KP_MINUS;
		case KeypadAdd:
			return SDLK_KP_PLUS;
		case KeypadEnter:
			return SDLK_KP_ENTER;
		case KeypadEqual:
			return SDLK_KP_EQUALS;
		case LeftCtrl:
			return SDLK_LCTRL;
		case LeftShift:
			return SDLK_LSHIFT;
		case LeftAlt:
			return SDLK_LALT;
		case LeftSuper:
			return SDLK_LGUI;
		case RightCtrl:
			return SDLK_RCTRL;
		case RightShift:
			return SDLK_RSHIFT;
		case RightAlt:
			return SDLK_RALT;
		case RightSuper:
			return SDLK_RGUI;
		case Menu:
			return SDLK_APPLICATION;
		case D0:
			return SDLK_0;
		case D1:
			return SDLK_1;
		case D2:
			return SDLK_2;
		case D3:
			return SDLK_3;
		case D4:
			return SDLK_4;
		case D5:
			return SDLK_5;
		case D6:
			return SDLK_6;
		case D7:
			return SDLK_7;
		case D8:
			return SDLK_8;
		case D9:
			return SDLK_9;
		case A:
			return SDLK_a;
		case B:
			return SDLK_b;
		case C:
			return SDLK_c;
		case D:
			return SDLK_d;
		case E:
			return SDLK_e;
		case F:
			return SDLK_f;
		case G:
			return SDLK_g;
		case H:
			return SDLK_h;
		case I:
			return SDLK_i;
		case J:
			return SDLK_j;
		case K:
			return SDLK_k;
		case L:
			return SDLK_l;
		case M:
			return SDLK_m;
		case N:
			return SDLK_n;
		case O:
			return SDLK_o;
		case P:
			return SDLK_p;
		case Q:
			return SDLK_q;
		case R:
			return SDLK_r;
		case S:
			return SDLK_s;
		case T:
			return SDLK_t;
		case U:
			return SDLK_u;
		case V:
			return SDLK_v;
		case W:
			return SDLK_w;
		case X:
			return SDLK_x;
		case Y:
			return SDLK_y;
		case Z:
			return SDLK_z;
		case F1:
			return SDLK_F1;
		case F2:
			return SDLK_F2;
		case F3:
			return SDLK_F3;
		case F4:
			return SDLK_F4;
		case F5:
			return SDLK_F5;
		case F6:
			return SDLK_F6;
		case F7:
			return SDLK_F7;
		case F8:
			return SDLK_F8;
		case F9:
			return SDLK_F9;
		case F10:
			return SDLK_F10;
		case F11:
			return SDLK_F11;
		case F12:
			return SDLK_F12;
		case None:
			return SDLK_UNKNOWN;
		}

		return SDLK_UNKNOWN;
	}

	MouseCode mouseCodeFromSDL(int mouseCode)
	{
		switch (mouseCode)
		{
		case SDL_BUTTON_LEFT:
			return MouseLeft;
		case SDL_BUTTON_RIGHT:
			return MouseRight;
		case SDL_BUTTON_MIDDLE:
			return MouseMiddle;
		case SDL_BUTTON_X1:
			return MouseX1;
		case SDL_BUTTON_X2:
			return MouseX2;
		}
		return MouseUnknown;
	}

	int mouseCodeToSDL(MouseCode mouseCode)
	{
		switch (mouseCode)
		{
		case MouseLeft:
			return SDL_BUTTON_LEFT;
		case MouseRight:
			return SDL_BUTTON_RIGHT;
		case MouseMiddle:
			return SDL_BUTTON_MIDDLE;
		case MouseX1:
			return SDL_BUTTON_X1;
		case MouseX2:
			return SDL_BUTTON_X2;
		case MouseUnknown:
			return -1;
		}
		return -1;
	}
}