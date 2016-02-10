#include "Player.hpp"

Player::Player(int spawn_x, int spawn_y, int spawn_z) : GameObject(spawn_x, spawn_y, spawn_z){
	this->sprite_renderer = Renderable(this);
	this->sprite_renderer.setSpriteScale(Vector2(0.4f, 0.4f));

	this->idle_animation.setAnimationSpeed(40);
	this->run_animation.setAnimationSpeed(40);
	this->slide_animation.setAnimationSpeed(20);

	this->jump_animation.setAnimationSpeed(20);
	this->jump_animation.setRepeat(false);

	this->dead_animation.setAnimationSpeed(40);
	this->dead_animation.setRepeat(false);

	setPlayerState(PlayerState::RUNNING);


	this->rigidbody = Rigidbody(*this);
	this->rect_collider = RectCollider(Vector2(spawn_x, spawn_y), this->sprite_renderer.getSpriteSize().x, this->sprite_renderer.getSpriteSize().y);

	this->sprite_renderer.setOrigin(LEFT_BOTTOM);
	this->sprite_renderer.positionSprite(getPosition());

	setName("Player");
	addComponent(&this->sprite_renderer);
	addComponent(&this->rigidbody);
	addComponent(&this->rect_collider);
}

void Player::setPlayerState(PlayerState player_state){
	if(this->player_state == player_state)
		return;

	switch(player_state){
		case IDLE:
			setPlayerAnimation(&this->idle_animation);
			break;
		case RUNNING:
			setPlayerAnimation(&this->run_animation);
			break;
		case SLIDING:
			setPlayerAnimation(&this->slide_animation);
			break;
		case JUMPING:
			setPlayerAnimation(&this->jump_animation);
			break;
		case DEAD:
			setPlayerAnimation(&this->dead_animation);
			break;
	}
	this->player_state = player_state;
}

PlayerState Player::getPlayerState(){
	return this->player_state;
}

void Player::setPlayerAnimation(AnimatedSprite* new_animation){
	this->current_animation = new_animation;
	this->current_animation->reset();
	this->sprite_renderer.changeTexture(this->current_animation->getCurrentTexture());
}

void Player::updateGameObject(){
	this->current_animation->updateAnimatedSprite();
}
