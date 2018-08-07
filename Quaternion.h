#pragma once
#include <iostream>
#include "Vector3.h"
using namespace std;

#define PI 3.14159265

class Quaternion {
private:
	double w;
	double x;
	double y;
	double z;
public:
	Quaternion();
	Quaternion(double w, double x, double y, double z);
	Quaternion(const Quaternion &q);

	double getW() const { return w; }
	void setW(double w) { this->w = w; }

	double getX() const { return x; }
	void setX(double x) { this->x = x; }

	double getY() const { return y; }
	void setY(double y) { this->y = y; }

	double getZ() const { return z; }
	void setZ(double z) { this->z = z; }

	static Quaternion getQuaternionByAngleAndVector(double angle, Vector3 vector);
	static Quaternion slerp(const Quaternion &q1, const Quaternion &q2, double t);

	Quaternion operator+(const Quaternion &q);
	Quaternion operator-(const Quaternion &q);
	Quaternion operator*(const Quaternion &q) const;
	~Quaternion();
};

ostream &operator<<(ostream &out, const Quaternion &quaternion);
Vector3 operator*(const Vector3 &v1, const Quaternion &q);
Vector3 operator*(Quaternion &q, Vector3 &v1);