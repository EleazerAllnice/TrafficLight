#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__
#include "TrafficLight.h"
#include "Parameters.h"
#include <iostream>
#include <string>

using namespace std;

TrafficLight::TrafficLight(LightColor color, int currentTimeOfLight, std::string ID)
{
	color = color; //default color
	currentTimeOfLight = currentTimeOfLight; //whatever the default color - get time from Simulation
	ID = ID;
}
TrafficLight::~TrafficLight(){}
void TrafficLight::update(int newTime)
{
	currentTimeOfLight = currentTimeOfLight - newTime; //newTime is incremented by 1 in Simulation

	if(currentTimeOfLight == 0 && color == LightColor::green)
	{
		if(TrafficLight::getID() == "NS")
		currentTimeOfLight = Parameters::getYellowNorthSouth();//get time of light time for whatever direction for yellow
		if(TrafficLight::getID() == "EW")
		currentTimeOfLight = Parameters::getYellowEastWest();

		color = LightColor::yellow;
	}

	if(currentTimeOfLight == 0 && color == LightColor::yellow)
	{
		//get time of light time for whatever direction for red
		if(TrafficLight::getID() == "NS")
		currentTimeOfLight = Parameters::getRedNorthSouth();//get time of light time for whatever direction for yellow
		if(TrafficLight::getID() == "EW")
		currentTimeOfLight = Parameters::getRedEastWest();

		color = LightColor::red;
	}

	if(currentTimeOfLight == 0 && color == LightColor::red)
	{
		//get time of light time for whatever direction for green
		if(TrafficLight::getID() == "NS")
		currentTimeOfLight = Parameters::getGreenNorthSouth();//get time of light time for whatever direction for yellow
		if(TrafficLight::getID() == "EW")
		currentTimeOfLight = Parameters::getGreenEastWest();

		color = LightColor::green;
	}

}

std::string TrafficLight::getColor()
{
	if(color == LightColor::red)
		return "red";
	else if(color == LightColor::green)
		return "green";
	else
		return "yellow";
}

int TrafficLight::getCurrentTime()
{
	return currentTimeOfLight;
}
std::string TrafficLight::getID()
{
	return ID;
}


#endif
