#ifndef __PHYSICS_ENGINE__
#define __PHYSICS_ENGINE__

#include <iostream>
#include <vector>
#include <sys/time.h>

#include <Physics/Rigidbody.hpp>
#include <Math/Vector2.hpp>

namespace sge{
	class PhysicsEngine{
		protected:
			std::vector<Rigidbody*>rigidbodies;

			Vector2 gravity_vector{0, 0.9f};

			timeval time_last_frame;
			float delta_time{0};
		public:
			PhysicsEngine(){
				gettimeofday(&this->time_last_frame, NULL);
			}

			const Vector2 getGravity() const;
			void setGravity(const Vector2 gravity_vector);

			void addRigidbody(Rigidbody* rigidbody);

			void updatePhysics();
	};
}
#endif
