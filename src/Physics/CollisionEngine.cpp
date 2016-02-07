#include <Physics/CollisionEngine.hpp>

void CollisionEngine::updateCollisions(){
	for(RectCollider* that : this->colliders){
		for(RectCollider* other : this->colliders){
			if(that == other)
				continue;
			if(boundingBoxCollision(that, other)){
				Rigidbody* rigidbody1 = that->getGameObject()->getComponent<Rigidbody>();
				Rigidbody* rigidbody2 = other->getGameObject()->getComponent<Rigidbody>();

				Vector2 velocity_difference = rigidbody1->getVelocity() - rigidbody2->getVelocity();
			}else{
					//TODO:
			}
		}
	}
}

void CollisionEngine::addCollider(RectCollider* collider){
	this->colliders.push_back(collider);
}

const bool CollisionEngine::boundingBoxCollision(RectCollider* r1, RectCollider* r2){
	Vector2 r1_left_corner = r1->getLeftTopCorner();
	Vector2 r2_left_corner = r2->getLeftTopCorner();

	int x_difference = abs(r1_left_corner.x - r2_left_corner.x) * 2;
	int y_difference = abs(r1_left_corner.y - r2_left_corner.y) * 2;

	if(x_difference < (r1->getRectWidth() + r2->getRectWidth())){
		if(y_difference < (r1->getRectHeight() + r2->getRectHeight())){
			return true;
		}
	}
	return false;
}
