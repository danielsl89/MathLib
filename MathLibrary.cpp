#include "Vector3.h"
#include "Vector4.h"
#include "Vector.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Quaternion.h"
#include "AABB.h"
#include <iostream>
#include <array>
#include <vector>
#include "OpenGLUtil.h"
using namespace std;

const char* WINDOW_NAME = "Math Library";
vector<Vector3> bezierAnchors;
vector<Vector3> casteljauPoints;
void runMainLoop(int val);
void update();
void render();

void vector3Examples()
{
	cout << "----------- VECTOR3 -----------" << endl;

	Vector<double, 3> vector1({ 7, -1, 4.5 });
	cout << "vector1: " << vector1 << endl;
	Vector<double, 3> vector2({ 2, 3, -2 });
	cout << "vector2: " << vector2 << endl;

	Vector<double, 3> result = vector1 + vector2;
	cout << "Result of vector1 + vector2: " << result << endl;

	result = vector1 * 3;
	cout << "Result of vector1 * 3: " << result << endl;

	cout << "Dot product of vector1 and vector2: " << Vector<double, 3>::dot(vector1, vector2) << endl;

	result = cross(vector1, vector2);
	cout << "Cross product of vector1 and vector2: " << result << endl;

	result = Vector<double, 3>::scale(vector1, vector2);
	cout << "Scale vector1 by vector2: " << result << endl;

	cout << "Magnitude vector1: " << vector1.magnitude() << endl;

	cout << "Linear interpolation (t=0.25) between vector1 and vector2: " << Vector<double, 3>::lerp(vector1, vector2, 0.25) << endl;
}

void vector4Examples()
{
	cout << "----------- VECTOR4 -----------" << endl;
	//Creating vector1
	Vector<double, 4> vector1({ 7, -1, 4.5, 2 });
	cout << "vector1: " << vector1 << endl;
	//Creating vector2
	Vector<double, 4> vector2({ 2, 3, -2, 0.5 });
	cout << "vector2: " << vector2 << endl;
	cout << "vector1, w value: " << vector1[3] << endl; //Testing operator[] access

	Vector<double, 4> result = vector1 - vector2;
	cout << "Result of vector1 - vector2: " << result << endl;

	result = vector1 / 2;
	cout << "Result of vector1 / 2: " << result << endl;

	cout << "Dot product of vector1 and vector2: " << Vector<double, 4>::dot(vector1, vector2) << endl;

	result = Vector<double, 4>::scale(vector1, vector2);
	cout << "Scale vector1 by vector2: " << result << endl;

	cout << "Magnitude vector1: " << vector1.magnitude() << endl;

	cout << "Linear interpolation (t=0.5) between vector1 and vector2: " << Vector<double, 4>::lerp(vector1, vector2, 0.5) << endl;
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
	cout << "quaternion3 (angle: 90, vector3(1, 0, 0): " << quaternion3 << endl;
	cout << "Result of rotation: " << vector3_1 * quaternion3 << endl;

	Quaternion qn1 = Quaternion::getNormalizedQuaternion(quaternion1);
	Quaternion qn2 = Quaternion::getNormalizedQuaternion(Quaternion(-1, 0, 1, 0));

	cout << "Normalized quaternion1: " << qn1 << endl;
	cout << "Normalized quaternion(-1, 0, 1, 0): " << qn2 << endl;
	cout << "Slerp: " << Quaternion::slerp(qn1, qn2, 0.5) << endl;
}

void aabbExamples()
{
	cout << "----------- AABB -----------" << endl;
	AABB aabb1(Vector3(2, 2, 1), Vector3(4, 4, 1));
	cout << "aabb1: " << aabb1 << endl;
	AABB aabb2(Vector3(3, 4, 1), Vector3(5, 5, 2));
	cout << "aabb2: " << aabb2 << endl;

	if (aabb1.collide(aabb2))
	{
		cout << "aabb1 collides aabb2" << endl;
	}
	else
	{
		cout << "aabb1 does not collide aabb2" << endl;
	}
}

Vector3 getCasteljauPoint(vector<Vector3> &points, int r, int i, double t) {
	if (r == 0) return points[i];

	Vector3 v1 = getCasteljauPoint(points, r - 1, i, t);
	Vector3 v2 = getCasteljauPoint(points, r - 1, i + 1, t);

	return Vector3(((1 - t) * v1.getX() + t * v2.getX()), ((1 - t) * v1.getY() + t * v2.getY()), ((1 - t) * v1.getZ() + t * v2.getZ()));
}

void getCasteljauPoints(vector<Vector3> &points) {
	Vector3 cp;

	for (double t = 0; t <= 1; t += 0.001) {
		cp = getCasteljauPoint(points, points.size() - 1, 0, t);
		casteljauPoints.push_back(cp);
	}
}

int main(int argc, char* args[]) {

	vector3Examples();
	vector4Examples();
	matrix3Examples();
	matrix4Examples();
	quaternionExamples();
	aabbExamples();
	cout << "---------------------------" << endl;

	

	//Bezier curve generation and drawing
	bezierAnchors.push_back(Vector3(20, 20, 1));
	bezierAnchors.push_back(Vector3(400, 80, 1));
	bezierAnchors.push_back(Vector3(420, 380, 1));
	bezierAnchors.push_back(Vector3(620, 400, 1));
	getCasteljauPoints(bezierAnchors);

	//Initialize FreeGLUT
	glutInit(&argc, args);
	//Create OpenGL 3.1 context
	glutInitContextVersion(3, 1);
	//Create Double Buffered Window
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow(WINDOW_NAME);

	//Do post window/context creation initialization
	if (!initGL())
	{
		printf("Unable to initialize graphics library!\n");
		return 1;
	}
	//Set rendering function
	glutDisplayFunc(render);
	//Set main loop
	glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, 0);
	//Start GLUT main loop
	glutMainLoop();

	return 0;
}

void runMainLoop(int val)
{
	//Frame logic
	update();
	render();
	//Run frame one more time
	glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}

void update()
{
}

void render()
{
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.f, 0.f, 0.f);
	for (unsigned int i = 0; i < casteljauPoints.size() - 1; i++)
	{
		glBegin(GL_LINES);
		glVertex3f(static_cast<GLfloat>(casteljauPoints[i].getX()), (GLfloat)casteljauPoints[i].getY(), static_cast<GLfloat>(casteljauPoints[i].getZ()));
		glVertex3f(static_cast<GLfloat>(casteljauPoints[i + 1].getX()), (GLfloat)casteljauPoints[i + 1].getY(), static_cast<GLfloat>(casteljauPoints[i + 1].getZ()));
		glEnd();
	}

	const int ANCHOR_SIZE = 2;
	glColor3f(0.f, 0.f, 1.f);
	for (unsigned int i = 0; i < bezierAnchors.size(); i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i].getX()) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getY()) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getZ()));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i].getX()) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getY()) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getZ()));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i].getX()) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getY()) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getZ()));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i].getX()) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getY()) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i].getZ()));
		glEnd();
	}

	//Update screen
	glutSwapBuffers();
}