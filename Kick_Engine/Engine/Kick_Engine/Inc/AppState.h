#pragma once

namespace Kick_Engine
{
	class AppState
	{
	public:
		virtual ~AppState() = default;
		virtual void Initialize() {}
		virtual void Terminate() {}
		virtual void Update(float deltaTime) {}
		virtual void DebugUI() {}
	};
}