#pragma once

#include <string>
#include <math.h>
#include <algorithm>
#include "Period.hpp"
#include "Wathan.hpp"
#include "Data.hpp"

using namespace std;

float round(float x, float multiple) {
	return round(x / multiple)*multiple;
}

namespace wp {

	class Exercise : public Period {

		string name_;
		float oneRepMax_, weight_;
		int sets_, reps_;

		void displayInternal() {
			cout << name_ << " " << sets_ << "x";
			cout<< reps_ << " - " << round (weight_, 2.5)<<"kg"<<endl;
		}

		void periodizeInternal() {

			sets_ = floor(volume_ * 5);

			if (name_ == "Deadlift") {
				reps_ = 3;
			}
			else {
				reps_ = 5;
			}

			weight_ = wathan(1, intensity_ * oneRepMax_, reps_);

			if (name_ == "Chinup") {
				reps_ = max(2.0f, round(wathanFixedWeight(oneRepMax_*intensity_, Data::myWeight)));
				weight_ = Data::myWeight;
			}
		}

	public:
		Exercise(float volume, float intensity, string name, float oneRepMax) :
			Period(volume, intensity),
			name_(name),
			oneRepMax_(oneRepMax)
		{

		}
	};
}
