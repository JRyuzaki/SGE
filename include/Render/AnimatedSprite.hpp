#ifndef __ANIMATED_SPRITE__
#define __ANIMATED_SPRITE__

#include <iostream>
#include <sys/time.h>

#include <SFML/Graphics.hpp>

class AnimatedSprite{
	private:
		sf::Image sprite_sheet;
		sf::Texture current_texture;
		
		int sprite_width{0};
		int sprite_height{0};
		
		int animation_speed {1};
		timeval time_since_last_frame;
		
		int current_frame_id{0};
		int frame_amount{0};
		
		bool repeat{true};
		
	public:
		AnimatedSprite() = default;
		AnimatedSprite(std::string path_to_sprite_sheet, int swidth, int sheight, int frames);
		
		int timeDifference(timeval t1, timeval t2);
		
		void reset();
		
		void setRepeat(const bool repeat);
		const bool isRepeated();
		
		sf::Texture& getCurrentTexture();
		void setAnimationSpeed(int new_animation_speed);
		void updateAnimatedSprite();
};

#endif
