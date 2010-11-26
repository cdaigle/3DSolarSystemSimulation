/**
 * ring.h
 */

class Ring{
	private:
		string texturePath;
		string name;
		double innerRadius;
		double outerRadius;

	public:
		Ring(string nameIn, double innerRadiusIn, double outerRadiusIn, string texturePathIn, int planetIn) {
			innerRadius = innerRadiusIn;
			outerRadius = outerRadiusIn;
			texturePath = texturePathIn;
			name = nameIn;
			planetId = planetIn;
		}
		int textureId;
		int planetId;

		double getInnerRadius(void) {
			return innerRadius;
		}
		double getOuterRadius(void) {
			return outerRadius;
		}

		void drawRing(double, Point3);
		string getTexturePath(void){ return texturePath; }
		string getName(void) { return name; }
};
