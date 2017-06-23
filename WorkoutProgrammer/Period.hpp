#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

namespace wp {

	class Period {

	private:
		const string name_ = "Period";

	protected:

		float volume_, intensity_;
		vector<shared_ptr<Period>> subPeriods_;

		virtual void displayInternal() {};
		virtual void periodizeInternal() = 0;

	public:
		Period(float volume, float intensity) :
			volume_(volume),
			intensity_(intensity)
		{

		}

		void addPeriod(Period * period) {
			shared_ptr<Period> p;
			p.reset(period);
			subPeriods_.push_back(p);
		}

		void display() {

			displayInternal();

			for (auto subPeriod : subPeriods_) {
				subPeriod->display();
			}

		}

		void periodize() {
			periodizeInternal();

			for (auto subPeriod : subPeriods_) {
				subPeriod->periodize();
			}
		}
	};
}
