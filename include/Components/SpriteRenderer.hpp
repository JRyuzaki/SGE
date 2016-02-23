#ifndef __SPRITE_RENDERER__
#define __SPRITE_RENDERER__

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Components/Component.hpp>
#include <GameObject/GameObject.hpp>
//#include <Variables.hpp>
#include <Math/Vector2.hpp>
#include <Math/Vector3.hpp>

namespace sge{
	enum OriginPosition{
		CENTER, LEFT_TOP, LEFT_MIDDLE, LEFT_BOTTOM, MIDDLE_TOP, MIDDLE_BOTTOM, RIGHT_TOP, RIGHT_MIDDLE, RIGHT_BOTTOM
	};

	class SpriteRenderer : public Component{
		protected:
			sf::Sprite sprite;			///< Object Sprite that will be managed by the spriterenderer

			Vector3 position{0, 0, 0};		///< Z-Value only important for Z-Buffer-Rendering
			Vector2 scale{1, 1};
			Vector2 size{1, 1};			///< Vector represents size of Image with applied scaling

			OriginPosition origin{LEFT_TOP};
			Vector2 origin_offset{0, 0};
		public:
			Renderable() = default;
			Renderable(GameObject* g_object);
			Renderable(const Renderable &other);

			void setSprite(const sf::Texture &texture);	///< Applies the given Texture onto the sprite and sets the size Vector
			sf::Sprite& getSprite();

			void setSpriteScale(const Vector2 scale);		///< Sets the sprite scaling, if the sprite allready has a texture, the size vector is updated
			const Vector2 getSpriteScale() const;

			const Vector2 getSpriteSize() const;

			void setSpritePosition(const Vector3 position);
			const Vector3 getSpritePosition() const;

			void setOrigin(OriginPosition origin_position);			///< Sets the OriginPosition Variable and updates the offset Vector

			void changeTexture(const sf::Texture &texture);			///< Applies new Texture onto the sprite, keeping scaling and position intact

			void updateComponent();			///< Used to update the sprite's coordinates to the player's coordinates
	};
}
#endif
