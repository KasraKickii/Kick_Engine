#include "Precompiled.h"
#include "AnimatorComponent.h"

#include "GameObject.h"
#include "ModelComponent.h"

using namespace Kick_Engine;
using namespace Kick_Engine::Graphics;

void AnimatorComponent::Initialize()
{	 
	ModelComponent* modelComponent = GetOwner().GetComponent<ModelComponent>();
	mAnimator.Initialize(modelComponent->GetModelId());
}	 
	 
void AnimatorComponent::Terminate()
{	 
	//nothing
}	 
	 
void AnimatorComponent::Update(float deltaTime)
{	 
	mAnimator.Update(deltaTime);
}	 
	 
void AnimatorComponent::DebugUI()
{	 
	std::string buttonTag = "PlayAnim";
	uint32_t animationCount = mAnimator.GetAnimationCount();
	for (uint32_t i = 0; i < animationCount; ++i)
	{
		std::string buttonName = buttonTag + std::to_string(i);
		if (ImGui::Button(buttonName.c_str()))
		{
			Play(i, true);
		}
	}
}	 
	 
bool AnimatorComponent::Play(int index, bool looping)
{
	mAnimator.PlayAnimation(index, looping);
	return true;
}

void AnimatorComponent::Serialize(rapidjson::Document& doc, rapidjson::Value& value)
{
	rapidjson::Value componentValue(rapidjson::kObjectType);
	value.AddMember("AnimatorComponent", componentValue, doc.GetAllocator());
}
