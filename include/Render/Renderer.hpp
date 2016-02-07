#ifndef __RENDERER__
#define __RENDERER__

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Components/Renderable.hpp>

const bool zBufferCompare(Renderable* one, Renderable* other);

class Renderer{
	private:
		std::vector<Renderable*> renderList;
		sf::RenderWindow* render_window;

	public:
		Renderer(sf::RenderWindow* render_window);

		void addToRenderer(Renderable* obj);
		void render();
};


#endif
