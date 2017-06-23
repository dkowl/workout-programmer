#pragma once
#include <string>

#include "LoggedProperty.hpp"

using namespace std;

namespace wp {

	class Profile {

	private:
		LoggedProperty<string> name_;
		LoggedProperty<float> 
			weight_;


	};
}