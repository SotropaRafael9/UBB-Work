#pragma once
#include <string>


class Coat{
private:
	int size;
	std::string color;
	int price;
	int quantity;
	std::string photograph;

public:
	Coat(int size, std::string color, int prise, int quantity, std::string photograph );

	int get_size();
	std::string get_color();
	int get_price();
	int get_quantity();
	std::string get_photograph();	
		
};
