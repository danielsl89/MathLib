#include "Matrix4.h"

Matrix4::Matrix4(bool isIdentity) 
{
	matrix[0] = Vector4(isIdentity, 0, 0, 0);
	matrix[1] = Vector4(0, isIdentity, 0, 0);
	matrix[2] = Vector4(0, 0, isIdentity, 0);
	matrix[3] = Vector4(0, 0, 0, isIdentity);
}

Matrix4::Matrix4(array<Vector4, SIZE> matrix) : matrix(matrix) 
{
}

Matrix4::Matrix4(const Matrix4 &matrix)
{
	this->matrix = matrix.matrix;
}


Matrix4 Matrix4::transpose()
{
	array<Vector4, SIZE> resultMatrix;
	for (unsigned int i = 0; i < SIZE; i++) {
		for (unsigned int j = 0; j < SIZE; j++) {
			resultMatrix[i][j] = matrix[j][i];
		}
	}
	return Matrix4(resultMatrix);
}

const Matrix4 &Matrix4::operator=(const Matrix4 &m)
{
	matrix = m.matrix;
	return *this;
}

bool Matrix4::operator==(const Matrix4 &m) const
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

bool Matrix4::operator!=(const Matrix4 &m) const
{
	return !(*this == m);
}

Vector4 & Matrix4::operator[](const unsigned int i)
{
	return matrix[i];
}

Matrix4::~Matrix4()
{
}



ostream &operator<<(ostream &out, const Matrix4 &m)
{
	array<Vector4, Vector4::SIZE> matrix = m.getMatrix();
	for (unsigned int i = 0; i < Vector4::SIZE; i++)
	{
		out << matrix[i] << endl;
	}
	return out;
}

Matrix4 operator+(Matrix4 &m1, Matrix4 &m2)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector4, Vector4::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] + m2.getMatrix()[i];
	}
	return Matrix4(matrix);
}

Matrix4 operator-(Matrix4 &m1, Matrix4 &m2)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector4, Vector4::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] - m2.getMatrix()[i];
	}
	return Matrix4(matrix);
}

Matrix4 operator*(Matrix4 & m1, double d)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	array<Vector4, Vector4::SIZE> matrix;
	for (unsigned int i = 0; i < matrixSize; i++)
	{
		matrix[i] = m1.getMatrix()[i] * d;
	}
	return Matrix4(matrix);
}

Matrix4 operator*(double d, Matrix4 & m1)
{
	return m1 * d;
}

Matrix4 operator/(Matrix4 & m1, double d)
{
	return m1 * ( 1 / d);
}

Vector4 operator*(Matrix4 & m1, Vector4 & v1)
{
	const unsigned int matrixSize = m1.getMatrix().size();
	Vector4 result = Vector4();
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

Vector4 operator*(Vector4 & v1, Matrix4 & m1)
{
	return m1 * v1;
}

Matrix4 operator*(Matrix4 & m1, Matrix4 & m2)
{
	Matrix4 transposedM2 = m2.transpose();
	array<Vector4, Vector4::SIZE> matrix;
	array<double, Vector4::SIZE> components;
	for (unsigned int i = 0; i < Vector4::SIZE; i++)
	{
		for (unsigned int j = 0; j < Vector4::SIZE; j++)
		{
			components[j] = Vector4::dot(m1[i], transposedM2[j]);
		}
		matrix[i] = Vector4(components);
	}
	return Matrix4(matrix);
}