#include <iostream>
#include <string>

// The Builder Design Pattern is a creational design pattern 
// that is used to construct complex objects step by step. 

// Step 1: Define the Vehicle class
class Vehicle 
{
public:
    void setVehicleType(const std::string& type) 
    {
        vehicleType = type;
    }

    void setBrand(const std::string& brand) 
    {
        this->brand = brand;
    }

    void setModel(const std::string& model) 
    {
        this->model = model;
    }

    void addGPS() 
    {
        hasGPS = true;
    }

    void addLeatherSeats() 
    {
        hasLeatherSeats = true;
    }

    void addSunroof() 
    {
        hasSunroof = true;
    }

    void showVehicle() const 
    {
        std::cout << "Vehicle Type: " << vehicleType << "\n";
        std::cout << "Brand: " << brand << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "GPS: " << (hasGPS ? "Yes" : "No") << "\n";
        std::cout << "Leather Seats: " << (hasLeatherSeats ? "Yes" : "No") << "\n";
        std::cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << "\n";
    }

private:
    std::string vehicleType;
    std::string brand;
    std::string model;
    bool hasGPS = false;
    bool hasLeatherSeats = false;
    bool hasSunroof = false;
};

// Step 2: Define the VehicleBuilder interface
class VehicleBuilder 
{
public:
    virtual void setVehicleType() = 0;
    virtual void setBrand() = 0;
    virtual void setModel() = 0;
    virtual void addGPS() = 0;
    virtual void addLeatherSeats() = 0;
    virtual void addSunroof() = 0;
    virtual Vehicle build() = 0;
};

// Step 3: Create concrete builders
class CarBuilder : public VehicleBuilder 
{
public:
    void setVehicleType() override 
    {
        vehicle.setVehicleType("Car");
    }

    void setBrand() override 
    {
        vehicle.setBrand("Toyota");
    }

    void setModel() override 
    {
        vehicle.setModel("Camry");
    }

    void addGPS() override 
    {
        vehicle.addGPS();
    }

    void addLeatherSeats() override 
    {
        vehicle.addLeatherSeats();
    }

    void addSunroof() override 
    {
        vehicle.addSunroof();
    }

    Vehicle build() override 
    {
        return vehicle;
    }

private:
    Vehicle vehicle;
};

class MotorcycleBuilder : public VehicleBuilder 
{
public:
    void setVehicleType() override 
    {
        vehicle.setVehicleType("Motorcycle");
    }

    void setBrand() override 
    {
        vehicle.setBrand("Harley-Davidson");
    }

    void setModel() override 
    {
        vehicle.setModel("Sportster");
    }

    void addGPS() override 
    {
        // Motorcycles do not have GPS
    }

    void addLeatherSeats() override 
    {
        // Motorcycles do not have leather seats
    }

    void addSunroof() override 
    {
        // Motorcycles do not have sunroofs
    }

    Vehicle build() override 
    {
        return vehicle;
    }

private:
    Vehicle vehicle;
};

// Step 4: Create the Director
class VehicleDirector 
{
public:
    VehicleDirector(VehicleBuilder* builder) : builder(builder) {}

    Vehicle construct() 
    {
        builder->setVehicleType();
        builder->setBrand();
        builder->setModel();
        builder->addGPS();
        builder->addLeatherSeats();
        builder->addSunroof();
        return builder->build();
    }

private:
    VehicleBuilder* builder;
};

int main() 
{
    // Client code
    CarBuilder carBuilder;
    MotorcycleBuilder motorcycleBuilder;

    VehicleDirector carDirector(&carBuilder);
    Vehicle car = carDirector.construct();

    VehicleDirector motorcycleDirector(&motorcycleBuilder);
    Vehicle motorcycle = motorcycleDirector.construct();

    std::cout << "Car Details:\n";
    car.showVehicle();
    std::cout << "\nMotorcycle Details:\n";
    motorcycle.showVehicle();

    return 0;
}