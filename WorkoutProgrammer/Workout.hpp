#pragma once

#include "Period.hpp"

namespace wp {

	class Workout : public Period {

		const string name_ = "Workout";

		void displayInternal() {

			static int number;
			number++;

			cout << endl;
			cout << "================" << endl;
			cout << name_ << " #" << number << endl;
		}

		void periodizeInternal() {

		}

	public:
		Workout(float volume, float intensity) :
			Period(volume, intensity)
		{

		}

	};
}