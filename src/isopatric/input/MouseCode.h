#ifndef ISOPATRIC_SRC_ISOPATRIC_INPUT_MOUSECODE_H
#define ISOPATRIC_SRC_ISOPATRIC_INPUT_MOUSECODE_H

namespace isopatric::input
{
	enum MouseCode
	{
		// From imgui.h
		MouseLeft,
		MouseRight,
		MouseMiddle,
		MouseX1,
		MouseX2,
		MouseUnknown = -1,
	};
}

#endif //ISOPATRIC_SRC_ISOPATRIC_INPUT_MOUSECODE_H
