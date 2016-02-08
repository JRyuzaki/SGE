#include <Render/Renderer.hpp>

#include <iostream>
#include <functional>

namespace sge{
	Renderer::Renderer(sf::RenderWindow* render_window) : render_window(render_window){

	}

	const bool zBufferCompare(Renderable* one, Renderable* other){
		return one->getSpritePosition().z > other->getSpritePosition().z;
	}

	void Renderer::addToRenderer(Renderable* obj){
		this->renderList.push_back(obj);
		std::sort(this->renderList.begin(), this->renderList.end(), zBufferCompare);
	}

	void Renderer::render(){
		this->render_window->clear();

		int i = 0;

		for(Renderable* renderObject : this->renderList){
			this->render_window->draw(renderObject->getSprite());
		}
		this->render_window->display();
	}
}
