#include "Tests.h"
#include <iostream>
#include "UI.h"
#include <vector>
#include "CSVUserRepo.h"
#include "HTMLUserRepo.h"

void print_menu_files()
{
	std::cout << "\n\t1. CSV file\n" << "\t2. HTML file\n";
}


int main()
{
	test_all();
	//DynamicVector<Dog> v1{ 100 };
	std::vector<Dog> v1;
	FileRepository repo = FileRepository(&v1, "dog.txt");
	Service serv = Service(&repo);

	std::vector<Dog> v2;
	print_menu_files();
	std::cout << "Please select the type of file for your adoption list: ";

	int option;
	bool done = false;

	while (!done)
	{
		std::cin >> option;
		if (option == 1)
		{
			CSVUserRepo user_repo = CSVUserRepo(&v2, "dogs.csv");
			UserService user_serv = UserService(&user_repo);
			UI ui = UI(&serv, &user_serv);
			ui.run_console();
			done = true;
		}
		else if (option == 2)
		{
			HtmlUserRepo user_repo = HtmlUserRepo(&v2, "dogs.html");
			UserService user_serv = UserService(&user_repo);
			UI ui = UI(&serv, &user_serv);
			ui.run_console();
			done = true;
		}
		else std::cout << "Invalid input.";
	}

	return 0;
}

/*
* OpenCppCoverage --sources PetShelter -- ./PetShelter/Debug/PetShelter.exe
*/