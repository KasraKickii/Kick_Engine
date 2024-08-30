#pragma once

namespace Kick_Engine::Physics
{
	class CollisionShape final
	{
	public:
		CollisionShape() = default;
		~CollisionShape();

		void InitializeSphere(float radius);
		void InitializeBox(const Kick_Engine::Math::Vector3& halfExtents);
		void InitializeHull(const Kick_Engine::Math::Vector3& halfExtents, const Kick_Engine::Math::Vector3& origin);
		void InitializeEmpty();
		void Terminate();

	private:
		btCollisionShape* mCollisionShape = nullptr;

		friend class RigidBody;
		btCollisionShape* GetCollisionShape() const { return mCollisionShape; }
	};
}