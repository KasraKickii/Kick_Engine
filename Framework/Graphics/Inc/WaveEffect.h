#pragma once
#include "ConstantBuffer.h"
#include "StructuredBuffer.h"
#include "VertexShader_D3D11.h"
#include "PixelShader_D3D11.h"
#include "Colours.h"

namespace Kick_Engine::Graphics
{
	class Camera;
	struct RenderObject;
	struct DirectionalLight;

	struct WaveData
	{
		Math::Vector2 direction;
		Math::Vector2 origin;
		float frequency;
		float amplitude;
		float phase;
		float steepness;
	};

	class WaveEffect
	{
	public:
		void Initialize(const std::filesystem::path& filename);
		void InitializeWaves(std::vector<WaveData> data);
		void Terminate();

		void AddWave(WaveData data);

		void Update(float deltaTime);
		void Begin(); 
		void Render(const RenderObject& renderObject);
		void End();
		void SetCamera(const Camera& camera);
		void SetDirectionalLight(const DirectionalLight& light);
		void DebugUI();

	private:
		struct TransformData
		{
			Math::Matrix4 wvp;
			Math::Matrix4 worldMatrix;
			Math::Vector3 lightDirection;
			Math::Vector3 cameraPos;
			float padding[2] = { 0.0f };
		};

		struct SettingsData
		{
			float normalStrength = 1.0f;
			Math::Vector3 diffuseReflectance = { 1.0f, 1.0f, 5.0f };
		};

		struct TimeData
		{
			float time;
			float padding[3] = { 0.0f };
		};

		struct OceanData
		{
			int waveCount;
			float padding[3] = { 0.0f };
		};

		using TransformBuffer = TypedConstantBuffer<TransformData>;
		using SettingsBuffer = TypedConstantBuffer<SettingsData>;
		using TimeBuffer = TypedConstantBuffer<TimeData>;
		using OceanBuffer = TypedConstantBuffer<OceanData>;
		using WaveBuffer = TypedStructuredBuffer<WaveData>;

		TransformBuffer mTransformBuffer;
		SettingsBuffer m_SettingsBuffer;
		TimeBuffer mTimeBuffer;
		OceanBuffer mOceanBuffer;
		WaveBuffer mWaveBuffer;

		VertexShader_D3D11 mVertexShader;
		PixelShader_D3D11 mPixelShader;

		const Camera* mCamera = nullptr;
		const DirectionalLight* m_DirectionalLight = nullptr;

		SettingsData m_SettingsData;

		float mCurrentTime = 0.0f;
		int mWaveCount = 0;
		std::vector<WaveData> mWaves;
	};
}