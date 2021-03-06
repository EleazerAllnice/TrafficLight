#ifndef __ROADWAY_CPP__
#define __ROADWAY_CPP__
#include "Roadway.h"
#include <iostream>

Roadway::Roadway(int rowNum, int colNum)
{
    // create 2d Array to represent Roadway.
    row = rowNum;
    col = colNum;


    for(int r = 0; r < this->row; r++)
    {
        std::vector<Vehicle*> v1;
      for(int c = 0; c < this->col; c++)
      {
          v1.push_back(nullptr);
      }
      lanes.push_back(v1);
    }


}

//adds vehicle
void Roadway::addVehicle(Vehicle* vehicle)
{
    carList.push_back(vehicle);

    int startingSquareRow = 0;
    int startingSquareCol = 0;
    int rowDirection = 0;
    int colDirection = 0;

    //NORTH
    if(vehicle->getVehicleOriginalDirection() == Direction::north)
    {
        int startingSquareRow = row-1;
        int startingSquareCol = col/2+1;
        int rowDirection = -1;
        int colDirection = 0;
    }

    //SOUTH
    else if(vehicle->getVehicleOriginalDirection() == Direction::south)
    {
      int startingSquareRow = 0;
      int startingSquareCol = col/2;
      int rowDirection = 1;
      int colDirection = 0;
    }

    //EAST
    else if(vehicle->getVehicleOriginalDirection() == Direction::east)
    {
      int startingSquareRow = row/2;
      int startingSquareCol = 0;
      int rowDirection = 0;
      int colDirection = 1;
    }

    //WEST
    else
    {
      int startingSquareRow = row/2+1;
      int startingSquareCol = col-1;
      int rowDirection = 0;
      int colDirection = -1;
    }

    for(int i = 0; i < vehicle->getGridSize(); i++)
    {
      lanes[startingSquareRow][startingSquareCol] = vehicle;
      startingSquareRow += rowDirection;
      startingSquareCol += colDirection;
    }

}

Roadway::~Roadway(){}

bool Roadway::isNextMoveIntersection(Vehicle* vehicle, int row, int col)
{
    //Check current lane and add 1 to get to intersection
    if(vehicle->getVehicleOriginalDirection() == Direction::north)
    {
        int rowDirection = -1;
        int colDirection = 0;
        row  = row + rowDirection;
        col = col + colDirection;
    }

    //SOUTH
    else if(vehicle->getVehicleOriginalDirection() == Direction::south)
    {
      int rowDirection = 1;
      int colDirection = 0;
      row  = row + rowDirection;
      col = col + colDirection;
    }

    //EAST
    else if(vehicle->getVehicleOriginalDirection() == Direction::east)
    {
      int rowDirection = 0;
      int colDirection = 1;
      row  = row + rowDirection;
      col = col + colDirection;
    }

    //WEST
    else
    {
      int rowDirection = 0;
      int colDirection = -1;
      row  = row + rowDirection;
      col = col + colDirection;
    }

    struct intersection sb = {row/2, col/2};
    struct intersection nb = {row/2, (col/2)+1};
    struct intersection eb = {(row/2)+1, col/2};
    struct intersection wb = {row/2+1, (col/2)+1};


    //
    if((sb.row == row) && sb.col == col){return true;}
    else if((nb.row == row) && nb.col == col){return true;}
    else if((eb.row == row) && eb.col == col){return true;}
    else if((wb.row == row) && wb.col == col){return true;}
    else return false;

}
bool Roadway::isNextOccupied(Vehicle* vehicle)
{
  if(vehicle->getVehicleOriginalDirection() == Direction::north)
  {
      int rowDirection = -1;
      int colDirection = 0;
      row  = row + rowDirection;
      col = col + colDirection;
  }

  //SOUTH
  else if(vehicle->getVehicleOriginalDirection() == Direction::south)
  {
    int rowDirection = 1;
    int colDirection = 0;
    row  = row + rowDirection;
    col = col + colDirection;
  }

  //EAST
  else if(vehicle->getVehicleOriginalDirection() == Direction::east)
  {
    int rowDirection = 0;
    int colDirection = 1;
    row  = row + rowDirection;
    col = col + colDirection;
  }

  //WEST
  else
  {
    int rowDirection = 0;
    int colDirection = -1;
    row  = row + rowDirection;
    col = col + colDirection;
  }

  if(lanes[row][col] == nullptr)
  {
    return false
  }
  return true
}

void Roadway::moveCars()
{
  for(int i = 0; i < carList.size(); i++)
  {
    if(carlist.at(i).get)


  }

}

// Traffic light
TrafficLight Roadway::getNSlight()
{
    return nsLight;
}
TrafficLight Roadway::getEWlight()
{
    return ewLight;
}

std::vector<VehicleBase*> Roadway::getNorthbound()
{
  std::vector<VehicleBase*> northbound;
  for(int i = 1; i < this->row + 1; i++)
  {
    northbound.push_back(lanes[row-i][col/2+1]);
  }
  return northbound;

}
std::vector<VehicleBase*> Roadway::getSouthbound()
{
  std::vector<VehicleBase*> southbound;
  for(int i = 0; i < this->row; i++)
  {

    southbound.push_back(lanes[0+i][col/2]);
  }
  return southbound;
}
std::vector<VehicleBase*> Roadway::getWestbound()
{
  std::vector<VehicleBase*> westbound;
  for(int i = 0; i < this->row; i++)
  {
    westbound.push_back(lanes[row/2+1][0+i]);
  }
  return westbound;
}
std::vector<VehicleBase*> Roadway::getEastbound()
{
  std::vector<VehicleBase*> eastbound;
  for(int i = 1; i < this->row+1; i++)
  {
    eastbound.push_back(lanes[row/2][col-i]);
  }
  return eastbound;
}


#endif
