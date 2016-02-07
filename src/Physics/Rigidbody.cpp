#include <Physics/Rigidbody.hpp>

void Rigidbody::setStatic(const bool static_mode){
	this->static_mode = static_mode;
}

const bool Rigidbody::isStatic() const{
	return this->static_mode;
}

void Rigidbody::setGravityMultiplier(const float gravity_multiplier){
	this->gravity_multiplier = gravity_multiplier;
}

const float Rigidbody::getGravityMultiplier() const{
	return this->gravity_multiplier;
}

void Rigidbody::setGrounded(const bool grounded){
	this->is_grounded = grounded;
}

const bool Rigidbody::isGrounded() const{
	return this->is_grounded;
}

void Rigidbody::setPosition(const Vector3 position){
	this->position = position;
}

const Vector3 Rigidbody::getPosition() const{
	return this->position;
}

void Rigidbody::setVelocity(const Vector2 velocity){
	this->velocity = velocity;
}

Vector2 Rigidbody::getVelocity() const{
	return this->velocity;
}

void Rigidbody::updateComponent(GameObject& g_object){
	g_object.setPosition(this->position);
}
