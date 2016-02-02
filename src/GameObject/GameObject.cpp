#include <GameObject/GameObject.hpp>

int GameObject::gameobject_counter{0};

GameObject::GameObject(){
	initializeName();
}

GameObject::GameObject(const float spawn_x, const float spawn_y, const float spawn_z){
	this->transform = Transform(Vector3(spawn_x, spawn_y, spawn_z), Vector2(1, 1));
	this->components.push_back(&this->transform);

	initializeName();
}

GameObject::GameObject(const Vector3 position, const Vector2 scale){
	this->transform = Transform(position, scale);
	initializeName();
}

GameObject::~GameObject(){
	--gameobject_counter;
}


const int GameObject::getGameObjectCounter(){
	return GameObject::gameobject_counter;
}

void GameObject::setPosition(const Vector3 position){
	this->transform.setPosition(position);
}

void GameObject::setScale(const Vector2 scale){
	this->transform.setScale(scale);
}

void GameObject::setName(const std::string name){
	this->name = name;
}

const Vector3 GameObject::getPosition() const{
	return this->transform.getPosition();
}

const Vector2 GameObject::getScale() const{
	return this->transform.getScale();
}

const std::string GameObject::getName() const{
	return this->name;
}

void GameObject::addComponent(Component* component){
	component->setGameObject(this);
	this->components.push_back(component);
}

std::vector<Component*>* GameObject::getComponents(){
	return &this->components;
}

void GameObject::initializeName(){
	this->name += "_" + gameobject_counter;
	++gameobject_counter;
}
