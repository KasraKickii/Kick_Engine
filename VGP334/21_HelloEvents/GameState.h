#pragma once
#include <../Kick_Engine/Inc/Kick_Engine.h>


class GameState : public Kick_Engine::AppState
{
public:
    ~GameState() = default;
    void Initialize() override;
    void Terminate() override;
    void Render() override;
    void Update(float deltaTime) override;
    void DebugUI() override;

private:
    void UpdateCameraControl(float deltaTime);

    void MoveRight();
    void OnSpacePressedEvent(const Kick_Engine::Event* event);

    Kick_Engine::Graphics::Camera mCamera;
    Kick_Engine::Graphics::DirectionalLight mDirectionalLight;
    Kick_Engine::Graphics::StandardEffect mStandardEffect;

    Kick_Engine::Graphics::RenderObject mBall;
    Kick_Engine::Graphics::RenderObject mGround;

    //animation
    Kick_Engine::Kick_Math::Vector3 mOffset = Kick_Engine::Kick_Math::Vector3::Zero;
    Kick_Engine::Graphics::Animation mAnimation;
    float mAnimationTime = 0.0f;
};