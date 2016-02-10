#ifndef __SCENE_MANAGER__
#define __SCENE_MANAGER__

#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

#include <SFML/Graphics.hpp>


#include <Render/Renderer.hpp>
#include <Physics/PhysicsEngine.hpp>
#include <Physics/CollisionEngine.hpp>
#include <Components/Component.hpp>
#include <GameObject/GameObject.hpp>
#include <GameObject/Transform.hpp>
//#include "Variables.hpp"

namespace sge{
	class SceneManager{
		private:
			std::vector<GameObject*> scene_objects;

			Renderer scene_renderer;
			PhysicsEngine physics_engine;
			CollisionEngine collision_engine;

		public:
			SceneManager(Renderer renderer) : scene_renderer(renderer){
			}

			void addToScene(GameObject* game_object){
				scene_objects.push_back(game_object);

				Renderable* sprite_renderer = game_object->getComponent<Renderable>();
				Rigidbody* rigidbody = game_object->getComponent<Rigidbody>();
				RectCollider* rect_collider = game_object->getComponent<RectCollider>();

				if(sprite_renderer != NULL){
					this->scene_renderer.addToRenderer(sprite_renderer);
				}

				if(rigidbody != NULL){
					this->physics_engine.addRigidbody(rigidbody);
				}

				if(rect_collider != NULL){	///DEBUG
					std::cout << "Rect Collider Added For " << game_object->getName() << std::endl;
					this->collision_engine.addCollider(rect_collider);
				}
			}

			void updateScene(){
				this->collision_engine.updateCollisions();
				this->physics_engine.updatePhysics();
				for(GameObject* g_object : this->scene_objects){
					for(Component* component : *g_object->getComponents()){
						component->updateComponent();
					}
					g_object->updateGameObject();
				}
			}

			void drawScene(){
				scene_renderer.render();
			}
	};
}
#endif
