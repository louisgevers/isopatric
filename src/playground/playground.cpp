#include <isopatric/isopatric.h>

class PlayGround : public isopatric::core::Application
{
 public:
	PlayGround()
	{
		pushOverlay(new isopatric::ui::UILayer());
	}
};

isopatric::core::Application* isopatric::core::createApplication()
{
	return new PlayGround();
}