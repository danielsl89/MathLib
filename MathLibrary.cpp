#include "Vector.h"
#include "SquareMatrix.h"
#include "Quaternion.h"
#include "AABB.h"
#include <iostream>
#include <array>
#include <vector>
#include "OpenGLUtil.h"
using namespace std;

const char* WINDOW_NAME = "Math Library";
vector<Vector<double, 3>> bezierAnchors;
vector<Vector<double, 3>> casteljauPoints;
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
	SquareMatrix<double, 3> matrix1(
		array<Vector<double, 3>, 3>
		{
			Vector<double, 3>({ 3, 2, -1 }),
			Vector<double, 3>({ 0, -5, 2 }),
			Vector<double, 3>({ 2, 1, 4 })
		}
	);
	cout << "matrix1:" << endl << matrix1;

	Vector<double, 3> vector1({ 7, -1, 4.5 });
	cout << "vector1" << vector1 << endl;
	Vector<double, 3> vectorResult = matrix1 * vector1;
	cout << "Result of matrix1 * vector1: " << vectorResult << endl;

	SquareMatrix<double, 3> matrix2(
		array<Vector<double, 3>, 3>
		{
			Vector<double, 3>({ 0, 5, 1 }),
			Vector<double, 3>({0, 4, -1}),
			Vector<double, 3>({3, 1, -1})
		}
	);
	cout << "matrix2:" << endl << matrix2;

	cout << "Transpose matrix2:" << endl << matrix2.transpose();

	SquareMatrix<double, 3> matrixResult = matrix1 + matrix2;
	cout << "Result of matrix1 + matrix2: " << endl << matrixResult;

	matrixResult = matrix2 * 1.5;
	cout << "Result of matrix2 * 1.5: " << endl << matrixResult;

	matrixResult = matrix1 * matrix2;
	cout << "Result of matrix1 * matrix2: " << endl << matrixResult;
}

void matrix4Examples()
{
	cout << "----------- MATRIX4 -----------" << endl;
	SquareMatrix<double, 4> matrix1(
		array<Vector<double, 4>, 4>
		{
			Vector<double, 4>({ 2, 1, 3, -1 }),
			Vector<double, 4>({ 1, -3, 4, -3 }),
			Vector<double, 4>({0, 1, 1, 2}),
			Vector<double, 4>({ 2, -1, -3, -4 })
		}
	);
	Vector<double, 4> vector1({ 7, -1, 4.5, 2 });

	cout << "matrix1: " << endl << matrix1;
	cout << "vector1: " << vector1 << endl;

	Vector<double, 4> vectorResult = matrix1 * vector1;
	cout << "Result of matrix1 * vector1: " << vectorResult << endl;

	SquareMatrix<double, 4> matrix2(
		array<Vector<double, 4>, 4>
		{
			Vector<double, 4>({-1, 0, 2, 1}),
			Vector<double, 4>({0, -1, 1, 3}),
			Vector<double, 4>({1, 0, 0, -2}),
			Vector<double, 4>({-1, 1, 2, 3})
		}
	);
	cout << "matrix2: " << endl << matrix2;
	SquareMatrix<double, 4> matrixResult = matrix1 - matrix2;
	cout << "Result of matrix1 - matrix: " << endl << matrixResult;

	matrixResult = matrix1 / 2;
	cout << "Result of matrix1 / 2: " << endl << matrixResult;

	SquareMatrix<double, 4> identityMatrix(true);
	cout << "Identity Matrix4: " << endl << identityMatrix;

	matrixResult = matrix1 * matrix2;
	cout << "Result of matrix1 * matrix2: " << endl << matrixResult;
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

	Vector<double, 3> vector3_1({ 0, 3, 2 });
	cout << "vector3_1: " << vector3_1 << endl;
	Quaternion quaternion3 = Quaternion::getQuaternionByAngleAndVector(90, Vector<double, 3>({ 1, 0, 0 }));
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
	AABB aabb1(Vector<double, 3>({ 2, 2, 1 }), Vector<double, 3>({ 4, 4, 1 }));
	cout << "aabb1: " << aabb1 << endl;
	AABB aabb2(Vector<double, 3>({ 3, 4, 1 }), Vector<double, 3>({ 5, 5, 2 }));
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

Vector<double, 3> getCasteljauPoint(vector<Vector<double, 3>> &points, int r, int i, double t) {
	if (r == 0) return points[i];

	Vector<double, 3> v1 = getCasteljauPoint(points, r - 1, i, t);
	Vector<double, 3> v2 = getCasteljauPoint(points, r - 1, i + 1, t);

	return Vector<double, 3>({ ((1 - t) * v1[0] + t * v2[0]), ((1 - t) * v1[1] + t * v2[1]), ((1 - t) * v1[2] + t * v2[2]) });
}

void getCasteljauPoints(vector<Vector<double, 3>> &points) {
	Vector<double, 3> cp;

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
	bezierAnchors.push_back(Vector<double, 3>({ 20, 20, 1 }));
	bezierAnchors.push_back(Vector<double, 3>({ 400, 80, 1 }));
	bezierAnchors.push_back(Vector<double, 3>({ 420, 380, 1 }));
	bezierAnchors.push_back(Vector<double, 3>({ 620, 400, 1 }));
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
		glVertex3f(static_cast<GLfloat>(casteljauPoints[i][0]), (GLfloat)casteljauPoints[i][1], static_cast<GLfloat>(casteljauPoints[i][2]));
		glVertex3f(static_cast<GLfloat>(casteljauPoints[i + 1][0]), (GLfloat)casteljauPoints[i + 1][1], static_cast<GLfloat>(casteljauPoints[i + 1][2]));
		glEnd();
	}

	const int ANCHOR_SIZE = 2;
	glColor3f(0.f, 0.f, 1.f);
	for (unsigned int i = 0; i < bezierAnchors.size(); i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i][0]) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][1]) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][2]));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i][0]) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][1]) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][2]));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i][0]) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][1]) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][2]));
		glVertex3f(static_cast<GLfloat>(bezierAnchors[i][0]) - ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][1]) + ANCHOR_SIZE, static_cast<GLfloat>(bezierAnchors[i][2]));
		glEnd();
	}

	//Update screen
	glutSwapBuffers();
}