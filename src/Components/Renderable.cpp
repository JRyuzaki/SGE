#include <Components/Renderable.hpp>

Renderable::Renderable(GameObject *g_object){
	this->position = g_object->getPosition();
	this->scale = g_object->getScale();

	positionSprite(this->position);
	setSpriteScale(this->scale);
}

Renderable::Renderable(const Renderable &other){
	this->sprite = other.sprite;
	this->position = other.getSpritePosition();
	this->scale = other.getSpriteScale();
	this->size = other.getSpriteSize();
	this->origin = other.origin;
}

sf::Sprite& Renderable::getSprite(){
	return this->sprite;
}

void Renderable::positionSprite(const Vector3 position){
	this->sprite.setPosition(sf::Vector2f(this->origin_offset.x + position.x, this->origin_offset.y + position.y));
	this->position.z = position.z;
}

void Renderable::setSprite(const sf::Texture &texture){
	this->sprite.setTexture(texture);
	this->size.x *= texture.getSize().x;
	this->size.y *= texture.getSize().y;
}

const Vector2 Renderable::getSpriteScale() const{
	return this->scale;
}

void Renderable::setSpriteScale(const Vector2 scale){
	this->sprite.setScale(sf::Vector2f(scale.x, scale.y));
	this->size.x *= scale.x;
	this->size.y *= scale.y;
	this->scale = scale;
}

const Vector3 Renderable::getSpritePosition() const{
	return this->position;
}

void Renderable::setSpritePosition(const Vector3 position){
	this->position = position;
}

const Vector2 Renderable::getSpriteSize() const{
	return this->size;
}

void Renderable::setOrigin(OriginPosition origin_position){
	int x_size = getSpriteSize().x;
	int y_size = getSpriteSize().y;


	switch(origin_position){
		case CENTER:
			this->origin_offset = Vector2(x_size / 2, y_size / 2);
			break;
		case LEFT_BOTTOM:
			this->origin_offset = Vector2(0, y_size);
			break;
		case LEFT_MIDDLE:
			this->origin_offset = Vector2(0, y_size / 2);
			break;
		case LEFT_TOP:
			this->origin_offset = Vector2(0, 0);
			break;
		case MIDDLE_BOTTOM:
			this->origin_offset = Vector2(x_size / 2, y_size);
			break;
		case MIDDLE_TOP:
			this->origin_offset = Vector2(x_size / 2, 0);
			break;
		case RIGHT_BOTTOM:
			this->origin_offset = Vector2(x_size, y_size);
			break;
		case RIGHT_MIDDLE:
			this->origin_offset = Vector2(x_size, y_size / 2);
			break;
		case RIGHT_TOP:
			this->origin_offset = Vector2(x_size, 0);
			break;
	}

	this->origin = origin_position;
	this->sprite.setOrigin(this->origin_offset.x, this->origin_offset.y);
}

void Renderable::updateComponent(GameObject& g_object){
	positionSprite(g_object.getPosition());
}

void Renderable::changeTexture(const sf::Texture& texture){
	this->sprite = sf::Sprite(texture);
	this->size.x = texture.getSize().x * this->scale.x;
	this->size.y = texture.getSize().y * this->scale.y;

	setOrigin(this->origin);
	positionSprite(this->position);
	this->sprite.setScale(this->scale.x, this->scale.y);
}
