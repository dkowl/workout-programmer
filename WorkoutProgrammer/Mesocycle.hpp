#pragma once

#include "Period.hpp"
#include "Microcycle.hpp"

namespace wp {

	class Mesocycle : public Period {

		const string name_ = "Mesocycle"; 
		
		void displayInternal() {

			static int number;
			number++;

			cout << endl;
			cout << "==========================" << endl;
			cout << name_ << " #" << number << endl;
			cout << "==========================" << endl;
		}

		void periodizeInternal(){
			addPeriod(new Microcycle(volume_, intensity_*0.8));
			addPeriod(new Microcycle(volume_*0.6, intensity_*0.9));
			addPeriod(new Microcycle(volume_*0.2, intensity_ * 1));
			addPeriod(new Microcycle(volume_*0.6, intensity_*0.75));
		}

	public:

		Mesocycle(float value, float intensity) :
			Period(value, intensity)
		{

		}
	};
}