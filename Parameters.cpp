#ifndef __PARAMETERS_CPP__
#define __PARAMETERS_CPP__
#include "Parameters.h"
#include <fstream>
int Parameters::green_north_south;
int Parameters::yellow_north_south;
int Parameters::green_east_west;
int Parameters::yellow_east_west;
int Parameters::maximum_simulated_time;
int Parameters::number_of_sections_before_intersection;
double Parameters::prob_new_vehicle_northbound;
double Parameters::prob_new_vehicle_southbound;
double Parameters::prob_new_vehicle_eastbound;
double Parameters::prob_new_vehicle_westbound;
double Parameters::proportion_of_cars;
double Parameters::proportion_of_SUVs;
double Parameters::proportion_of_trucks = 1 - proportion_of_SUVs - proportion_of_cars;
double Parameters::proportion_right_turn_cars;
double Parameters::proportion_left_turn_cars;
double Parameters::proportion_right_turn_SUVs;
double Parameters::proportion_left_turn_SUVs;
double Parameters::proportion_right_turn_trucks;
double Parameters::proportion_left_turn_trucks;
int Parameters::red_east_west = yellow_north_south + green_north_south;
int Parameters::red_north_south = yellow_east_west + green_east_west;

int Parameters::getMaximumSimulatedTime()
{
	return maximum_simulated_time;
}
int Parameters::getNumberOfSections()
{
	return number_of_sections_before_intersection;
}
int Parameters::getYellowNorthSouth()
{
	return yellow_north_south;
}
int Parameters::getYellowEastWest()
{
	return yellow_east_west;
}
int Parameters::getGreenNorthSouth()
{
	return green_north_south;
}
int Parameters::getGreenEastWest()
{
	return green_east_west;
}
int Parameters::getRedNorthSouth()
{
	return red_north_south;
}
int Parameters::getRedEastWest()
{
	return red_east_west;
}
double Parameters::getProbNewVehicleNorthbound()
{
	return prob_new_vehicle_northbound;
}
double Parameters::getProbNewVehicleSouthbound()
{
	return prob_new_vehicle_southbound;
}
double Parameters::getProbNewVehicleEastbound()
{
	return prob_new_vehicle_eastbound;
}
double Parameters::getProbNewVehicleWestbound()
{
	return prob_new_vehicle_westbound;
}
double Parameters::getProportionOfCars()
{
	return proportion_of_cars;
}
double Parameters::getProportionOfSUVs()
{
	return proportion_of_SUVs;
}
double Parameters::getProportionOfTrucks()
{
	return proportion_of_trucks;
}
double Parameters::getProportionOfRightTurnCars()
{
	return proportion_right_turn_cars;
}
double Parameters::getProportionOfRightTurnSUVs()
{
	return proportion_right_turn_SUVs;
}
double Parameters::getProportionOfRightTurnTrucks()
{
	return proportion_right_turn_trucks;
}

void Parameters::readInputFile(std::string filename)
{
	std::ifstream infile(filename); // to open file reading
	std::string line; //to declare the line being used to read
	if(!infile)
    { std::cerr << "\nError opening input file: " << filename << "\n" << std::endl;
	exit(1);
}
        std::string tag;
        std::string value;
		infile >> tag >> value;
		maximum_simulated_time = stoi(value);
		infile >> tag >> value;
		number_of_sections_before_intersection = stoi(value);
		infile >> tag >> value;
		green_north_south = stoi(value);
		infile >> tag >> value;
		yellow_north_south = stoi(value);
		infile >> tag >> value;
		green_east_west = stoi(value);
		infile >> tag >> value;
		yellow_east_west = stoi(value);
		infile >> tag >> value;	
     	prob_new_vehicle_northbound = stod(value);
		infile >> tag >> value;
		prob_new_vehicle_southbound = stod(value);
		infile >> tag >> value;
		prob_new_vehicle_eastbound = stod(value);
		infile >> tag >> value;
		prob_new_vehicle_westbound = stod(value);
		infile >> tag >> value;
		proportion_of_cars = stod(value);
		infile >> tag >> value;
		proportion_of_SUVs = stod(value);
		infile >> tag >> value;
		proportion_right_turn_cars = stod(value);
		infile >> tag >> value;
		proportion_left_turn_cars = stod(value);
		infile >> tag >> value;
		proportion_right_turn_SUVs = stod(value);
		infile >> tag >> value;
		proportion_left_turn_SUVs = stod(value);
		infile >> tag >> value;
		proportion_right_turn_trucks = stod(value);
		infile >> tag >> value;
		proportion_left_turn_trucks = stod(value);
		infile.close();

}


#endif
