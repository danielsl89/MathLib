#include "vector3.h"
#include "vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "quaternion.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std;

void vector3Examples()
{
	cout << "----------- VECTOR3 -----------" << endl;

	//Creating vector1
	Vector3 vector3_1(7, -1, 4.5);
	cout << "vector3_1: " << vector3_1 << endl;
	//Creating vector2
	Vector3 vector3_2(2, 3, -2);
	cout << "vector3_2: " << vector3_2 << endl;

	Vector3 result = vector3_1 + vector3_2;
	cout << "Result of vector3_1 + vector3_2: " << result << endl;

	result = vector3_1 * 3;
	cout << "Result of vector3_1 * 3: " << result << endl;

	cout << "Dot product of vector3_1 and vector3_2: " << Vector3::dot(vector3_1, vector3_2) << endl;

	result = Vector3::cross(vector3_1, vector3_2);
	cout << "Cross product of vector3_1 and vector3_2: " << result << endl;

	result = Vector3::scale(vector3_1, vector3_2);
	cout << "Scale vector3_1 by vector3_2: " << result << endl;

	cout << "Magnitude vector3_1: " << vector3_1.magnitude() << endl;

	cout << "Linear interpolation (t=0.25) between vector3_1 and vector3_2: " << Vector3::lerp(vector3_1, vector3_2, 0.25) << endl;
}

void vector4Examples()
{
	cout << "----------- VECTOR4 -----------" << endl;
	//Creating vector1
	Vector4 vector4_1(7, -1, 4.5, 2);
	cout << "vector4_1: " << vector4_1 << endl;
	//Creating vector2
	Vector4 vector4_2(2, 3, -2, 0.5);
	cout << "vector4_2: " << vector4_2 << endl;
	cout << "vector4_1, w value: " << vector4_1[3] << endl; //Testing operator[] access

	Vector4 result = vector4_1 - vector4_2;
	cout << "Result of vector4_1 - vector4_2: " << result << endl;

	result = vector4_1 / 2;
	cout << "Result of vector4_1 / 2: " << result << endl;

	cout << "Dot product of vector4_1 and vector4_2: " << Vector4::dot(vector4_1, vector4_2) << endl;

	result = Vector4::scale(vector4_1, vector4_2);
	cout << "Scale vector4_1 by vector4_2: " << result << endl;

	cout << "Magnitude vector4_1: " << vector4_1.magnitude() << endl;

	cout << "Linear interpolation (t=0.5) between vector4_1 and vector4_2: " << Vector3::lerp(vector4_1, vector4_2, 0.5) << endl;
}

void matrix3Examples()
{
	cout << "----------- MATRIX3 -----------" << endl;
	Matrix3 matrix3_1 = Matrix3(
		array<Vector3, 3>
		{
			Vector3(3, 2, -1),
			Vector3(0, -5, 2),
			Vector3(2, 1, 4)
		}
	);
	cout << "matrix3_1:" << endl << matrix3_1;

	Vector3 vector3_1(7, -1, 4.5);
	cout << "vector3_1" << vector3_1 << endl;
	Vector3 vectorResult = matrix3_1 * vector3_1;
	cout << "Result of matrix3_1 * vector3_1: " << vectorResult << endl;

	Matrix3 matrix3_2 = Matrix3(
		array<Vector3, 3>
		{
			Vector3(0, 5, 1),
			Vector3(0, 4, -1),
			Vector3(3, 1, -1)
		}
	);
	cout << "matrix3_2:" << endl << matrix3_2;

	cout << "Transpose matrix3_2:" << endl << matrix3_2.transpose();

	Matrix3 matrixResult = matrix3_1 + matrix3_2;
	cout << "Result of matrix3_1 + matrix3_2: " << endl << matrixResult;

	matrixResult = matrix3_2 * 1.5;
	cout << "Result of matrix3_2 * 1.5: " << endl << matrixResult;

	matrixResult = matrix3_1 * matrix3_2;
	cout << "Result of matrix3_1 * matrix3_2: " << endl << matrixResult;
}

void matrix4Examples()
{
	cout << "----------- MATRIX4 -----------" << endl;
	Matrix4 matrix4_1 = Matrix4(
		array<Vector4, 4>
		{
			Vector4(2, 1, 3, -1),
			Vector4(1, -3, 4, -3),
			Vector4(0, 1, 1, 2),
			Vector4(2, -1, -3, -4)
		}
	);
	Vector4 vector4_1(7, -1, 4.5, 2);

	cout << "matrix4_1: " << endl << matrix4_1;
	cout << "vector4_1: " << vector4_1 << endl;

	Vector4 vectorResult = matrix4_1 * vector4_1;
	cout << "Result of matrix4_1 * vector4_1: " << vectorResult << endl;

	Matrix4 matrix4_2 = Matrix4(
		array<Vector4, 4>
		{
			Vector4(-1, 0, 2, 1),
			Vector4(0, -1, 1, 3),
			Vector4(1, 0, 0, -2),
			Vector4(-1, 1, 2, 3)
		}
	);
	cout << "matrix4_2: " << endl << matrix4_2;

	Matrix4 matrixResult = matrix4_1 - matrix4_2;
	cout << "Result of matrix4_1 - matrix4_2: " << endl << matrixResult;

	matrixResult = matrix4_1 / 2;
	cout << "Result of matrix4_1 / 2: " << endl << matrixResult;

	Matrix4 identityMatrix = Matrix4(true);
	cout << "Identity Matrix4: " << endl << identityMatrix;

	matrixResult = matrix4_1 * matrix4_2;
	cout << "Result of matrix4_1 * matrix4_2: " << endl << matrixResult;
}

void quaternionExamples()
{
	cout << "----------- QUATERNION -----------" << endl;

	Quaternion quaternion1(1, 0, 1, 0);
	cout << "quaternion1: " << quaternion1 << endl;
	Quaternion quaternion2(1, 0.5, 0.5, 0.75);
	cout << "quaternion2: " << quaternion2 << endl;

	cout << "Result of quaternion1 + quaternion2: " << quaternion1 + quaternion2 << endl;
	cout << "Result of quaternion1 - quaternion2: " << quaternion1 - quaternion2 << endl;
	cout << "Result of quaternion1 * quaternion2: " << quaternion1 * quaternion2 << endl;

	Vector3 vector3_1(0, 3, 2);
	cout << "vector3_1: " << vector3_1 << endl;
	Quaternion quaternion3 = Quaternion::getQuaternionByAngleAndVector(90, Vector3(1, 0, 0));
	cout << "quaternion3: " << quaternion3 << endl;
	cout << "Result of rotation: " << vector3_1 * quaternion3 << endl;
}

int main() {

	vector3Examples();
	vector4Examples();
	matrix3Examples();
	matrix4Examples();
	quaternionExamples();

	int wait;
	cin >> wait;

	return 0;
}
