#include"Domain.h"
#include"Repository.h"
#include"Service.h"
#include "Ui.h"
#include "Tests.h"
#include<iostream>
using namespace std;

int main()
{
	Test abc;
	abc.run_all_test();
	Repo repository{};
	Service service{ repository };
	UI ui{ service };
	ui.run_menu();
	
	return 0;
}
/*service.initialiseService();
	vector<Car>new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	Car car1("Fiat", "Bravo", 2007, "red");
	service.removeService(car1);
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	cout << "\n \n";
	service.sortColourService();
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	cout << "\n \n";
	service.sortManufacturerModel();
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}*/
	/*cout << "\n";
	Car new_car("A", "B", 2, "C");
	service.addService(new_car);
	service.getCarsService();
	cout << "\n";
	service.removeService(new_car);
	service.getCarsService();
	cout << "\n";
	service.sortColourService();
	service.getCarsService();
	cout << "\n";
	service.sortManufacturerModel();
	service.getCarsService();
	cout << "\n";*/
	//Car new_car("Fiat","Bravo",2007,"red");
	//cout<<new_car.GetYear()<<" ";
	//cout << new_car.GetName() << " ";
	//cout << new_car.GetColour() << " ";
	//cout << new_car.GetModel() << " ";
	/*
	repository.add(new_car);
	Car new_car2("Audi", "A5", 2007, "blue");
	repository.add(new_car2);
	Car new_car3("Fiat", "Idea", 2003, "black");
	repository.add(new_car3);
	Car new_car4("BMW", "Coupe", 2013, "pink");
	repository.add(new_car4);
	Car new_car5("Ford", "Fiesta", 1976, "yellow");
	repository.add(new_car5);
	repository.sortColour();
	cout << "\n";
	repository.sortManufacturerandModel();*/