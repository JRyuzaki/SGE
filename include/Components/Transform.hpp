#ifndef __TRANSFORM__
#define __TRANSFORM__

#include <Components/Component.hpp>
#include <Math/Vector3.hpp>
#include <Math/Vector2.hpp>

class Transform : public Component{
	protected:
		Vector3 position{0, 0, 0};
		Vector2 scale{1, 1};
		double rotation{0};

	public:
		Transform() = default;
		Transform(Vector3 position);
		Transform(Vector3 position, Vector2 scale);
		Transform(Vector3 position, Vector2 scale, double rotation);

		void setPosition(const Vector3 position);
		const Vector3 getPosition() const;

		void setScale(const Vector2 scale);
		const Vector2 getScale() const;

		void setRotation(const double rotation);
		const double getRotation() const;

		void updateComponent(GameObject& g_object){};	///< Update Function for every GameObject that is executed, needs to be overriden if used
};

#endif
