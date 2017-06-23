#pragma once

#include "Period.hpp"
#include "Workout.hpp"
#include "Exercise.hpp"
#include "Wathan.hpp"

namespace wp {

	class Microcycle : public Period {

		const string name_ = "Microcycle";

		Exercise squat;
		Exercise benchPress;
		Exercise pendlayRow;
		Exercise deadlift;
		Exercise chinup;
		Exercise ohp;

		Workout workout1, workout2;

		void displayInternal() {

			static int number;
			number++;

			cout << endl;
			cout << "=====================" << endl;
			cout << name_ << " #" << number << endl;
			cout << "=====================" << endl;
		}

		void periodizeInternal() {
		}

	public:

		Microcycle(float volume, float intensity) :
			Period(volume, intensity),
			squat(volume_, intensity_, "Squat", wathan(5, 105, 1)),
			benchPress(volume_, intensity_, "Bench Press", wathan(5, 67.5, 1)),
			pendlayRow(volume_, intensity_, "Pendlay Row", wathan(5, 57.5, 1)),
			deadlift(volume_, intensity_, "Deadlift", 125),
			chinup(volume_, intensity_, "Chinup", wathan(8, Data::myWeight, 1)),
			ohp(volume_, intensity_, "Overhead Press", wathan(5, 50, 1)),
			workout1(volume_, intensity_),
			workout2(volume_, intensity_)
		{
			workout1.addPeriod(new Exercise(squat));
			workout1.addPeriod(new Exercise(benchPress));
			workout1.addPeriod(new Exercise(pendlayRow));
			addPeriod(new Workout(workout1));

			workout2.addPeriod(new Exercise(deadlift));
			workout2.addPeriod(new Exercise(chinup));
			workout2.addPeriod(new Exercise(ohp));
			addPeriod(new Workout(workout2));
			
		}

	};
}