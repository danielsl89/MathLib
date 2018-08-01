#pragma once
#include <iostream>
using namespace std;

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

	Quaternion operator+(Quaternion &q);
	Quaternion operator-(Quaternion &q);
	Quaternion operator*(Quaternion &q);
	~Quaternion();
};

ostream &operator<<(ostream &out, const Quaternion &quaternion);