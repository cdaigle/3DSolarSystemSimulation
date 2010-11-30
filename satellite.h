/**
 * satellite.h
 */

class Satellite : public Sphere
{
	public:
		Satellite() : Sphere() {}
		Satellite(
			string nameIn, 
			double radiusIn, 
			double orbitDistance, 
			double albeldoIn, 
			double daysToOrbitIn, 
			double inclinationIn, 
			double eccentricityIn, 
			string texturePathIn, 
			int planetIdIn
		) :	Sphere(
			nameIn,
			radiusIn,
			orbitDistance,
			albeldoIn,
			0.0,
			texturePathIn
		) 
		{ 
			daysToOrbit = daysToOrbitIn;
			inclination = inclinationIn;
			eccentricity = eccentricityIn;
			planetId = planetIdIn;
			enabled = true;
			orbitEnabled = true;
			planetPosition.set(0.0f, 0.0f, 0.0f);
		}
		int planetId;

		void draw(void);
		void move(Point3);
		void toggle(void);
		void toggleOrbit(void);
		void drawOrbit(void);
		double getOrbitX(double);
		double getOrbitY(double);
		double getOrbitZ(double);
		bool isEnabled(void);
		bool isOrbitEnabled(void);
		void setEnabled(bool);
		void setOrbitEnabled(bool);
		double getRadius(void);
		double getOrbitDistance(void);

	private:
		bool enabled, orbitEnabled;
		double daysToOrbit, inclination, eccentricity;
		Point3 planetPosition;
};
