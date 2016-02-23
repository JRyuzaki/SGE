#include <Components/SpriteRenderer.hpp>

namespace sge{
	SpriteRenderer::SpriteRenderer(GameObject *g_object){
		this->position = g_object->getPosition();
		this->scale = g_object->getScale();

		setSpritePosition(this->position);
		setSpriteScale(this->scale);
	}

	SpriteRenderer::SpriteRenderer(const SpriteRenderer &other){
		this->sprite = other.sprite;
		this->position = other.getSpritePosition();
		this->scale = other.getSpriteScale();
		this->size = other.getSpriteSize();
		this->origin = other.origin;
	}

	void SpriteRenderer::setSprite(const sf::Texture &texture){
		this->sprite.setTexture(texture);
		this->size.x *= texture.getSize().x;
		this->size.y *= texture.getSize().y;
	}

	sf::Sprite& SpriteRenderer::getSprite(){
		return this->sprite;
	}

	void SpriteRenderer::setSpriteScale(const Vector2 scale){
		this->sprite.setScale(sf::Vector2f(scale.x, scale.y));
		this->size.x *= scale.x;
		this->size.y *= scale.y;
		this->scale = scale;
	}

	const Vector2 SpriteRenderer::getSpriteScale() const{
		return this->scale;
	}

	const Vector2 SpriteRenderer::getSpriteSize() const{
		return this->size;
	}

	void SpriteRenderer::setSpritePosition(const Vector3 position){
		this->position = position;
		this->sprite.setPosition(sf::Vector2f(this->origin_offset.x + position.x, this->origin_offset.y + position.y));
	}

	const Vector3 SpriteRenderer::getSpritePosition() const{
		return this->position;
	}

	void SpriteRenderer::setOrigin(OriginPosition origin_position){
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

	void SpriteRenderer::changeTexture(const sf::Texture& texture){
		this->sprite = sf::Sprite(texture);
		this->size.x = texture.getSize().x * this->scale.x;
		this->size.y = texture.getSize().y * this->scale.y;

		setOrigin(this->origin);
		setSpritePosition(this->position);
		this->sprite.setScale(this->scale.x, this->scale.y);
	}

	void SpriteRenderer::updateComponent(){
		setSpritePosition(this->game_object->getPosition());
	}
}
