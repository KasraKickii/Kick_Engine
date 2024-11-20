#pragma once

#include "CustomTypeIds.h"

class CustomDebugDrawComponent : public Kick_Engine::Component
{
public:
	SET_TYPE_ID(CustomComponentId::CustomDebugDraw);

	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Deserialize(const rapidjson::Value& value) override;

	void AddDebugDraw();

private:
	const Kick_Engine::TransformComponent* mTransformComponent = nullptr;
	Kick_Engine::Math::Vector3 mPosition = Kick_Engine::Math::Vector3::Zero;
	Kick_Engine::Color mColor = Kick_Engine::Colors::White;
	uint32_t mSlices = 0;
	uint32_t mRings = 0;
	float mRadius = 0.0f;
};