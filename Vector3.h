#pragma once
#include <array>
#include <iostream>
using namespace std;

class Vector3 {
protected:
	static const unsigned int X_INDEX = 0;
	static const unsigned int Y_INDEX = 1;
	static const unsigned int Z_INDEX = 2;
	double x;
	double y;
	double z;
public:
	static const unsigned int SIZE = 3;
	Vector3();
	Vector3(double x, double y, double z);
	Vector3(array<double, SIZE> components);
	Vector3(const Vector3 &vector);

	double getX() const { return x; }
	void setX(double x) { this->x = x; }

	double getY() const { return y; }
	void setY(double y) { this->y = y; }

	double getZ() const { return z; }
	void setZ(double z) { this->z = z; }

	double magnitude();
	static double dot(Vector3 &v1, Vector3 &v2);
	static Vector3 cross(Vector3 &v1, Vector3 &v2);
	static Vector3 scale(Vector3 &v1, Vector3 &v2);

	const Vector3 &operator=(const Vector3 &vector);
	bool operator==(const Vector3 &vector) const;
	bool operator!=(const Vector3 &vector) const;
	double &operator[](const unsigned int i);
	~Vector3();
};

ostream &operator<<(ostream &out, const Vector3 &vector);
Vector3 operator+(Vector3 &v1, Vector3 &v2);
Vector3 operator-(Vector3 &v1, Vector3 &v2);
Vector3 operator*(Vector3 &v1, double d);
Vector3 operator*(double d, Vector3 &v1);
Vector3 operator/(Vector3 &v1, double d);