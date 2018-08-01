#pragma once
#include "vector3.h"

class Vector4: public Vector3 {
private:
	static const unsigned int W_INDEX = 3;
	double w;
public:
	static const unsigned int SIZE = 4;
	Vector4();
	Vector4(double x, double y, double z, double w);
	Vector4(array<double, SIZE> components);
	Vector4(const Vector4 &vector);

	double getW() const { return w; }
	void setW(double x) { this->w = w; }

	double magnitude();
	static double dot(Vector4 &v1, Vector4 &v2);
	static Vector4 scale(Vector4 &v1, Vector4 &v2);

	const Vector4 &operator=(const Vector4 &vector);
	bool operator==(const Vector4 &vector) const;
	bool operator!=(const Vector4 &vector) const;
	double &operator[](const unsigned int i);
	~Vector4();
};

ostream &operator<<(ostream &out, const Vector4 &vector);
Vector4 operator+(Vector4 &v1, Vector4 &v2);
Vector4 operator-(Vector4 &v1, Vector4 &v2);
Vector4 operator*(Vector4 &v1, double d);
Vector4 operator*(double d, Vector4 &v1);
Vector4 operator/(Vector4 &v1, double d);