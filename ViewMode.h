class ViewMode{
	private:
		string name;
		
		double planetRadiusScale;
		double planetRadiusScaleModifier;
		double starRadiusScale;
		double starRadiusScaleModifier;
		double satelliteRadiusScale;
		double satelliteRadiusScaleModifier;
		double orbitScale;
		double orbitScaleModifier;
		double satelliteOrbitScale;
		double satelliteOrbitScaleModifier;
		
		double hourIncrement;
		double hourIncrementModifier;
		
		double cameraDistance;

		int orbitBodyId;
	public:
		ViewMode(string nameIn, double pRS, double pRSM, double sRS, double sRSM, double oS, double oSM, double hI, double hIM, double cD, int oBI, double satelliteRadiusScaleIn, double satelliteRadiusScaleModifierIn, double satelliteOrbitScaleIn, double satelliteOrbitScaleModifierIn) {
			name = nameIn;
			
			planetRadiusScale = pRS;
			planetRadiusScaleModifier = pRSM;
			starRadiusScale = sRS;
			starRadiusScaleModifier = sRSM;
			satelliteRadiusScale = satelliteRadiusScaleIn;
			satelliteRadiusScaleModifier = satelliteRadiusScaleModifierIn;
			orbitScale = oS;
			orbitScaleModifier = oSM;
			satelliteOrbitScale = satelliteOrbitScaleIn;
			satelliteOrbitScaleModifier = satelliteOrbitScaleModifierIn;
			
			hourIncrement = hI;
			hourIncrementModifier = hIM;
			
			cameraDistance = cD;

			orbitBodyId = oBI;
		}
		void incrementPlanetRadiusScale(void) { 
			planetRadiusScale += planetRadiusScaleModifier;
		}
		void decrementPlanetRadiusScale(void) {
			planetRadiusScale -= planetRadiusScaleModifier; 
			if( planetRadiusScale <= 0.0 ) {
				planetRadiusScale = 0.0;
			}
		}
		double getPlanetRadiusScale(void) {
			return planetRadiusScale;
		}
		double getPlanetRadiusScaleModifier(void) {
			return planetRadiusScaleModifier;
		}

		void incrementStarRadiusScale(void) {
			starRadiusScale += starRadiusScaleModifier;
		}
		void decrementStarRadiusScale(void) {
			starRadiusScale -= starRadiusScaleModifier; 
			if( starRadiusScale <= 0.0 ) {
				starRadiusScale = 0.0;
			}
		}
		double getStarRadiusScale(void) {
			return starRadiusScale;
		}
		double getStarRadiusScaleModifier(void) {
			return starRadiusScaleModifier;
		}
		
		void incrementSatelliteRadiusScale(void) { 
			satelliteRadiusScale += satelliteRadiusScaleModifier;
		}
		void decrementSatelliteRadiusScale(void) {
			satelliteRadiusScale -= satelliteRadiusScaleModifier; 
			if( satelliteRadiusScale <= 0.0 ) {
				satelliteRadiusScale = 0.0;
			}
		}
		double getSatelliteRadiusScale(void) {
			return satelliteRadiusScale;
		}
		double getSatelliteRadiusScaleModifier(void) {
			return satelliteRadiusScaleModifier;
		}

		void incrementOrbitScale(void) {
			orbitScale += orbitScaleModifier;
		}
		void decrementOrbitScale(void) {
			orbitScale -= orbitScaleModifier;
			if( orbitScale <= 0.0 ) {
				orbitScale = 0.0;
			}
		}
		double getOrbitScale(void) {
			return orbitScale;
		}
		double getOrbitScaleModifier(void) {
			return orbitScaleModifier;
		}
		
		void incrementSatelliteOrbitScale(void) {
			satelliteOrbitScale += satelliteOrbitScaleModifier;
		}
		void decrementSatelliteOrbitScale(void) {
			satelliteOrbitScale -= satelliteOrbitScaleModifier;
			if( satelliteOrbitScale <= 0.0 ) {
				satelliteOrbitScale = 0.0;
			}
		}
		double getSatelliteOrbitScale(void) {
			return satelliteOrbitScale;
		}
		double getSatelliteOrbitScaleModifier(void) {
			return satelliteOrbitScaleModifier;
		}

		void incrementHourIncrement(void) {
			hourIncrement += hourIncrementModifier;
		}
		void decrementHourIncrement(void) {
			hourIncrement -= hourIncrementModifier;
			if( hourIncrement <= 0.0 ) {
				hourIncrement = 0.0;
			}
		}
		double getHourIncrement(void) {
			return hourIncrement;
		}
		double getHourIncrementModifier(void) {
			return hourIncrementModifier;
		}
		
		double getInitialCameraDistance(void) {
			return cameraDistance;
		}
		Point3 getInitialEyePosition(void) {
			float x = -10.0f;
			float y = 1.2f;
			float z = 0.0f;
			return Point3(x,y,z);
		}
		Point3 getInitialLookPosition(void) {
			float x = 0.0f;
			float y = 0.0f;
			float z = 0.0f;
			return Point3(x,y,z);
		}
		int getId(void) {
			return orbitBodyId;
		}
};
