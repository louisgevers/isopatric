#ifndef ISOPATRIC_EVENT_KEYEVENT_H
#define ISOPATRIC_EVENT_KEYEVENT_H

#include "Event.h"

#include <isopatric/input/KeyCode.h>

#include <utility>

namespace isopatric::event
{
	class KeyEvent : public Event
	{
	 public:
		input::KeyCode getKeyCode() { return mKeyCode; }

		EVENT_CLASS_CATEGORIES(EventCategoryInput | EventCategoryKeyboard)
	 protected:
		KeyEvent(input::KeyCode keyCode) : mKeyCode(keyCode) {}
		input::KeyCode mKeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	 public:
		KeyPressedEvent(input::KeyCode keyCode, bool isRepeat)
			: KeyEvent(keyCode), mIsRepeat(isRepeat) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << mKeyCode << " (repeat = " << mIsRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	 private:
		int mIsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	 public:
		KeyReleasedEvent(input::KeyCode keyCode)
			: KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyInputEvent : public Event
	{
	 public:
		KeyInputEvent(const char* input) : mInput(input) {}

		const char* getInput() const
		{
			return mInput;
		}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyInput: " << mInput;
			return ss.str();
		}

		EVENT_CLASS_CATEGORIES(EventCategoryInput | EventCategoryKeyboard)
		EVENT_CLASS_TYPE(KeyInput)
	 private:
		const char* mInput;
	};
}

#endif // ISOPATRIC_EVENT_KEYEVENT_H
