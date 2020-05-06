#ifndef __VEHICLE_BASE_H__
#define __VEHICLE_BASE_H__

// enum: see http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-enum
enum class Direction   {north, south, east, west};
enum class VehicleType {car, suv, truck};
enum class Turn        {right,straight};

class VehicleBase
{
   public:
      static int vehicleCount;

  protected:
      int         vehicleID;
      VehicleType vehicleType;
      Direction   vehicleDirection;
      Turn        vehicleTurn;

   public:
      VehicleBase();
      VehicleBase(const VehicleBase& other);
      ~VehicleBase();

      inline int getVehicleID() const { return this->vehicleID; }

      inline VehicleType getVehicleType() const { return this->vehicleType; }
      inline Direction   getVehicleOriginalDirection() const { return this->vehicleDirection; }
      inline Turn        getVehicleTurn() const { return this->vehicleTurn; }
};

#endif
