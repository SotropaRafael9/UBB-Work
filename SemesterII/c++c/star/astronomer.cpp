#include "astronomer.h"

Astronomer::Astronomer()
{
	this->name = "";
	this->constellation = "";
}

Astronomer::Astronomer(std::string name, std::string constellation)
{
	this->name = name;
	this->constellation = constellation;
}

std::string Astronomer::getName() const
{
	return this->name;
}

std::string Astronomer::getConstellation() const
{
	return this->constellation;
}





Star::Star()
{
	this->name = "";
	this->constellation = "";
	this->RA = 0;
	this->Dec = 0;
	this->diameter = 0;
}

Star::Star(std::string name, std::string constellation, int RA, int Dec, int diameter)
{
	this->name = name;
	this->constellation = constellation;
	this->RA = RA;
	this->Dec = Dec;
	this->diameter = diameter;
}

std::string Star::getName() const
{
	return this->name;
}

std::string Star::getConstellation() const
{
	return this->constellation;
}

int Star::getRA() const
{
	return this->RA;
}

int Star::getDec() const
{
	return this->Dec;
}

int Star::getDiameter() const
{
	return this->diameter; 
}

void Star::setName(std::string name)
{
	this->name = name; 
}

void Star::setConstellation(std::string constellation)
{
	this->constellation = constellation; 
}

void Star::setRA(int RA)
{ 
	this->RA = RA; 
}

void Star::setDec(int Dec)
{
	this->Dec = Dec; 
}

void Star::setDiameter(int diameter)
{
	this->diameter = diameter; 
}
