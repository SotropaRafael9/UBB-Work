#pragma once
#pragma once
#include"Repository.h"


class Service {
private:
	Repo service;
public:
	Service(Repo service);
	bool addService(Car new_car);
	bool removeService(Car new_car);
	vector<Car> sortColourService();
	vector<Car> sortManufacturerModel();
	void initialiseService();
	vector<Car> getCarsService();

};