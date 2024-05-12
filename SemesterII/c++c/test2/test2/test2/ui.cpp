#include "UI.h"
#include <string>
#include <iostream>

using namespace std;
void UI::print_menu()
{
	cout << "1.Add new departament\n";
	cout << "2.Show all departaments \n";
	cout << "3.exit\n";

}
void UI::add_departament()
{
}

void UI::run_console()
{
	int command;
	while (true)
	{
		if (command == 1)
			add_departament();
		else 
			if(command == 3)
				break

	}
}


