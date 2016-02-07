#include <Physics/PhysicsEngine.hpp>

#include <iostream>

const Vector2 PhysicsEngine::getGravity() const{
	return this->gravity_vector;
}

void PhysicsEngine::setGravity(const Vector2 gravity_vector){
	this->gravity_vector = gravity_vector;
}

void PhysicsEngine::addRigidbody(Rigidbody* rigidbody){
	this->rigidbodies.push_back(rigidbody);
}

void PhysicsEngine::updatePhysics(){
	timeval current_time;
	gettimeofday(&current_time, NULL);

	this->delta_time = ((current_time.tv_sec - this->time_last_frame.tv_sec) * 1000) + ((current_time.tv_usec - this->time_last_frame.tv_usec) / 1000) / 1000;

	if(this->delta_time > 0.15f){
		this->delta_time = 0.15f;
	}

	for(Rigidbody* rigidbody : this->rigidbodies){
		if(!rigidbody->isStatic() && !rigidbody->isGrounded()){	//Apply Gravity TODO: ADD BOOL USEGRAVITY
			float x = rigidbody->getPosition().x;	///TODO: Vector arithmetic use
			float y = rigidbody->getPosition().y;


			float velocity_x = rigidbody->getVelocity().x;
			float velocity_y = rigidbody->getVelocity().y;

			x += velocity_x * this->delta_time;
			y += velocity_y * this->delta_time;

			velocity_x += this->delta_time * this->gravity_vector.x;
			velocity_y += this->delta_time * this->gravity_vector.y;

			rigidbody->setVelocity(Vector2(velocity_x, velocity_y));
			rigidbody->setPosition(Vector3(x, y, rigidbody->getPosition().z));
		}
	}
}
