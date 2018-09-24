#pragma once
#include <array>
#include <iostream>
using namespace std;

template<typename T, std::size_t n>
class Vector {
private:
	array<T, n> data;
public:
	Vector(array<T, n> data);
	Vector(const Vector &vector);
	Vector(Vector &&vector) = default;

	long double magnitude();
	static T dot(const Vector &v1, const Vector &v2);
	static Vector scale(const Vector &v1, const Vector &v2);
	static Vector lerp(const Vector &v1, const Vector &v2, const double t);

	const Vector &operator=(const Vector &vector);
	bool operator==(const Vector &vector) const;
	bool operator!=(const Vector &vector) const;
	T &operator[](const unsigned int i);
	const T &operator[](const unsigned int i) const;
	~Vector() = default;
};

template<typename T, std::size_t n>
ostream &operator<<(ostream &out, const Vector<T, n> &vector);
template<typename T, std::size_t n>
Vector<T, n> operator+(const Vector<T, n> &v1, const Vector<T, n> &v2);
template<typename T, std::size_t n>
Vector<T, n> operator-(const Vector<T, n> &v1, const Vector<T, n> &v2);
template<typename T, std::size_t n>
Vector<T, n> operator*(const Vector<T, n> &v1, const double d);
template<typename T, std::size_t n>
Vector<T, n> operator*(const double d, const Vector<T, n> &v1);
template<typename T, std::size_t n>
Vector<T, n> operator/(const Vector<T, n> &v1, const double d);
template<typename T>
Vector<T, 3> cross(const Vector<T, 3> &v1, const Vector<T, 3> &v2);

//Class member functions
template<typename T, std::size_t n>
Vector<T, n>::Vector(array<T, n> data) : data(data)
{
}

template<typename T, std::size_t n>
Vector<T, n>::Vector(const Vector<T, n> & vector)
{
	data = vector.data;
}

template<typename T, std::size_t n>
long double Vector<T, n>::magnitude()
{
	double result = .0;
	for (auto &&i : data)
	{
		result += pow(i, 2);
	}
	return sqrt(result);
}

template<typename T, std::size_t n>
T Vector<T, n>::dot(const Vector<T, n> &v1, const Vector<T, n> &v2)
{
	T result = T();
	for (int i = 0; i < n; i++)
	{
		result += v1.data[i] * v2.data[i];
	}
	return result;
}

template<typename T, std::size_t n>
Vector<T, n> Vector<T, n>::scale(const Vector<T, n> & v1, const Vector<T, n> & v2)
{
	array<T, n> data;
	for (int i = 0; i < n; i++)
	{
		data[i] = v1.data[i] * v2.data[i];
	}
	return data;
}

template<typename T, std::size_t n>
Vector<T, n> Vector<T, n>::lerp(const Vector<T, n> & v1, const Vector<T, n> & v2, const double t)
{
	return t * v1 + (1.0 - t) * v2;
}

template<typename T, std::size_t n>
const Vector<T, n> &Vector<T, n>::operator=(const Vector<T, n> &vector)
{
	data = vector.data;
	return *this;
}

template<typename T, std::size_t n>
bool Vector<T, n>::operator==(const Vector<T, n> &vector) const
{
	for (int i = 0; i < n; i++)
	{
		if (data[i] != vector.data[i]) return false;
	}
	return true;
}

template<typename T, std::size_t n>
bool Vector<T, n>::operator!=(const Vector<T, n> &vector) const
{
	return !(*this == vector);
}

template<typename T, std::size_t n>
T &Vector<T, n>::operator[](const unsigned int i)
{
	return data[i];
}

template<typename T, std::size_t n>
const T &Vector<T, n>::operator[](const unsigned int i) const
{
	return data[i];
}
//End of class member functions



template<typename T, std::size_t n>
ostream &operator<<(ostream &out, const Vector<T,n> &vector)
{
	out << "(";
	for (int i = 0; i < n; i++)
	{
		out << vector[i] << "; ";
	}
	out << ")";
	return out;
}

template<typename T, std::size_t n>
Vector<T, n> operator+(const Vector<T, n> &v1, const Vector<T, n> &v2)
{
	array<T, n> data;
	for (int i = 0; i < n; i++)
	{
		data[i] = v1[i] + v2[i];
	}
	Vector<T, n> result(data);
	return result;
}

template<typename T, std::size_t n>
Vector<T, n> operator-(const Vector<T, n> &v1, const Vector<T, n> &v2)
{
	array<T, n> data;
	for (int i = 0; i < n; i++)
	{
		data[i] = v1[i] - v2[i];
	}
	return Vector<T, n>(data);
}

template<typename T, std::size_t n>
Vector<T, n> operator*(const Vector<T, n> & v1, const double d)
{
	array<T, n> data;
	for (int i = 0; i < n; i++)
	{
		data[i] = v1[i] * d;
	}
	return Vector<T, n>(data);
}

template<typename T, std::size_t n>
Vector<T, n> operator*(const double d, const Vector<T, n> & v1)
{
	return v1 * d;
}

template<typename T, std::size_t n>
Vector<T, n> operator/(const Vector<T, n> & v1, const double d)
{
	return v1 * (1 / d);
}

template<typename T>
Vector<T, 3> cross(const Vector<T, 3> &v1, const Vector<T, 3> &v2)
{
	T i = v1[1] * v2[2] - v1[2] * v2[1];
	T j = -v1[0] * v2[2] + v1[2] * v2[0];
	T k = v1[0] * v2[1] - v1[1] * v2[0];
	return Vector<T, 3>({ i, j, k });
}