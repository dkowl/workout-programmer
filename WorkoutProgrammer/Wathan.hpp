#pragma once

#include <math.h>

namespace wp {

	namespace Wathan {
		const float A = 100, B = 48.8, C = 53.8, D = -0.075;
	}

	using namespace Wathan;

	float wathan(int reps, int weight, int desiredReps) {

		float oneRepMax_ = (A * weight) / (B + C*exp(D*reps));
		return oneRepMax_ * (B + C*exp(D*desiredReps)) / A;
		
	}

	float wathanFixedWeight(int oneRepMax, int desiredWeight) {
		return log(((A*desiredWeight / oneRepMax) - B) / C) / D;
	}
}
