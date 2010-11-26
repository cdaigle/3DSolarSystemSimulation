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
		void draw(void);
		void move(Planet);
		void toggle(void);
		void toggleOrbit(void);
		void drawOrbit(void);
		double getOrbitX(double);
		double getOrbitY(double);
		double getOrbitZ(double);
		int getPlanetId(void);
		bool isEnabled(void);

	private:
		int planetId;
		bool enabled;
		bool orbitEnabled;
		double daysToOrbit;
		double inclination;
		double eccentricity;
		Point3 planetPosition;
};
