#include "camera.h"

void Camera :: init(double cameraDistance)
{
	viewAngle = 0.0;
	aspect = 1.0;
	nearDist = 1.0;
	farDist = 2.0;
	eye.set(1.0, 1.0, 1.0);
	u.set(0.0, 0.0, 1.0);
	v.set(0.0, 1.0, 0.0);
	n.set(-1.0, 0.0, 0.0);
	lookAt.set(0.0,0.0,0.0);
	lookAtOld.set(0.0,0.0,0.0);
	orbitDegree = 180.0;
	distance = cameraDistance;
}

void Camera :: setModelViewMatrix(void)
{
	GLfloat m[16];
	Vector3 eVec(eye.x, eye.y, eye.z); // a vector version of eye 
	m[0] =  u.x; m[4] =  u.y; m[8]  =  u.z;  m[12] = -eVec.dot(u);
	m[1] =  v.x; m[5] =  v.y; m[9]  =  v.z;  m[13] = -eVec.dot(v);
	m[2] =  n.x; m[6] =  n.y; m[10] =  n.z;  m[14] = -eVec.dot(n);
	m[3] =  0;   m[7] =  0;   m[11] =  0;    m[15] = 1.0;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m); // load OpenGL's modelview matrix
}

void Camera:: set(Point3 Eye, Point3 look, Vector3 up)     // create a modelview matrix and send it to OpenGL
{   
	eye.set(Eye);                                          // store the given eye position
	n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z); // make n
	u.set(up.cross(n));                                    // make u = up X n
	n.normalize(); u.normalize();                          // make them unit length
	v.set(n.cross(u));                                     // make v =  n X u
	setModelViewMatrix();                                  // tell OpenGL 
}

void Camera :: setLookAt(Point3 lookAtIn)
{
	lookAtOld = lookAt;
	lookAt = lookAtIn;
	Point3 change(lookAt.x - lookAtOld.x, lookAt.y - lookAtOld.y, lookAt.z - lookAtOld.z);
	Point3 Eye(eye.x+change.x, eye.y+change.y, eye.z+change.z);
	Vector3 Up(0.0f, 1.0f, 0.0f);
	set(Eye, lookAt, Up);
}

void Camera:: setShape(GLdouble vAng, GLdouble asp, GLdouble nearD, GLdouble farD) // define shape of view volume
{
	viewAngle = vAng;
	aspect = asp;
	nearDist = nearD;
	farDist = farD;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle, aspect, nearDist, farDist);  // tell OpenGL
}

void Camera:: slide(GLdouble delU, GLdouble delV, GLdouble delN) // slide the camera along its own axes
{
	eye.x += delU * u.x + delV * v.x + delN * n.x;
	eye.y += delU * u.y + delV * v.y + delN * n.y;
	eye.z += delU * u.z + delV * v.z + delN * n.z;
	setModelViewMatrix(); // tell OpenGL 
}

void Camera :: swing(double value)
{
	orbitDegree += value;
	if( orbitDegree > 360.0 )
	{
		orbitDegree -= 360.0;
	}
	if( orbitDegree < 0.0 )
	{
		orbitDegree += 360.0;
	}
	Point3 Eye(cos(orbitDegree*DEG2RAD)*distance+lookAt.x, eye.y+lookAt.y, sin(orbitDegree*DEG2RAD)*distance+lookAt.z);
	Point3 Look = lookAt;
	Vector3 Up(0.0, 1.0, 0.0);
	set(Eye, Look, Up);
}

void Camera :: zoom(double value)
{
	distance += value;
	if( distance <= 0.0 ) {
		distance = 0.001;
	}
	slide(0.0, 0.0, value);
}

void Camera :: move(double value)
{
	Point3 Eye(eye.x, eye.y+value, eye.z);
	Point3 Look = lookAt;
	Vector3 Up(0.0, 1.0, 0.0);
	set(Eye, Look, Up);
}

Point3 Camera :: getEyePos() {
	return eye;
}
