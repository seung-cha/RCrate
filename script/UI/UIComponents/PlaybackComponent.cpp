#include "UIComponent.h"


namespace UIComponent
{
	class PlaybackComponent : public UIComponent
	{
	public:
		void DrawComponent() override
		{
			ImGui::Button("Play", ImVec2(30, 30));

		}
	};

}