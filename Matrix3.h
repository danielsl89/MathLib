#pragma once
#include "Vector3.h"
#include <array>

class Matrix3
{
private:
	static const unsigned int SIZE = 3;
	array<Vector3, SIZE> matrix;
public:
	Matrix3(bool isIdentity = false);
	Matrix3(array<Vector3, SIZE> matrix);
	Matrix3(const Matrix3 &matrix);

	array<Vector3, SIZE> getMatrix() const { return matrix; }
	void setMatrix(array<Vector3, SIZE> matrix) { this->matrix = matrix; }
	Matrix3 transpose();

	const Matrix3 &operator=(const Matrix3 &m);
	bool operator==(const Matrix3 &m) const;
	bool operator!=(const Matrix3 &m) const;
	Vector3 &operator[](const unsigned int i);
	~Matrix3();
};

ostream &operator<<(ostream &out, const Matrix3 &m);
Matrix3 operator+(Matrix3 &m1, Matrix3 &m2);
Matrix3 operator-(Matrix3 &m1, Matrix3 &m2);
Matrix3 operator*(Matrix3 &m1, double d);
Matrix3 operator*(double d, Matrix3 &m1);
Matrix3 operator/(Matrix3 &m1, double d);
Vector3 operator*(Matrix3 &m1, Vector3 &v1);
Vector3 operator*(Vector3 &v1, Matrix3 &m1);
Matrix3 operator*(Matrix3 &m1, Matrix3 &m2);