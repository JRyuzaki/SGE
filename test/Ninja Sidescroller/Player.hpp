#ifndef __PLAYER__
#define __PLAYER__

#include <iostream>

#include <SFML/Graphics.hpp>

#include <GameObject/GameObject.hpp>
#include <Components/Renderable.hpp>
#include <Render/AnimatedSprite.hpp>
//#include "Variables.hpp>
#include <GameObject/Transform.hpp>
#include <Physics/Collider/RectCollider.hpp>
#include <Physics/Rigidbody.hpp>

using namespace sge;

enum PlayerState{
	IDLE, SLIDING, RUNNING, JUMPING, DEAD
};

class Player : public GameObject{
	private:
		int lifes;
		AnimatedSprite idle_animation{"GFX/Player/player_idle.png", 232, 439, 10};
		AnimatedSprite run_animation{"GFX/Player/player_run.png", 363, 458, 10};
		AnimatedSprite slide_animation{"GFX/Player/player_slide.png", 373, 351, 10};
		AnimatedSprite jump_animation{"GFX/Player/player_jump.png", 362, 483, 10};
		AnimatedSprite dead_animation{"GFX/Player/player_dead.png", 482, 498, 10};

		AnimatedSprite* current_animation;

		Renderable sprite_renderer;
		PlayerState player_state;

		Rigidbody rigidbody;
		RectCollider rect_collider;
	public:
		Player(int spawn_x, int spawn_y, int spawn_z);

		void setPlayerState(PlayerState player_state);
		PlayerState getPlayerState();

		void setPlayerAnimation(AnimatedSprite* new_animation);

		void updateGameObject();
};
#endif
