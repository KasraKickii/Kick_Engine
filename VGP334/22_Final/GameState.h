#pragma once
#include <Kick_Engine/Inc/Kick_Engine.h>

class GameState : public Kick_Engine::AppState
{
public:
	virtual void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Render() override;
	void DebugUI() override;

protected:
	void OnEvent2();
	void OnEvent3();

	void OnSpaceEvent(const Kick_Engine::Event* event);
	void OnAnimEvent(const Kick_Engine::Event* event);

	Kick_Engine::Graphics::DirectionalLight mDirectionalLight;
	Kick_Engine::Graphics::Camera mCamera;

	Kick_Engine::Graphics::ModelId mModelId;
	Kick_Engine::Graphics::RenderGroup mCharacter;
	Kick_Engine::Graphics::Animator mCharacterAnimator;
	Kick_Engine::Graphics::ModelId mModelId2;
	Kick_Engine::Graphics::RenderGroup mCharacter2;
	Kick_Engine::Graphics::Animator mCharacterAnimator2;
	Kick_Engine::Graphics::StandardEffect mStandardEffect;

	Kick_Engine::ListenerId mSpaceEventId = 0;
	Kick_Engine::ListenerId mAnimEventId = 0;

	std::vector<Kick_Engine::Audio::SoundId> mEventSoundIds;
	Kick_Engine::Graphics::Animation mEventAnimation;
	float mEventAnimationTime = 0.0f;

	int mAnimIndex = 1;
	bool mDrawSkeleton = false;
};