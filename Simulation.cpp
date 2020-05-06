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

	int halfsize = Parameters::getNumberOfSections();
	Animator animate(halfsize);

	std::cout<< "Time: " << Parameters::getMaximumSimulatedTime() << std::endl;

	for(int i = 0; i < Parameters::getMaximumSimulatedTime(); i++)
	{
		std::cout<< "In the for loop" << std::endl;
		std::vector<VehicleBase*> northbound = road.getNorthbound();
		std::vector<VehicleBase*> southbound = road.getSouthbound();
		std::vector<VehicleBase*> eastbound = road.getEastbound();
		std::vector<VehicleBase*> westbound = road.getWestbound();
		animate.setVehiclesWestbound(westbound);
		animate.setVehiclesEastbound(eastbound);
		animate.setVehiclesSouthbound(southbound);
		animate.setVehiclesNorthbound(eastbound);

		road.moveCars(i);
		t1.update(i);
		t2.update(i);

		animate.draw(i);
	}

}

// int main(int argc, char* argv[]) //command-line arguments are the the intial seed and input file
// {
// 	std::cout<< "Time: " << Parameters::getMaximumSimulatedTime() << std::endl;
// 	//all animation stuff happens in main()
// 	Parameters::readInputFile(argv[2]);
// 	std::cout<< "Time: " << Parameters::getMaximumSimulatedTime() << std::endl;
// 	Random ram = Random(argc);
// 	Simulation::run();
//
//
//
// 	return(0);
// }

#endif
