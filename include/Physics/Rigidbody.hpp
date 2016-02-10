#ifndef __RIGIDBODY__
#define __RIGIDBODY__

#include <Components/Component.hpp>
#include <GameObject/GameObject.hpp>
#include <Physics/Collider/RectCollider.hpp>
#include <Math/Vector2.hpp>

namespace sge{
	class Rigidbody : public Component{
		protected:
			Vector3 position{0, 0, 0};
			Vector2 velocity{0, 0};

			bool static_mode{false};
			bool is_grounded{false};

			float gravity_multiplier{1};
		public:
			Rigidbody() = default;

			Rigidbody(GameObject &g_object){
				this->position.x = g_object.getPosition().x;
				this->position.y = g_object.getPosition().y;
				this->position.z = g_object.getPosition().z;
			}

			void setStatic(const bool static_mode);
			const bool isStatic() const;

			void setGravityMultiplier(const float gravity_multiplier);
			const float getGravityMultiplier() const;

			void setGrounded(const bool grounded);
			const bool isGrounded() const;

			void setPosition(const Vector3 position);
			const Vector3 getPosition() const;

			void setVelocity(const Vector2 velocity);
			Vector2 getVelocity() const;

			void updateComponent();
	};
}
#endif
