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

double Quaternion::dot(const Quaternion & q1, const Quaternion & q2)
{
	return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
}

Quaternion Quaternion::getQuaternionByAngleAndVector(double angle, Vector<double, 3> vector)
{
	double rad = angle * PI / 180;
	double a = sin(rad / 2);
	return Quaternion(cos(rad / 2), vector[0] * a, vector[1] * a, vector[2] * a );
}

Quaternion Quaternion::getNormalizedQuaternion(const Quaternion & q1)
{
	double norm = sqrt(q1.w * q1.w + q1.x * q1.x + q1.y * q1.y + q1.z * q1.z);
	return Quaternion(q1.w / norm, q1.x / norm, q1.y / norm, q1.z / norm);
}

Quaternion Quaternion::lerp(const Quaternion & q1, const Quaternion & q2, double t)
{
	return q1 + t * (q2 - q1);
}

Quaternion Quaternion::slerp(const Quaternion & q1, const Quaternion & q2, double t)
{
	Quaternion qn1 = Quaternion::getNormalizedQuaternion(q1);
	Quaternion qn2 = Quaternion::getNormalizedQuaternion(q2);

	double dot = Quaternion::dot(qn1, qn2);

	//Reversing q2, so slerp takes the shortest path
	if (dot < 0) {
		qn2 = -1 * qn2;
		dot = -dot;
	}

	const double DOT_THRESHOLD = 0.9995;
	//If the results are too close, linearly interpolate
	if (dot > DOT_THRESHOLD) {
		Quaternion result = Quaternion::lerp(q1, q2, t);
		result.normalize();
		return result;
	}

	// Since dot is in range [0, DOT_THRESHOLD], acos is safe
	double theta_0 = acos(dot);
	double theta = theta_0 * t;
	double sin_theta = sin(theta);
	double sin_theta_0 = sin(theta_0);

	double s0 = cos(theta) - dot * sin_theta / sin_theta_0;
	double s1 = sin_theta / sin_theta_0;

	return (s0 * qn1) + (s1 * qn2);
}

void Quaternion::normalize()
{
	double norm = sqrt(w * w + x * x + y * y + z * z);
	w = w / norm;
	x = x / norm;
	y = y / norm;
	z = z / norm;
}

const Quaternion & Quaternion::operator=(const Quaternion & q)
{
	w = q.w;
	x = q.x;
	y = q.y;
	z = q.z;
	return *this;
}

Quaternion Quaternion::operator+(const Quaternion &q) const
{
	return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator-(const Quaternion &q) const
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

Vector<double, 3> operator*(const Vector<double, 3> & v1, const Quaternion & q)
{
	Vector<double, 3> qvector = Vector<double, 3>({ q.getX(), q.getY(), q.getZ() });
	Vector<double, 3> v2 = cross(qvector, v1) * 2;
	return v1 + q.getW() * v2 + cross(qvector, v2);
}

Vector<double, 3> operator*(Quaternion & q, Vector<double, 3> & v1)
{
	return v1 * q;
}

Quaternion operator*(const Quaternion & q1, const double d)
{
	return Quaternion(q1.getW() * d, q1.getX() * d, q1.getY() * d, q1.getZ() * d);
}

Quaternion operator*(const double d, const Quaternion & q1)
{
	return q1 * d;
}

Quaternion operator/(const Quaternion & q1, const double d)
{
	return q1 * ( 1 / d );
}
