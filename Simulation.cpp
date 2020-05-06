#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include "Simulation.h"
#include "TrafficLight.h"
#include "Parameters.h"
#include "Animator.h"
#include "Roadway.h"
#include <random>
#include "random.h"

using namespace std;

void Simulation::run()
{

	int rowlength = 2 * Parameters::getNumberOfSections() + 2;
	int collength = 2 * Parameters::getNumberOfSections() + 2;
    Roadway road(rowlength,collength);
	TrafficLight t1 = road.getEWlight();
	TrafficLight t2 = road.getNSlight();

	int i = 0;
	while(i <= Parameters::getMaximumSimulatedTime())
	{
		road.moveCars(i);
		t1.update(i);
		t2.update(i);
		i++;
	}
}

int main(int argc, char* argv[]) //command-line arguments are the the intial seed and input file
{
	//all animation stuff happens in main()
	Parameters::readInputFile(argv[2]);
	Random ram = Random(argc);
	Simulation::run();
	int halfsize = Parameters::getNumberOfSections();
	Animator animate(halfsize);

	return(0);
}

#endif
