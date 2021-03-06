#ifndef __COMPONENT__
#define __COMPONENT__

namespace sge{
	class GameObject;		//Foreward-Declaration needed here to resolve circular dependency
	
	class Component{
		protected:
			GameObject* game_object;		//Reference to the GameObject that uses the component
		public:
			/**
			 * This virtual function is used as an interface for the user to make his own custom Components
			 * for own projects.
			 **/
			virtual void updateComponent() = 0;

			void setGameObject(GameObject* game_object){
				this->game_object = game_object;
			}

			GameObject* getGameObject(){
				return this->game_object;
			}
	};
}
#endif
