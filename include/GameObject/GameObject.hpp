#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <iostream>
#include <vector>

#include <Math/Vector2.hpp>
#include <Math/Vector3.hpp>

#include <Components/Component.hpp>
#include <Components/Transform.hpp>

class GameObject{
	protected:
		std::string name{"gameobject"};		///<Name of the GameObject, does not need to be unique
		std::vector<Component*> components;

		Transform transform{Vector3(0, 0, 0), Vector2(1, 1)};

		static int gameobject_counter;

	public:
		GameObject();
		GameObject(const float spawn_x, const float spawn_y, const float spawn_z);
		GameObject(const Vector3 position, const Vector2 scale);
		~GameObject();

		static const int getGameObjectCounter();

		void setPosition(const Vector3 position);
		void setScale(const Vector2 scale);
		void setName(const std::string name);

		const Vector3 getPosition() const;
		const Vector2 getScale() const;
		const std::string getName() const;

		void addComponent(Component* component);
		std::vector<Component*>* getComponents();

		virtual void updateGameObject(){};	///<This method is the interface for users to implement their own update routines for the GameObject

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
#endif
