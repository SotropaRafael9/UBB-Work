#include "domain.h"

Car::Car(string manufacturer_name, string model, int year_of_fabrication, string colour)
{
	this->manufacturer_name = manufacturer_name;
	this->model = model;
	this->year_of_fabrication = year_of_fabrication;
	this->colour = colour;
}

string Car::GetName()
{
	return this->manufacturer_name;
}

string Car::GetModel()
{
	return this->model;
}

int Car::GetYear()
{
	return this->year_of_fabrication;
}

string Car::GetColour()
{
	return this->colour;
}
