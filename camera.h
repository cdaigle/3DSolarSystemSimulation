class Camera {
	private:
		Point3 eye, lookAt;
		Vector3 u,v,n;
		GLdouble viewAngle, aspect, nearDist, farDist; // view volume shape
		double orbitDegree, distance;
		void setModelViewMatrix(); // tell OpenGL where the camera is

	public:
		Camera(double);                                             // default constructor
		void set(Point3 eye, Point3 look, Vector3 up);              // like gluLookAt()
		void roll(GLdouble angle);                                  // roll it
		void yaw(GLdouble angle);                                   // yaw it
		void pitch(GLdouble angle);                                 // pitch it
		void slide(GLdouble delU, GLdouble delV, GLdouble delN);    // slide it
		void setShape(GLdouble vAng, GLdouble asp, GLdouble nearD, GLdouble farD);
		void swing(double);
		void zoom(double);
		void setLookAt(Point3);
		void setView(double);
		Point3 getEyePosition(void);
		double getCameraDistance(void);
};
