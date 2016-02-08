#ifndef __COLLISION_ENGINE__
#define __COLLISION_ENGINE__

#include <iostream>
#include <vector>

#include <Physics/Collider/RectCollider.hpp>
#include <Physics/Rigidbody.hpp>
#include <Math/Vector2.hpp>

namespace sge{
	class CollisionEngine{
		protected:
			std::vector<RectCollider*> colliders;	///TODO: Abstract Collider

		public:
			CollisionEngine() = default;

			void updateCollisions();

			void addCollider(RectCollider* collider);

			static const bool boundingBoxCollision(RectCollider* r1, RectCollider* r2);
	};
}
#endif
