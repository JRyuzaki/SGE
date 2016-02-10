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

	class Renderable : public Component{
		protected:
			sf::Sprite sprite;

			Vector3 position{0, 0, 0};		///< Z-Value only important for Z-Buffer-Rendering
			Vector2 scale{1, 1};
			Vector2 size{1, 1};

			OriginPosition origin{LEFT_TOP};
			Vector2 origin_offset{0, 0};
		public:
			Renderable() = default;
			Renderable(GameObject* g_object);
			Renderable(const Renderable &other);

			sf::Sprite& getSprite();

			void updateComponent();
			
			void positionSprite(const Vector3 position);
			void setSprite(const sf::Texture &texture);
			const Vector2 getSpriteScale() const;
			void setSpriteScale(const Vector2 scale);
			const Vector2 getSpriteSize() const;
			void setSpritePosition(const Vector3 position);
			const Vector3 getSpritePosition() const;
			void setOrigin(OriginPosition origin_position);
			void changeTexture(const sf::Texture &texture);
	};
}
#endif
