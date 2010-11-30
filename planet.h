/**
 * planet.h
 */

class Planet : public Sphere
{
	public:
		Planet(): Sphere(){}
		Planet(
			string nameIn, 
			double radiusIn, 
			double orbitDistance, 
			double albeldoIn, 
			double daysToOrbitIn, 
			double inclinationIn, 
			double eccentricityIn, 
			double tiltIn,
			double daysToRotateIn,
			string texturePathIn
		) : Sphere (
			nameIn, 
			radiusIn, 
			orbitDistance, 
			albeldoIn, 
			tiltIn,
			texturePathIn
		)
		{ 
			enabled = true;
			orbitEnabled = true;
			daysToOrbit = daysToOrbitIn;
			inclination = inclinationIn;
			eccentricity = eccentricityIn;
			daysToRotate = daysToRotateIn;
		}
		double inclination;

		void move(void);
		void toggle(void);
		void toggleOrbit(void);
		void draw(void);
		void drawOrbit(void);
		double getSemiMajorAxis(void);
		double getSemiMinorAxis(void);
		double getOrbitX(double);
		double getOrbitY(void);
		double getOrbitZ(double);
		bool isEnabled(void);
		bool isOrbitEnabled(void);
		void setEnabled(bool);
		void setOrbitEnabled(bool);
		double getRadius(void);

	private:
		bool enabled, orbitEnabled;
		double daysToOrbit, daysToRotate, eccentricity;		
};
