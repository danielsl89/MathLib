#include "AABB.h"

AABB::AABB(): min(), max()
{
}

AABB::AABB(Vector<double, 3> min, Vector<double, 3> max): min(min), max(max)
{
}

AABB::AABB(const AABB &aabb): min(aabb.min), max(aabb.max)
{
}

bool AABB::collide(const AABB &aabb) const
{
	Vector<double, 3> aabbMax = aabb.getMax();
	Vector<double, 3> aabbMin = aabb.getMin();

	if (min[0] > aabbMax[0]) return false;
	if (min[1] > aabbMax[1]) return false;
	if (min[2] > aabbMax[2]) return false;
	if (max[0] < aabbMin[0]) return false;
	if (max[1] < aabbMin[1]) return false;
	if (max[2] < aabbMin[2]) return false;

	return true;
}

AABB::~AABB()
{
}

ostream & operator<<(ostream & out, const AABB & aabb)
{
	out << "[min: " << aabb.getMin() << ", max: " << aabb.getMax() << "]";
	return out;
}
