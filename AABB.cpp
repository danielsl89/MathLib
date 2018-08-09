#include "AABB.h"

AABB::AABB(): min(), max()
{
}

AABB::AABB(Vector3 min, Vector3 max): min(min), max(max)
{
}

AABB::AABB(const AABB &aabb): min(aabb.min), max(aabb.max)
{
}

bool AABB::collide(const AABB &aabb) const
{
	Vector3 aabbMax = aabb.getMax();
	Vector3 aabbMin = aabb.getMin();

	if (min.getX() > aabbMax.getX()) return false;
	if (min.getY() > aabbMax.getY()) return false;
	if (min.getZ() > aabbMax.getZ()) return false;
	if (max.getX() < aabbMin.getX()) return false;
	if (max.getY() < aabbMin.getY()) return false;
	if (max.getZ() < aabbMin.getZ()) return false;

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
