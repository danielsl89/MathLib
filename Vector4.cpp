#include "Vector4.h"

Vector4::Vector4() :Vector3(0, 0, 0), w(0)
{
}

Vector4::Vector4(double x, double y, double z, double w): Vector3(x, y, z), w(w)
{
}

Vector4::Vector4(array<double, SIZE> components):
	Vector3(components[X_INDEX],
			components[Y_INDEX],
			components[Z_INDEX]),
	w(components[W_INDEX])
{
}

Vector4::Vector4(const Vector4 & vector): Vector3(vector.x, vector.y, vector.z), w(vector.w)
{
}

double Vector4::magnitude()
{
	return sqrt(x*x + y*y + z*z + w*w);
}

double Vector4::dot(const Vector4 & v1, const Vector4 & v2)
{
	return Vector3::dot(v1, v2) + v1.getW() * v2.getW();
}

Vector4 Vector4::scale(const Vector4 & v1, const Vector4 & v2)
{
	return Vector4(v1.getX() * v2.getX(), v1.getY() * v2.getY(), v2.getZ() * v2.getZ(), v1.getW() * v2.getW());
}

Vector4 Vector4::lerp(const Vector4 & v1, const Vector4 & v2, const double t)
{
	return t * v1 + (1.0 - t) * v2;
}

const Vector4 &Vector4::operator=(const Vector4 &vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
	return *this;
}

bool Vector4::operator==(const Vector4 &vector) const
{
	return (x == vector.x && y == vector.y && z == vector.z && w == vector.w);
}

bool Vector4::operator!=(const Vector4 &vector) const
{
	return !(*this == vector);
}

double & Vector4::operator[](const unsigned int i)
{
	if (i == W_INDEX) { return w; }
	return Vector3::operator[](i);
}

Vector4::~Vector4()
{
}



ostream &operator<<(ostream &out, const Vector4 &vector)
{
	out << "(" << vector.getX() << "; " << vector.getY() << "; " << vector.getZ() << "; " << vector.getW() << ")";
	return out;
}

Vector4 operator+(const Vector4 &v1, const Vector4 &v2)
{
	return Vector4(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ(), v1.getW() + v2.getW());
}

Vector4 operator-(const Vector4 &v1, const Vector4 &v2)
{
	return Vector4(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ(), v1.getW() - v2.getW());
}

Vector4 operator*(const Vector4 & v1, const double d)
{
	return Vector4(v1.getX() * d, v1.getY() * d, v1.getZ() * d, v1.getW() * d);
}

Vector4 operator*(const double d, const Vector4 & v1)
{
	return v1 * d;
}

Vector4 operator/(const Vector4 & v1, const double d)
{
	return v1 * (1 / d);
}