#include "Matrix3.h"

Matrix3::Matrix3(bool isIdentity)
{
	matrix[0] = Vector3(isIdentity, 0, 0);
	matrix[1] = Vector3(0, isIdentity, 0);
	matrix[2] = Vector3(0, 0, isIdentity);
}

Matrix3::Matrix3(array<Vector3, SIZE> matrix) : matrix(matrix) 
{
}

Matrix3::Matrix3(const Matrix3 &matrix)
{
	this->matrix = matrix.matrix;
}

Matrix3 Matrix3::transpose()
{
	array<Vector3, SIZE> resultMatrix;
	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE; j++) {
			resultMatrix[i][j] = matrix[j][i];
		}
	}
	return Matrix3(resultMatrix);
}

const Matrix3 &Matrix3::operator=(const Matrix3 &m)
{
	matrix = m.matrix;
	return *this;
}

bool Matrix3::operator==(const Matrix3 &m) const
{
	for (unsigned int i = 0; i < m.matrix.size(); i++)
	{
		if (matrix[i] != m.matrix[i]) 
		{
			return false;
		}
	}
	return true;
}

bool Matrix3::operator!=(const Matrix3 &m) const
{
	return !(*this == m);
}

Vector3 & Matrix3::operator[](const unsigned int i)
{
	return matrix[i];
}

Matrix3::~Matrix3()
{
}



ostream &operator<<(ostream &out, const Matrix3 &m)
{
	array<Vector3, Vector3::SIZE> matrix = m.getMatrix();
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		out << matrix[i] << endl;
	}
	return out;
}

Matrix3 operator+(const Matrix3 &m1, const Matrix3 &m2)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector3, Vector3::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] + m2.getMatrix()[i];
	}
	return Matrix3(matrix);
}

Matrix3 operator-(const Matrix3 &m1, const Matrix3 &m2)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector3, Vector3::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] - m2.getMatrix()[i];
	}
	return Matrix3(matrix);
}

Matrix3 operator*(const Matrix3 & m1, const double d)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector3, Vector3::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] * d;
	}
	return Matrix3(matrix);
}

Matrix3 operator*(const double d, const Matrix3 & m1)
{
	return m1 * d;
}

Matrix3 operator/(const Matrix3 & m1, const double d)
{
	return m1 * ( 1 / d);
}

Vector3 operator*(Matrix3 & m1, Vector3 & v1)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	Vector3 result = Vector3();
	double component;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		component = 0;
		for (unsigned int j = 0; j < matrixSize; j++)
		{
			component += m1.getMatrix()[i][j] * v1[j];
		}
		result[i] = component;
	}
	return result;
}

Vector3 operator*(Vector3 & v1, Matrix3 & m1)
{
	return m1 * v1;
}

Matrix3 operator*(Matrix3 & m1, Matrix3 & m2)
{
	Matrix3 transposedM2 = m2.transpose();
	array<Vector3, Vector3::SIZE> matrix;
	array<double, Vector3::SIZE> components;
	for (unsigned int i = 0; i < Vector3::SIZE; i++)
	{
		for (unsigned int j = 0; j < Vector3::SIZE; j++)
		{
			components[j] = Vector3::dot(m1[i], transposedM2[j]);
		}
		matrix[i] = Vector3(components);
	}
	return Matrix3(matrix);
}