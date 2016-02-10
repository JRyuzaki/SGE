#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <iostream>
#include <vector>

#include <Math/Vector2.hpp>
#include <Math/Vector3.hpp>

#include <Components/Component.hpp>

#include <GameObject/Transform.hpp>

namespace sge{
	class GameObject{
		protected:
			static int gameobject_counter;

			std::string name{"gameobject"};		///<Name of the GameObject, does not need to be unique
			std::vector<Component*> components;

			Transform transform{Vector3(0, 0, 0), Vector2(1, 1)};

			bool activity{true};

			/**
			 *Add vector list for parent relations
			 */

		public:
			GameObject();
			GameObject(const float spawn_x, const float spawn_y, const float spawn_z);		///<Remove?, because it can be confusing with too many params
			GameObject(const Vector3 position, const Vector2 scale);
			GameObject(const Vector3 position, const Vector2 scale, const double rotation);
			~GameObject();

			static const int getGameObjectCounter();

			void setActivity(const bool activity);
			void setPosition(const Vector3 position);
			void setRotation(const double rotation);
			void setScale(const Vector2 scale);
			void setName(const std::string name);
			void setTransform(const Transform &other);

			const bool isActive() const;
			const Vector3 getPosition() const;
			const double getRotation() const;
			const Vector2 getScale() const;
			const std::string getName() const;
			const Transform getTransform() const;

			void addComponent(Component* component);
			void removeComponent(Component* component);		///<Not Working Needs Fixing
			void clearComponents();
			std::vector<Component*>* getComponents();

			/**
			 *Get all components of one type
			 **/

			/**
			 *This method is called once every frame and should be used to implement own routines for custom gameobjects
			 */
			virtual void readyGameObject(){};		///<Better Name for this function?
			virtual void updateGameObject(){};

			/**
			 *Add virtual destroy method
			 *Add virtual init method
			 **/

			template<typename ComponentClass>ComponentClass* getComponent(){
				for(Component* component : *getComponents()){
					if(ComponentClass* g_component = dynamic_cast<ComponentClass*>(component)){
						return g_component;
					}
				}
				return NULL;
			}

		protected:
			void initializeName();	///<This function is used in all constructors to give the GameObject a standardized name
	};
}
#endif
