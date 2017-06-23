#include <iostream>
#include <string>

#include "Macrocycle.hpp"
#include "Exercise.hpp"
#include "Wathan.hpp"

using namespace std;
using namespace wp;

float Macrocycle::intensityIncrement_ = 0.05;
int Macrocycle::length_ = 1;

int main() {

	Macrocycle macrocycle(1, 1);
	macrocycle.periodize();
	macrocycle.display();

	system("PAUSE");
	return 0;

}