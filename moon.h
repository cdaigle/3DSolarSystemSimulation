/**
 * moon.h
 */

class Moon : public Sphere{
	public:
		Moon(string nameIn, double radiusIn, double orbitDistance, double albeldoIn, string texturePathIn) : 
			Sphere(nameIn, radiusIn, orbitDistance, albeldoIn, texturePathIn) { }
	private:
};
