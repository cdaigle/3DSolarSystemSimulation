#include "camera.h"

Camera::Camera(double cameraDistance)
{
	viewAngle = 0.0;
	aspect = 1.0;
	nearDist = 1.0;
	farDist = 2.0;
	eye.set(1.0, 1.0, 1.0);
	u.set(0.0, 0.0, 1.0);
	v.set(0.0, 1.0, 0.0);
	n.set(-1.0, 0.0, 0.0);
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
	lookAt = lookAtIn;
	Vector3 Up(0.0f, 1.0f, 0.0f);
	set(eye, lookAt, Up);
}

void Camera :: setView(double initCameraDistance)
{
	orbitDegree = 0.0;
	distance = initCameraDistance;
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

void Camera:: roll(GLdouble angle) //roll the camera through angle degrees
{
	GLdouble cs = cos(3.14159265 /180 * angle);
	GLdouble sn = sin(3.14159265 /180 * angle);
	Vector3 t(u); //remember old u
	u.set(cs*t.x - sn*v.x, cs*t.y - sn*v.y, cs*t.z - sn*v.z);
	v.set(sn*t.x + cs*v.x, sn*t.y + cs*v.y, sn*t.z + cs*v.z);
	setModelViewMatrix();	
}

void Camera:: yaw(GLdouble angle) //yaw the camera through angle degrees
{
	GLdouble cs = cos(3.14159265 /180 * angle);
	GLdouble sn = sin(3.14159265 /180 * angle);
	Vector3 t(n); //remember old u
	n.set(cs*t.x + sn*u.x, cs*t.y + sn*u.y, cs*t.z + sn*u.z);
	u.set(-sn*t.x + cs*u.x, -sn*t.y + cs*u.y, -sn*t.z + cs*u.z);
	setModelViewMatrix();	
}

void Camera:: pitch(GLdouble angle) //pitch the camera through angle degrees
{
	GLdouble cs = cos(3.14159265 /180 * angle);
	GLdouble sn = sin(3.14159265 /180 * angle);
	Vector3 t(v); //remember old u
	v.set(cs*t.x + sn*n.x, cs*t.y + sn*n.y, cs*t.z + sn*n.z);
	n.set(-sn*t.x + cs*n.x, -sn*t.y + cs*n.y, -sn*t.z + cs*n.z);
	setModelViewMatrix();	
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
	Point3 Eye(cos(orbitDegree*DEG2RAD)*distance, eye.y, sin(orbitDegree*DEG2RAD)*distance);
	Point3 Look = lookAt;
	Vector3 Up(0.0, 1.0, 0.0);
	set(Eye, Look, Up);
}

void Camera :: zoom(double value)
{
	distance += value;
	if( distance < 0.0 ) {
		distance = 0.0;
	}
	slide(0.0, 0.0, value);
}

Point3 Camera :: getEyePos() {
	return eye;
}
