#include <GameObject/GameObject.hpp>

namespace sge{
	int GameObject::gameobject_counter{0};

	GameObject::GameObject(){
		initializeName();
	}

	GameObject::GameObject(const float spawn_x, const float spawn_y, const float spawn_z){
		this->transform = Transform(Vector3(spawn_x, spawn_y, spawn_z), Vector2(1, 1));

		initializeName();
	}

	GameObject::GameObject(const Vector3 position, const Vector2 scale){
		this->transform = Transform(position, scale);

		initializeName();
	}

	GameObject::GameObject(const Vector3 position, const Vector2 scale, const double rotation){
		this->transform = Transform(position, scale, rotation);

		initializeName();
	}

	GameObject::~GameObject(){
		--gameobject_counter;
	}

	const int GameObject::getGameObjectCounter(){
		return GameObject::gameobject_counter;
	}

	void GameObject::setActivity(const bool activity){
		this->activity = activity;
	}

	void GameObject::setPosition(const Vector3 position){
		this->transform.setPosition(position);
	}

	void GameObject::setRotation(const double rotation){
			this->transform.setRotation(rotation);
	}

	void GameObject::setScale(const Vector2 scale){
		this->transform.setScale(scale);
	}

	void GameObject::setName(const std::string name){
		this->name = name;
	}

	void GameObject::setTransform(const Transform &other){
		this->transform = other;
	}

	const bool GameObject::isActive() const{
		return this->activity;
	}

	const Vector3 GameObject::getPosition() const{
		return this->transform.getPosition();
	}

	const double GameObject::getRotation() const{
		return this->transform.getRotation();
	}

	const Vector2 GameObject::getScale() const{
		return this->transform.getScale();
	}

	const std::string GameObject::getName() const{
		return this->name;
	}

	const Transform GameObject::getTransform() const{
		return this->transform;
	}

	void GameObject::addComponent(Component* component){
		component->setGameObject(this);
		this->components.push_back(component);
	}

	void GameObject::removeComponent(Component* component){
		//this->components.erase(std::remove(this->components.begin(), this->components.end(), component), this->components.end());
	}

	void GameObject::clearComponents(){
		this->components.clear();
	}

	std::vector<Component*>* GameObject::getComponents(){
		return &this->components;
	}

	void GameObject::initializeName(){
		this->name += "_" + gameobject_counter;
		++gameobject_counter;
	}
}
