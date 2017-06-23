#pragma once

#include "Period.hpp"
#include "Mesocycle.hpp"

namespace wp {

	class Macrocycle : public Period {

		const string name_ = "Macrocycle";

		void displayInternal() {

			static int number;
			number++;

			cout << endl;
			cout << "===============================" << endl;
			cout << name_ << " #" << number << endl;
			cout << "===============================" << endl;
		}

		void periodizeInternal() {
			for (int i = 0; i < length_; i++) {
				addPeriod(new Mesocycle(volume_, intensity_*(1 + intensityIncrement_*i)));
			}
		}

	public:

		static float intensityIncrement_;
		static int length_;

		Macrocycle(float volume, float intensity):
			Period(volume, intensity)
		{

		}

	};
}