#include "Vector3.h"

Vector3::Vector3() :x(0), y(0), z(0)
{
}

Vector3::Vector3(double x, double y, double z): x(x), y(y), z(z)
{
}

Vector3::Vector3(array<double, SIZE> components) :
	x(components[X_INDEX]), 
	y(components[Y_INDEX]), 
	z(components[Z_INDEX])
{
}

Vector3::Vector3(const Vector3 & vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
}


double Vector3::magnitude()
{
	return sqrt(x*x + y*y + z *z);
}

double Vector3::dot(const Vector3 & v1, const Vector3 & v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

Vector3 Vector3::cross(const Vector3 & v1, const Vector3 & v2)
{
	double i = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
	double j = -v1.getX() * v2.getZ() + v1.getZ() * v2.getX();
	double k = v1.getX() * v2.getY() - v1.getY() * v2.getX();
	return Vector3(i, j, k);
}

Vector3 Vector3::scale(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.getX() * v2.getX(), v1.getY() * v2.getY(), v2.getZ() * v2.getZ());
}

Vector3 Vector3::lerp(const Vector3 & v1, const Vector3 & v2, const double t)
{
	return t * v1 + (1.0 - t) * v2;
}

const Vector3 &Vector3::operator=(const Vector3 &vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

bool Vector3::operator==(const Vector3 &vector) const
{
	return (x == vector.x && y == vector.y && z == vector.z);
}

bool Vector3::operator!=(const Vector3 &vector) const
{
	return !(*this == vector);
}

double & Vector3::operator[](const unsigned int i)
{
	switch(i)
	{
		case X_INDEX:
			return x;
		case Y_INDEX:
			return y;
		case Z_INDEX:
			return z;
	}
	throw out_of_range("Attempt to access an out of range index");
}

Vector3::~Vector3()
{
}



ostream &operator<<(ostream &out, const Vector3 &vector)
{
	out << "(" << vector.getX() << "; " << vector.getY() << "; " << vector.getZ() << ")";
	return out;
}

Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

Vector3 operator*(const Vector3 & v1, const double d)
{
	return Vector3(v1.getX() * d, v1.getY() * d, v1.getZ() * d);
}

Vector3 operator*(const double d, const Vector3 & v1)
{
	return v1 * d;
}

Vector3 operator/(const Vector3 & v1, const double d)
{
	return v1 * (1/d);
}