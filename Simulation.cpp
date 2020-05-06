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
		std::cout<<"called getNorttbound()" << std::endl;
		std::vector<VehicleBase*> southbound = road.getSouthbound();
		std::cout<<"called getSouthbound()" << std::endl;
		std::vector<VehicleBase*> eastbound = road.getEastbound();
		std::cout<<"called getEastbound()" << std::endl;
		std::vector<VehicleBase*> westbound = road.getWestbound();
		std::cout<<"called getWestbound()" << std::endl;

		animate.setVehiclesWestbound(westbound);
		animate.setVehiclesEastbound(eastbound);
		animate.setVehiclesSouthbound(southbound);
		animate.setVehiclesNorthbound(eastbound);

        std::cout << "finished setVehiclesNorthbound" << std::endl;
		road.moveCars(i);
		t1.update(i);
		t2.update(i);

		animate.draw(i);
		std::cout << "finished draw()" << std::endl;
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
