#include "UI.h"

#include<iostream>
using namespace std;
void UI::addUi()
{
	cout << "Enter name:";
	string name;
	cin >> name;
	cout << "Enter model:";
	string model;
	cin >> model;
	cout << "Enter year:";
	int year;
	cin >> year;
	cout << "Enter colour:";
	string colour;
	cin >> colour;
	cin.get();
	if (ui.addService(Car(name, model, year, colour)) == 1) {
		cout << "Car added \n";
	}
	else {
		cout << "Car already exists \n";
	}
}

void UI::removeUi()
{
	cout << "Enter name:";
	string name;
	cin >> name;
	cout << "Enter model:";
	string model;
	cin >> model;
	cout << "Enter year:";
	int year;
	cin >> year;
	cout << "Enter colour:";
	string colour;
	cin >> colour;
	cin.get();
	if (ui.removeService(Car(name, model, year, colour)) == 1) {
		cout << "Car removed \n";
	}
	else {
		cout << "Car does not exist \n";
	}
}

void UI::sortColourUi()
{
	std::vector<Car>new_car = ui.sortColourService();
	cout << "Sorted cars by colour: \n";
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetName() << " " << new_car[i].GetModel() << " " << new_car[i].GetYear() << " " << new_car[i].GetColour() << " " << "\n";
	}
}

void UI::sortManufacturerModelUi()
{
	cout << "Sorted cars by manufacturer and model: \n";
	std::vector<Car>new_car = ui.sortManufacturerModel();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetName() << " " << new_car[i].GetModel() << " " << new_car[i].GetYear() << " " << new_car[i].GetColour() << " " << "\n";
	}
}

void UI::menu()
{
	cout << "1.Add a car \n";
	cout << "2.Remove a car \n";
	cout << "3.Show cars sorted by manufacturer and model \n";
	cout << "4.Show cars sorted by colour, fabrication year > 45 \n";
	cout << "5.Exit \n";
}

void UI::run_menu()
{
	while (1) {
		menu();
		int option;
		cin >> option;
		if (option == 1) {
			addUi();
		}
		else if (option == 2)
		{
			removeUi();
		}
		else if (option == 3)
		{
			sortManufacturerModelUi();
		}
		else if (option == 4) {
			sortColourUi();
		}
		else if (option == 5) {
			break;
		}
	}

}
