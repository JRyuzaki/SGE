#include <Render/AnimatedSprite.hpp>

AnimatedSprite::AnimatedSprite(std::string path_to_sprite_sheet, int swidth, int sheight, int famount) : sprite_width(swidth), sprite_height(sheight), frame_amount(famount){
	if(!this->sprite_sheet.loadFromFile(path_to_sprite_sheet)){
		std::cerr << "Couldn't load spritesheet form " << path_to_sprite_sheet << std::endl;
	}

	if(!this->current_texture.loadFromImage(this->sprite_sheet, sf::IntRect(0, 0, sprite_width, sprite_height))){
		std::cerr << "Couldn't select current sprite" << std::endl;
	}

	this->current_texture.setSmooth(true);

	gettimeofday(&this->time_since_last_frame, NULL);
}

void AnimatedSprite::reset(){
	gettimeofday(&this->time_since_last_frame, NULL);
	this->current_frame_id = 0;
}

void AnimatedSprite::setRepeat(const bool repeat){
	this->repeat = repeat;
}

const bool AnimatedSprite::isRepeated(){
	return this->repeat;
}

int AnimatedSprite::timeDifference(timeval t1, timeval t2){
	return ((t1.tv_sec - t2.tv_sec) * 1000) + ((t1.tv_usec - t2.tv_usec) / 1000);
}

sf::Texture& AnimatedSprite::getCurrentTexture(){
	return this->current_texture;
}

void AnimatedSprite::setAnimationSpeed(int new_animation_speed){
	this->animation_speed = new_animation_speed;
}

void AnimatedSprite::updateAnimatedSprite(){
	if(!this->repeat && this->current_frame_id == (this->frame_amount - 1)){
		return;
	}

	timeval current_time;
	gettimeofday(&current_time, NULL);

	int time_difference = timeDifference(current_time, this->time_since_last_frame);


	if(time_difference >= this->animation_speed){
		++this->current_frame_id;
		this->time_since_last_frame = current_time;

		this->current_frame_id %= this->frame_amount;

		if(!this->current_texture.loadFromImage(this->sprite_sheet, sf::IntRect(this->current_frame_id * this->sprite_width, 0, this->sprite_width, this->sprite_height))){
			std::cerr << "FCouldn't select current sprite" << std::endl;
		}

	}
}
