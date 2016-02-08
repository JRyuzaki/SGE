#ifndef __RECT_COLLIDER__
#define __RECT_COLLIDER__


#include <Physics/Collider/Collider.hpp>
#include <GameObject/GameObject.hpp>
#include <Math/Vector2.hpp>

namespace sge{
	class RectCollider : public Component{
		protected:
			Vector2 left_top_corner{0, 0};
			int width{0};
			int height{0};
		public:
			RectCollider() = default;

			RectCollider(Vector2 left_top_corner, int width, int height) : left_top_corner(left_top_corner), width(width), height(height){

			}

			const Vector2 getLeftTopCorner() const{
				return this->left_top_corner;
			}

			const int getRectWidth() const{
				return this->width;
			}

			const int getRectHeight() const{
				return this->height;
			}

			void updateComponent(GameObject &game_object){
				this->left_top_corner = Vector2(game_object.getPosition().x, game_object.getPosition().y);
			}
	};
}
#endif
