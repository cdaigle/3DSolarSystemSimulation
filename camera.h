class Camera {
	private:
		Point3 eye, lookAt, lookAtOld;
		Vector3 u,v,n;
		GLdouble viewAngle, aspect, nearDist, farDist; // view volume shape
		void setModelViewMatrix(); // tell OpenGL where the camera is

	public:
		Camera() {}
		void init(double);
		double orbitDegree, distance;
		void set(Point3 eye, Point3 look, Vector3 up);
		void slide(GLdouble delU, GLdouble delV, GLdouble delN);
		void setShape(GLdouble vAng, GLdouble asp, GLdouble nearD, GLdouble farD);
		void swing(double);
		void zoom(double);
		void move(double);
		void setLookAt(Point3);
		void setView(double);
		Point3 getEyePos(void);
		double getCameraDistance(void);
};
