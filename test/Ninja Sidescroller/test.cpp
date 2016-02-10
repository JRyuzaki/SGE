#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
  sf::Texture sky_texture;
	sky_texture.setSmooth(true);
	if(!sky_texture.loadFromFile("GFX//Backgrounds//Mountain//sky.png")){
    std::cout << "Fuck" << std::endl;
  }

  std::cout << sky_texture.getSize().x << std::endl;
  return 0;
}
