#include "Domain.h"


Coat::Coat(int size, std::string color, int price, int quantity,std::string photograph)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
}

int Coat::get_size()
{
	return this->size;
}

std::string Coat::get_color()
{
	return this->color;
}

int Coat::get_price()
{
	return this->price;
}

int Coat::get_quantity()
{
	return this->quantity;
}

std::string Coat::get_photograph()
{
	return this->photograph;
}
