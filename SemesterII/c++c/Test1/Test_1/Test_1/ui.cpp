#include "UI.h"
#include <iostream>
using namespace std;
void UI::add_ui()
{
	cout << "Enter name: ";
	string name;
	cin >> name;
	cout << "Enter nationality: ";
	string nationality;
	cin >> nationality;
	cout << "Enter team: ";
	string team;
	cin >> team;
	cout << "Enter number_of_goals: ";
	int number_of_goals;
	cin >> number_of_goals;
	cin.get();
	if (ui.add_Service(Player(name, nationality, team, number_of_goals)) == 1)
	{
		cout << "Player added /n";
	}
	else
	{
		cout << "Player already exist/n";
	}

}

void UI::list_all()
{
	for (auto player : ui.get_Player_Service())
		cout << player.get_name()<<endl;
}

void UI::menu()
{
	cout << "1.ADD Player \n";
	cout << "2.List all \n";
	cout << "0.Exit \n";
}

void UI::run_menu()
{
	while (1)
	{
		menu();
		int option;
		cin >> option;
		if (option == 1) {
			add_ui();
		}
		else if(option == 2)
		{
			list_all();
		}
		else
		{
			if (option == 0)
				break;
		}	
			
	}
}