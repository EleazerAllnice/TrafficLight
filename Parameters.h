#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

#include <iostream>

class Parameters
{
	private:
		int static maximum_simulated_time;
		int static number_of_sections_before_intersection;
		int static green_north_south;
		int static yellow_north_south;
		int static green_east_west;
		int static yellow_east_west;
		double static prob_new_vehicle_northbound;
		double static prob_new_vehicle_southbound;
		double static prob_new_vehicle_eastbound;
		double static prob_new_vehicle_westbound;
		double static proportion_of_cars;
		double static proportion_of_SUVs;
		double static proportion_of_trucks;
		double static proportion_right_turn_cars;
		double static proportion_left_turn_cars;
		double static proportion_right_turn_SUVs;
		double static proportion_left_turn_SUVs;
		double static proportion_right_turn_trucks;
		double static proportion_left_turn_trucks;
		//not read in by file
		int static red_east_west;
		int static red_north_south; //set these lengths of time

		public:
		void static readInputFile(std::string filename);
		int static getMaximumSimulatedTime();
		int static getNumberOfSections();
		int static getYellowNorthSouth();
		int static getYellowEastWest();
		int static getGreenNorthSouth();
		int static getGreenEastWest();
		int static getRedNorthSouth();
		int static getRedEastWest();
		double static getProbNewVehicleNorthbound();
		double static getProbNewVehicleSouthbound();
		double static getProbNewVehicleEastbound();
		double static getProbNewVehicleWestbound();
		double static getProportionOfCars();
		double static getProportionOfSUVs();
		double static getProportionOfTrucks();
		double static getProportionOfRightTurnCars();
		double static getProportionOfRightTurnSUVs();
		double static getProportionOfRightTurnTrucks();
};

#endif
