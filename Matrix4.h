#pragma once
#include "Vector4.h"
#include <array>

class Matrix4
{
private:
	static const unsigned int SIZE = 4;
	array<Vector4, SIZE> matrix;
public:
	Matrix4(bool isIdentity = false);
	Matrix4(array<Vector4, SIZE> matrix);
	Matrix4(const Matrix4 &matrix);

	array<Vector4, SIZE> getMatrix() const { return matrix; }
	void setMatrix(array<Vector4, SIZE> matrix) { this->matrix = matrix; }
	Matrix4 transpose();

	const Matrix4 &operator=(const Matrix4 &m);
	bool operator==(const Matrix4 &m) const;
	bool operator!=(const Matrix4 &m) const;
	Vector4 &operator[](const unsigned int i);
	~Matrix4();
};

ostream &operator<<(ostream &out, const Matrix4 &m);
Matrix4 operator+(const Matrix4 &m1, const Matrix4 &m2);
Matrix4 operator-(const Matrix4 &m1, const Matrix4 &m2);
Matrix4 operator*(const Matrix4 &m1, const double d);
Matrix4 operator*(const double d, const  Matrix4 &m1);
Matrix4 operator/(const Matrix4 &m1, const double d);
Vector4 operator*(Matrix4 &m1, Vector4 &v1);
Vector4 operator*(Vector4 &v1, Matrix4 &m1);
Matrix4 operator*(Matrix4 &m1, Matrix4 &m2);