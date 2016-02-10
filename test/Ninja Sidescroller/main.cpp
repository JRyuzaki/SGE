#include <SFML/Graphics.hpp>

#include <Core.hpp>
#include "Player.hpp"
#include <MISC/BackgroundObject.hpp>

const int window_size_x	= 1200;
const int window_size_y = 800;

using namespace sge;

int main()
{
	sf::RenderWindow main_window(sf::VideoMode(window_size_x, window_size_y), "Ninja Run");
	Renderer gameRenderer{&main_window};
	SceneManager scene{gameRenderer};

	Player player{10, 10, 10};

	sf::Texture sky_texture;
	sky_texture.setSmooth(true);
	sky_texture.loadFromFile("GFX/Backgrounds/Mountain/sky.png");

	GameObject sky_background_1{0, 0, 100};
	Renderable sky_background_1_renderer{&sky_background_1};
	sky_background_1_renderer.setSpriteScale(Vector2(0.4f, 0.4f));
	sky_background_1_renderer.setSprite(sky_texture);
	BackgroundObject background_script{-2};

	sky_background_1.addComponent(&sky_background_1_renderer);
	sky_background_1.addComponent(&background_script);


	GameObject sky_background_2{1200, 0, 100};
	Renderable sky_background_2_renderer{&sky_background_2};
	sky_background_2_renderer.setSpriteScale(Vector2(0.4f, 0.4f));
	sky_background_2_renderer.setSprite(sky_texture);

	sky_background_2.addComponent(&sky_background_2_renderer);
	sky_background_2.addComponent(&background_script);

	GameObject ground{Vector3(0, 0, 90), Vector2(1, 1)};
	sf::Texture ground_texture;
	ground_texture.setSmooth(true);
	ground_texture.loadFromFile("GFX/Backgrounds/Mountain/Tile.png");
	ground.setName("Ground");



	Renderable ground_renderer{&ground};
	//ground_renderer.setSpriteScale(Vector2(0.2f, 0.2f));
	ground_renderer.setSprite(ground_texture);
	ground_renderer.setOrigin(OriginPosition::RIGHT_BOTTOM);
	ground.addComponent(&ground_renderer);
	Rigidbody ground_rigidbody{ground};
	ground_rigidbody.setStatic(true);
	RectCollider rect_coll{Vector2(0, 0), (int)ground_renderer.getSpriteSize().x, (int)ground_renderer.getSpriteSize().y};
	ground.addComponent(&rect_coll	);
	ground.addComponent(&ground_rigidbody);

	scene.addToScene(&ground);
	scene.addToScene(&player);
	scene.addToScene(&sky_background_1);
	scene.addToScene(&sky_background_2);
	main_window.setFramerateLimit(60);

	while(main_window.isOpen()){
		sf::Event event;
		while(main_window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					main_window.close();
					break;
				case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
						player.setPlayerState(PlayerState::SLIDING);
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
						player.setPlayerState(PlayerState::JUMPING);
					}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
						player.setPlayerState(PlayerState::DEAD);
					}
					break;
				case sf::Event::KeyReleased:
					if(player.getPlayerState() == PlayerState::SLIDING){
						player.setPlayerState(PlayerState::RUNNING);
					}
				default:

					break;

			}
		}
		scene.updateScene();
		scene.drawScene();
	}

	return 0;
}
