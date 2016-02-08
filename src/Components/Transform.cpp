#include <Components/Transform.hpp>

namespace sge{
	Transform::Transform(Vector3 position) : position(position){
	};

	Transform::Transform(Vector3 position, Vector2 scale) : position(position), scale(scale){
	};

	Transform::Transform(Vector3 position, Vector2 scale, double rotation) : position(position), scale(scale), rotation(rotation){
	};

	void Transform::setPosition(const Vector3 position){
		this->position = position;
	}

	const Vector3 Transform::getPosition() const{
		return this->position;
	}

	void Transform::setScale(const Vector2 scale){
		this->scale = scale;
	}

	const Vector2 Transform::getScale() const{
		return this->scale;
	}

	void Transform::setRotation(const double rotation){
		this->rotation = rotation;
	}

	const double Transform::getRotation() const{
		return this->rotation;
	}
}
