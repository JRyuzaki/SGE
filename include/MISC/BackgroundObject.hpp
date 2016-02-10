#ifndef __BACKGROUND_OBJECT__
#define __BACKGROUND_OBJECT__

#include <iostream>
#include <vector>

#include <Components/Component.hpp>
#include <GameObject/GameObject.hpp>


extern const int window_size_x;

namespace sge{
	class BackgroundObject : public Component{
		protected:
			bool repeat{false};
			float scroll_speed{1};


		public:
			BackgroundObject(const float scroll_speed) : scroll_speed(scroll_speed){

			}

			void updateComponent(){
				Vector3 g_position = this->game_object->getPosition();
				float g_x = g_position.x;

				Renderable* sprite_renderer = this->game_object->getComponent<Renderable>();
				if(sprite_renderer != NULL){
					g_x += sprite_renderer->getSpriteSize().x;
				}

				if(g_x < 0){
					this->game_object->setPosition(Vector3(window_size_x, g_position.y, g_position.z));
				}else{
					this->game_object->setPosition(Vector3(g_position.x + this->scroll_speed, g_position.y, g_position.z));
				}
			}

			void setRepeat(bool repeat){
				this->repeat = repeat;
			}

			const bool isRepeated(){
				return this->repeat;
			}
	};
}
#endif
