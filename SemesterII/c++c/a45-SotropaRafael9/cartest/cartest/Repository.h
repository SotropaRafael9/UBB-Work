#pragma once
#include<vector>
#include "Domain.h"

class Repo {
private:
	std::vector<Car> repository;
public:
	Repo();
	bool add(Car new_car);
	bool remove(Car new_car);
	vector<Car> sortColour();
	void sortManufacturerandModel();
	vector<Car>getCars();
};