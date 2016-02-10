#ifndef __TRANSFORM__
#define __TRANSFORM__

#include <Math/Vector3.hpp>
#include <Math/Vector2.hpp>

namespace sge{
	class Transform{		///<Is the Transform really a class or a struct?
		protected:
			Vector3 position{0, 0, 0};
			Vector2 scale{1, 1};
			double rotation{0};

		public:
			Transform() = default;
			Transform(Vector3 position);
			Transform(Vector3 position, Vector2 scale);
			Transform(Vector3 position, Vector2 scale, double rotation);
			Transform(const Transform &other);

			void setPosition(const Vector3 position);
			const Vector3 getPosition() const;

			void setScale(const Vector2 scale);
			const Vector2 getScale() const;

			void setRotation(const double rotation);
			const double getRotation() const;
	};
}
#endif
