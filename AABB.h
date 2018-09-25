#pragma once
#include "Vector.h"
class AABB
{
private:
	Vector<double, 3> min;
	Vector<double, 3> max;
public:
	AABB();
	AABB(Vector<double, 3> min, Vector<double, 3> max);
	AABB(const AABB &aabb);
	AABB(AABB &&aabb) = default;

	Vector<double, 3> getMin() const { return min; }
	void setMin(Vector<double, 3> min) { this->min = min; }
	Vector<double, 3> getMax() const { return max; }
	void setMax(Vector<double, 3> max) { this->max = max; }
	bool collide(const AABB &aabb) const;
	~AABB();
};

ostream &operator<<(ostream &out, const AABB &aabb);