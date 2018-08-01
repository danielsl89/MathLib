#include "Quaternion.h"

Quaternion::Quaternion() :w(0), x(0), y(0), z(0)
{
}

Quaternion::Quaternion(double w, double x, double y, double z) : w(w), x(x), y(y), z(z)
{
}

Quaternion::Quaternion(const Quaternion &q) : w(q.w), x(q.x), y(q.y), z(q.z)
{
}

Quaternion Quaternion::operator+(Quaternion &q) 
{
	return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator-(Quaternion &q) 
{
	return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::operator*(Quaternion &q) 
{
	double _w = w * q.w - x * q.x - y * q.y - z * q.z;
	double _x = w * q.x + x * q.w + y * q.z + z * q.y;
	double _y = w * q.y - x * q.z + y * q.w + z * q.x;
	double _z = w * q.z + x * q.y - y * q.x + z * q.w;
	return Quaternion(_w, _x, _y, _z);
}

Quaternion::~Quaternion() 
{
}

ostream & operator<<(ostream & out, const Quaternion & quaternion)
{
	out << "(" << quaternion.getW() << "; " << quaternion.getX() << "; " << quaternion.getY() << "; " << quaternion.getZ() << ")";
	return out;
}
