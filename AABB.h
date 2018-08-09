#pragma once
#include "Vector3.h"
class AABB
{
private:
	Vector3 min;
	Vector3 max;
public:
	AABB();
	AABB(Vector3 min, Vector3 max);
	AABB(const AABB &aabb);

	Vector3 getMin() const { return min; }
	void setMin(Vector3 min) { this->min = min; }
	Vector3 getMax() const { return max; }
	void setMax(Vector3 max) { this->max = max; }
	bool collide(const AABB &aabb) const;
	~AABB();
};

ostream &operator<<(ostream &out, const AABB &aabb);

