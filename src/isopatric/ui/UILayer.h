#ifndef ISOPATRIC_ISOPATRIC_UI_UILAYER_H
#define ISOPATRIC_ISOPATRIC_UI_UILAYER_H

#include <isopatric/core/Layer.h>

namespace isopatric::ui
{
	class UILayer : public core::Layer
	{
	 public:
		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(event::Event& event) override;
	 private:
		float mTime = 0.0f;
	};
}

#endif //ISOPATRIC_ISOPATRIC_UI_UILAYER_H
