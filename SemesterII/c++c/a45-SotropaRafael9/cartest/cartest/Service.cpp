#include "Service.h"
#include <iostream>
Service::Service(Repo service)
{
	this->service = service;
	initialiseService();
}

bool Service::addService(Car new_car)
{
	return this->service.add(new_car);
}

bool Service::removeService(Car new_car)
{
	return this->service.remove(new_car);
}

vector<Car> Service::sortColourService()
{
	return this->service.sortColour();
}

vector<Car> Service::sortManufacturerModel()
{
	this->service.sortManufacturerandModel();
	return service.getCars();
}

void Service::initialiseService()
{
	Car new_car("Fiat", "Bravo", 2007, "red");
	service.add(new_car);
	Car new_car2("Audi", "A5", 2007, "blue");
	service.add(new_car2);
	Car new_car3("Fiat", "Idea", 2003, "black");
	service.add(new_car3);
	Car new_car4("BMW", "Coupe", 2013, "pink");
	service.add(new_car4);
	Car new_car5("Ford", "Fiesta", 1976, "yellow");
	service.add(new_car5);
}

vector<Car> Service::getCarsService()
{
	//initialiseService();
	return service.getCars();
}
