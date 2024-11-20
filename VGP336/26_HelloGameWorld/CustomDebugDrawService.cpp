#include "CustomDebugDrawService.h"

#include "CustomDebugDrawComponent.h"

using namespace Kick_Engine;
using namespace Kick_Engine::Graphics;
using namespace Kick_Engine::Math;

void CustomDebugDrawService::Render()
{
	if (!mIsEnabled)
	{
		return;
	}

	for (CustomDebugDrawComponent* component : mCustomDebugDrawComponents)
	{
		component->AddDebugDraw();
	}
}

void CustomDebugDrawService::Register(CustomDebugDrawComponent* component)
{
	auto iter = std::find(mCustomDebugDrawComponents.begin(), mCustomDebugDrawComponents.end(), component);
	if (iter == mCustomDebugDrawComponents.end())
	{
		mCustomDebugDrawComponents.push_back(component);
	}
}

void CustomDebugDrawService::Unregister(CustomDebugDrawComponent* component)
{
	auto iter = std::find(mCustomDebugDrawComponents.begin(), mCustomDebugDrawComponents.end(), component);
	if (iter != mCustomDebugDrawComponents.end())
	{
		mCustomDebugDrawComponents.erase(iter);
	}
}


void CustomDebugDrawService::DebugUI()
{
	ImGui::Checkbox("Debug Draw", &mIsEnabled);
}
