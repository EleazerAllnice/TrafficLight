#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__
#include <string>
enum class LightColor   {green, yellow, red};

class TrafficLight
{
	private:
		LightColor color;
		int currentTimeOfLight;
		std::string ID;
	public:
		TrafficLight(LightColor color, int currentTimeOfLight, std::string ID); //default constructor
		~TrafficLight(); //deconstructor
		//void changeColor(); may not need this because of update function
		std::string getColor();
		int getCurrentTime();
		std::string getID();
		void update(int newTime); //takes in the current time to update light color
						 // time for each light color will be assigned in the Roadway class

};

#endif
