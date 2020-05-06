#include "Simulation.h"
#include "Parameters.h"
#include <iostream>
#include "random.h"


int main(int argc, char* argv[]) //command-line arguments are the the intial seed and input file
{
	std::cout<< "Time: " << Parameters::getMaximumSimulatedTime() << std::endl;
	//all animation stuff happens in main()
	Parameters::readInputFile(argv[1]);
	std::cout << argv[1] << std::endl;
	std::cout<< "Time: " << Parameters::getMaximumSimulatedTime() << std::endl;
	Random ram = Random(argc);
	Simulation::run();



	return(0);
}
