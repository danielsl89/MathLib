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

Quaternion Quaternion::getQuaternionByAngleAndVector(double angle, Vector3 vector)
{
	double rad = angle * PI / 180;
	double a = sin(rad / 2);
	return Quaternion(cos(rad / 2), vector.getX() * a, vector.getY() * a, vector.getZ() * a );
}

Quaternion Quaternion::slerp(const Quaternion & q1, const Quaternion & q2, double t)
{
	double dotproduct = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

	t = t / 2.0;

	double theta = acos(dotproduct);
	if (theta<0.0) theta = -theta;

	double s1 = sin(theta);
	double s2 = sin(t*theta);
	double s3 = sin((1 - t)*theta);
	double coeff1 = s3 / s1;
	double coeff2 = s2 / s1;

	Quaternion q3(coeff1 * q1.w + coeff2 * q2.w,
		coeff1 * q1.x + coeff2 * q2.x,
		coeff1 * q1.y + coeff2 * q2.y,
		coeff1 * q1.z + coeff2 * q2.z);

	//We should normalize before returning
	return q3;
}

Quaternion Quaternion::operator+(const Quaternion &q)
{
	return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator-(const Quaternion &q)
{
	return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::operator*(const Quaternion &q) const
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

Vector3 operator*(const Vector3 & v1, const Quaternion & q)
{
	Vector3 qvector = Vector3(q.getX(), q.getY(), q.getZ());
	Vector3 v2 = Vector3::cross(qvector, v1) * 2;
	return v1 + q.getW() * v2 + Vector3::cross(qvector, v2);
}

Vector3 operator*(Quaternion & q, Vector3 & v1)
{
	return v1 * q;
}
