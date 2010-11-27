class ViewMode
{
	private:
		string name;

	public:
		double planetRadiusScale;
		double planetRadiusScaleModifier;
		double starRadiusScale;
		double starRadiusScaleModifier;
		double satelliteRadiusScale;
		double satelliteRadiusScaleModifier;

		double planetOrbitScale;
		double planetOrbitScaleModifier;
		double satelliteOrbitScale;
		double satelliteOrbitScaleModifier;
		
		double hourIncrement;
		double hourIncrementModifier;
		
		double initCameraDistance;

		int orbitBodyId;
		Point3 initEyePos;
		Point3 initLookPos;

		ViewMode(
			string nameIn, 
			double pRS, 
			double pRSM, 
			double starRS, 
			double starRSM, 
			double pOS, 
			double pOSM, 
			double hI, 
			double hIM, 
			double cD, 
			int oBI, 
			double satelliteRS, 
			double satelliteRSM, 
			double satelliteOS, 
			double satelliteOSM	)
		{
			name = nameIn;
			
			planetRadiusScale = pRS;
			planetRadiusScaleModifier = pRSM;
			starRadiusScale = starRS;
			starRadiusScaleModifier = starRSM;
			satelliteRadiusScale = satelliteRS;
			satelliteRadiusScaleModifier = satelliteRSM;

			planetOrbitScale = pOS;
			planetOrbitScaleModifier = pOSM;
			satelliteOrbitScale = satelliteOS;
			satelliteOrbitScaleModifier = satelliteOSM;
			
			hourIncrement = hI;
			hourIncrementModifier = hIM;
			
			initCameraDistance = cD;

			orbitBodyId = oBI;
			initEyePos.set(-10.0f, 1.2f, 0.0f);
			initLookPos.set(0.0f, 0.0f, 0.0f);
		}
		void incPlanetRadiusScale(void);
		void decPlanetRadiusScale(void);

		void incStarRadiusScale(void);
		void decStarRadiusScale(void);
		
		void incSatelliteRadiusScale(void);
		void decSatelliteRadiusScale(void);

		void incPlanetOrbitScale(void);
		void decPlanetOrbitScale(void);
		
		void incSatelliteOrbitScale(void);
		void decSatelliteOrbitScale(void);

		void incHourIncrement(void);
		void decHourIncrement(void);

		int getId(void);
		
		string getName(void)
		{
			return name;
		}
};
