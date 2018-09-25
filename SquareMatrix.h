#pragma once
#include "Vector.h"
#include <array>

template<typename T, std::size_t n>
class SquareMatrix
{
private:
	array<Vector<T, n>, n> data;
public:
	SquareMatrix(bool isIdentity = false);
	SquareMatrix(array<Vector<T, n>, n> data);
	SquareMatrix(const SquareMatrix &matrix);
	SquareMatrix(SquareMatrix &&matrix) = default;

	SquareMatrix transpose();
	const SquareMatrix &operator=(const SquareMatrix &matrix);
	bool operator==(const SquareMatrix &matrix) const;
	bool operator!=(const SquareMatrix &matrix) const;
	Vector<T, n> &operator[](const unsigned int i);
	const Vector<T, n> &operator[](const unsigned int i) const;
	~SquareMatrix() = default;
};

template<typename T, std::size_t n>
ostream &operator<<(ostream &out, const SquareMatrix<T, n> &matrix);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator+(const SquareMatrix<T, n> &m1, const SquareMatrix<T, n> &m2);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator-(const SquareMatrix<T, n> &m1, const SquareMatrix<T, n> &m2);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(const SquareMatrix<T, n> &m1, const double d);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(const double d, const  SquareMatrix<T, n> &m1);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator/(const SquareMatrix<T, n> &m1, const double d);
template<typename T, std::size_t n>
Vector<T, n> operator*(SquareMatrix<T, n> &m1, Vector<T, n> &v1);
template<typename T, std::size_t n>
Vector<T, n> operator*(Vector<T, n> &v1, SquareMatrix<T, n> &m1);
template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(SquareMatrix<T, n> &m1, SquareMatrix<T, n> &m2);

//Class member functions
template<typename T, std::size_t n>
SquareMatrix<T, n>::SquareMatrix(bool isIdentity)
{
	for (int i = 0; i < n; i++)
	{
		data[i][i] = static_cast<T>(isIdentity);
	}
}

template<typename T, std::size_t n>
SquareMatrix<T, n>::SquareMatrix(array<Vector<T, n>, n> data) : data(data)
{
}

template<typename T, std::size_t n>
SquareMatrix<T, n>::SquareMatrix(const SquareMatrix &matrix)
{
	this->data = matrix.data;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> SquareMatrix<T, n>::transpose()
{
	SquareMatrix<T, n> resultMatrix(data);
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			resultMatrix[i][j] = data[j][i];
		}
	}
	return resultMatrix;
}

template<typename T, std::size_t n>
const SquareMatrix<T, n> &SquareMatrix<T, n>::operator=(const SquareMatrix<T, n> &matrix)
{
	data = matrix.data;
	return *this;
}

template<typename T, std::size_t n>
bool SquareMatrix<T, n>::operator==(const SquareMatrix<T, n> &matrix) const
{
	for (unsigned int i = 0; i < n; i++)
	{
		if (data[i] != matrix[i])
		{
			return false;
		}
	}
	return true;
}

template<typename T, std::size_t n>
bool SquareMatrix<T, n>::operator!=(const SquareMatrix<T, n> &matrix) const
{
	return !(*this == matrix);
}

template<typename T, std::size_t n>
Vector<T, n> &SquareMatrix<T, n>::operator[](const unsigned int i)
{
	return data[i];
}

template<typename T, std::size_t n>
const Vector<T, n> &SquareMatrix<T, n>::operator[](const unsigned int i) const
{
	return data[i];
}
//End of class member functions



template<typename T, std::size_t n>
ostream &operator<<(ostream &out, const SquareMatrix<T, n> &matrix)
{
	for (int i = 0; i < n; i++)
	{
		out << matrix[i] << endl;
	}
	return out;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator+(const SquareMatrix<T, n> &m1, const SquareMatrix<T, n> &m2)
{
	SquareMatrix<T, n> matrix;
	for (unsigned int i = 0; i < n; i++)
	{
		matrix[i] = m1[i] + m2[i];
	}
	return matrix;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator-(const SquareMatrix<T, n> &m1, const SquareMatrix<T, n> &m2)
{
	SquareMatrix<T, n> matrix;
	for (unsigned int i = 0; i < n; i++)
	{
		matrix[i] = m1[i] - m2[i];
	}
	return matrix;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(const SquareMatrix<T, n> &m1, const double d)
{
	SquareMatrix<T, n> matrix;
	for (unsigned int i = 0; i < n; i++)
	{
		matrix[i] = m1[i] * d;
	}
	return matrix;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(const double d, const  SquareMatrix<T, n> &m1)
{
	return m1 * d;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator/(const SquareMatrix<T, n> &m1, const double d)
{
	return m1 * (1 / d);
}

template<typename T, std::size_t n>
Vector<T, n> operator*(SquareMatrix<T, n> &m1, Vector<T, n> &v1)
{
	array<T, n> result;
	double component;
	for (unsigned int i = 0; i < n; i++)
	{
		component = 0;
		for (unsigned int j = 0; j < n; j++)
		{
			component += m1[i][j] * v1[j];
		}
		result[i] = component;
	}
	return Vector<T, n>(result);
}

template<typename T, std::size_t n>
Vector<T, n> operator*(Vector<T, n> &v1, SquareMatrix<T, n> &m1)
{
	return m1 * v1;
}

template<typename T, std::size_t n>
SquareMatrix<T, n> operator*(SquareMatrix<T, n> &m1, SquareMatrix<T, n> &m2)
{
	SquareMatrix<T, n> transposedM2 = m2.transpose();
	array<Vector<T, n>, n> matrix;
	array<T, n> components;
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			components[j] = Vector<T, n>::dot(m1[i], transposedM2[j]);
		}
		matrix[i] = Vector<T, n>(components);
	}
	return SquareMatrix<T, n>(matrix);
}