/**
 *  Deals with the different viewing modes
 */

#include "ViewMode.h"

void ViewMode :: incPlanetRadiusScale(void) { 
	planetRadiusScale += planetRadiusScaleModifier;
}
void ViewMode :: decPlanetRadiusScale(void) {
	planetRadiusScale -= planetRadiusScaleModifier; 
	if( planetRadiusScale <= 0.0 ) {
		planetRadiusScale = 0.0;
	}
}

void ViewMode :: incStarRadiusScale(void) {
	starRadiusScale += starRadiusScaleModifier;
}
void ViewMode :: decStarRadiusScale(void) {
	starRadiusScale -= starRadiusScaleModifier; 
	if( starRadiusScale <= 0.0 ) {
		starRadiusScale = 0.0;
	}
}

void ViewMode :: incSatelliteRadiusScale(void) { 
	satelliteRadiusScale += satelliteRadiusScaleModifier;
}
void ViewMode :: decSatelliteRadiusScale(void) {
	satelliteRadiusScale -= satelliteRadiusScaleModifier; 
	if( satelliteRadiusScale <= 0.0 ) {
		satelliteRadiusScale = 0.0;
	}
}

void ViewMode :: incPlanetOrbitScale(void) {
	planetOrbitScale += planetOrbitScaleModifier;
}
void ViewMode :: decPlanetOrbitScale(void) {
	planetOrbitScale -= planetOrbitScaleModifier;
	if( planetOrbitScale <= 0.0 ) {
		planetOrbitScale = 0.0;
	}
}

void ViewMode :: incSatelliteOrbitScale(void) {
	satelliteOrbitScale += satelliteOrbitScaleModifier;
}
void ViewMode :: decSatelliteOrbitScale(void) {
	satelliteOrbitScale -= satelliteOrbitScaleModifier;
	if( satelliteOrbitScale <= 0.0 ) {
		satelliteOrbitScale = 0.0;
	}
}

void ViewMode :: incHourIncrement(void) {
	hourIncrement += hourIncrementModifier;
}
void ViewMode :: decHourIncrement(void) {
	hourIncrement -= hourIncrementModifier;
	if( hourIncrement <= 0.0 ) {
		hourIncrement = 0.0;
	}
}

int ViewMode :: getId(void) {
	return orbitBodyId;
}
