#pragma once
#include "ConstantBuffer.h"
#include "Sampler.h"
#include "GrassShader.h"
#include "PixelShader_D3D11.h"
#include "TextureManager.h"
#include "BlendState.h"
#include "Colours.h"

namespace Kick_Engine::Graphics
{
	class Camera;

	class GrassEffect
	{
	public:
		void Initialize(const std::filesystem::path& filename);
		void Terminate();

		void Update(float deltaTime);
		void Begin();
		void End();
		void SetCamera(const Camera& camera);
		void SetGrassTextureID(TextureID id);
		void DebugUI();

	private:
		struct TransformData
		{
			Math::Matrix4 wvp;
			Math::Vector3 cameraPos;
			float padding;
		};

		struct ColorData
		{
			Kick_Engine::Color albedo1Colour;
			Kick_Engine::Color albedo2Colour;
			Kick_Engine::Color AOColour;
			Kick_Engine::Color tipColour;
			Kick_Engine::Color fogColour;
			float fogDensity;
			float fogOffset;
			float padding[2] = { 0.0f };
		};

		struct TimeData
		{
			float time;
			float padding[3] = { 0.0f };
		};

		using TransformBuffer = TypedConstantBuffer<TransformData>;
		using ColorBuffer = TypedConstantBuffer<ColorData>;
		using TimeBuffer = TypedConstantBuffer<TimeData>;

		TransformBuffer mTransformBuffer;
		ColorBuffer mColorBuffer;
		TimeBuffer mTimeBuffer;

		Sampler mSampler;
		GrassVertexShader mVertexShader;
		PixelShader_D3D11 mPixelShader;

		TextureID mGrassTextureId;

		const Camera* mCamera = nullptr;
		ColorData mColorData;
		float mCurrentTime;
	};
}