#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

UI::UI(Service* service, UserService* user_service)
{
	this->serv = service;
	this->user_serv = user_service;
}


// ================ MENUS ====================


void UI::print_administrator_user_menu()
{
	cout << "WELCOME TO OUR DOG SHELTER!\n";
	cout << "\n\t1. Administrator mode." << endl << "\t2. User mode" << endl << "\t3. Exit\n";
}

void UI::print_menu_administrator()
{
	cout << "\n\t1. Add a dog." << endl;
	cout << "\t2. Delete a dog." << endl;
	cout << "\t3. Update informations about a dog." << endl;
	cout << "\t4. List the dogs in the shelter." << endl;
	cout << "\t5. Exit\n";
}

void UI::print_menu_user()
{
	cout << "\n\t1. See all the dogs and adopt one!\n";
	cout << "\t2. See the dogs of a certain breed and age. Adopt one!\n";
	cout << "\t3. List the adoption list.\n";
	//cout << "\t4. Display the adoption list from file.\n";
	cout << "\t5. Exit the user mode.\n";
}

// =================== USER MODE ================================



string UI::make_string_lower(string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}


bool UI::validate_string(string something)
{
	for (int i = 0; i < something.length(); i++)
		if (isdigit(something[i]) == true)
			return false;
	return true;
}

void UI::display_adoption_list()
{/*
	string link = string("start ").append(this->user_serv->get_file_name_service());
	system(link.c_str());*/
}

void UI::user_mode()
{
	cout << "You are now in the user mode :)" << endl;

	bool going = true;
	while (going)
	{
		try {
			print_menu_user();
			string option;
			cout << "Please select what you want to do next: ";
			cin >> option;
			if (option == "1") adopt_from_all_dogs();
			else if (option == "2") adopt_dogs_filtered();
			else if (option == "3") see_adoption_list();
			else if (option == "4") going = false;
			else if (option == "5") going = false;
			else cout << "Invalid input.";

		}
		catch (UserServiceException exception_message)
		{
			cout << exception_message.what() << endl;
		}
	}
}

void UI::ui_list_one_dog(Dog dog)
{
	cout << dog.get_id() << " | Name: " << dog.get_name() << " | Breed: " << dog.get_breed() << " | Age: " << dog.get_age() << " | Image: " << dog.get_photograph() << endl;
}

void UI::see_adoption_list()
{
	Dog* adoption_list = this->user_serv->get_dogs_wishlist_service();
	int length = this->user_serv->get_lenght_service_user();

	if (length == 0) cout << "There are no dogs in the adoption list.\n";

	for (int i = 0; i < length; i++)
		ui_list_one_dog(adoption_list[i]);
}

void UI::adopt_from_all_dogs()
{
	Dog* dogs_list = this->serv->get_dogs_service();
	bool done = false;
	int length = this->serv->get_length_service();
	string option;
	int i = 0;
	if (length == 0) throw("There are no dogs in the shelter!\n");

	while (!done)
	{
		if (this->user_serv->get_lenght_service_user() == length) throw("You have adopted all the dogs!!!\n");

		if (i == length) i = 0;

		ui_list_one_dog(dogs_list[i]);
		cout << "Do you want to adopt this dog? (yes / no / exit)\n";

		string link = string("start ").append(this->serv->get_dogs_service()[i].get_photograph());
		system(link.c_str());

		cin >> option;
		option = make_string_lower(option);

		if (option == "yes")
		{
			this->user_serv->add_dog_wishlist_service(dogs_list[i]);
			this->serv->delete_elem_service(dogs_list[i].get_id());

		}
		else if (option == "no") { i++; }
		else if (option == "exit") { done = true; }
		else throw("No such option!");
		if (length == 0) done = true;

	}
}

void UI::adopt_dogs_filtered()
{
	string breed;
	int age;
	Dog* dog_list = this->serv->get_dogs_service();
	int length = this->serv->get_length_service();

	cout << "Please enter the wanted breed: ";
	cin >> breed;
	cout << "Please enter the filter age: ";
	cin >> age;

	if (age <= 0) throw("Age must be a positive integer");
	if (!validate_string(breed)) throw("Invalid input");

	if (breed.length() == 0) adopt_from_all_dogs();
	else {
		Dog* dog_list_filtered = new Dog[length];
		int length_filtered = this->user_serv->filter_dogs(breed, age, dog_list, dog_list_filtered, length);

		int i = 0;
		bool done = false;
		string option;

		while (!done)
		{
			if (this->user_serv->get_lenght_service_user() == length) throw("You have adopted all the dogs!!!\n");
			if (i == length_filtered) i = 0;

			ui_list_one_dog(dog_list_filtered[i]);

			cout << "Do you want to adopt this dog? (yes / no / exit)\n";

			string link = string("start ").append(dog_list_filtered[i].get_photograph());
			system(link.c_str());

			cin >> option;
			option = make_string_lower(option);

			if (option == "yes")
			{
				this->user_serv->add_dog_wishlist_service(dog_list_filtered[i]);
				this->serv->delete_elem_service(dog_list_filtered[i].get_id());
				i++;
			}
			else if (option == "no") { i++; }
			else if (option == "exit") { done = true; }
			else throw("No such option!");
			if (length_filtered == 0) done = true;
		}
		delete[] dog_list_filtered;
	}

}



// ========================= ADMIN MODE ============================

void UI::ui_add_dog()
{
	int dog_id = 0, age = 0;
	string breed, name, photograph;
	cout << "Please enter the id of the dog: ";
	cin >> dog_id;
	if (dog_id <= 0) throw("ID must be a positive number.");

	cout << "Please enter the breed: ";
	cin >> breed;
	if (!validate_string(breed) || breed.length() == 0) throw("Invalid input.");

	cout << "Please enter the name: ";
	cin >> name;
	if (!validate_string(name) || name.length() == 0) throw("Name is not valid.");

	cout << "Please enter the link of the image:  ";
	cin >> photograph;
	if (photograph.length() == 0) { throw ("Photograph link is not valid."); }

	cout << "Please enter dog's age: ";
	cin >> age;
	this->serv->add_elem_service(dog_id, breed, name, photograph, age);

}

void UI::ui_delete_dog()
{
	int dog_id = 0;

	cout << "Please the id of the dog you want to delete: ";
	cin >> dog_id;

	if (dog_id <= 0) throw("ID must be a positive number.");

	this->serv->delete_elem_service(dog_id);

}

void UI::ui_update_dog()
{

	int dog_id = 0, age = 0;
	string breed, name, photograph;
	cout << "Please enter the id of the dog you want to update: ";
	cin >> dog_id;
	if (dog_id <= 0) throw("ID must be a positive number.");

	cout << "Please enter the new breed: ";
	cin >> breed;
	if (!validate_string(breed) || breed.length() == 0) throw("Invalid input.");

	cout << "Please enter the new name: ";
	cin >> name;
	if (!validate_string(name) || name.length() == 0) throw("Name is not valid.");

	cout << "Please enter the new link of the image:  ";
	cin >> photograph;
	if (photograph.length() == 0) throw("Photograph link is not valid.");

	cout << "Please enter dog's age: ";
	cin >> age;
	this->serv->update_elem_service(dog_id, breed, name, photograph, age);
}

void UI::ui_list_dogs()
{
	Dog* dogs_list = this->serv->get_dogs_service();
	int length = this->serv->get_length_service();
	if (length == 0) cout << "There are no dogs in the shelter.";


	for (int i = 0; i < length; i++)
		cout << dogs_list[i].get_id() << " | Name: " << dogs_list[i].get_name() << " | Breed: " << dogs_list[i].get_breed() << " | Age: " << dogs_list[i].get_age() << " | Image: " << dogs_list[i].get_photograph() << endl;
}



void UI::administrator_mode()
{
	cout << "\tYou are now in2 adminstrator mode ;)\n";
	bool going = true;
	while (going)
	{
		try {
			print_menu_administrator();
			string option;
			cout << "Please select what you want to do next: ";
			cin >> option;
			if (option == "1") ui_add_dog();
			else if (option == "2") ui_delete_dog();
			else if (option == "3") ui_update_dog();
			else if (option == "4") ui_list_dogs();
			else if (option == "5") going = false;
			else cout << "Invalid input\n";
		}
		catch (ServiceException exception_message) {
			cout << exception_message.what() << endl;
		}

	}
}

void UI::run_console()
{
	bool going = true;
	while (going)
	{
		print_administrator_user_menu();

		string option;
		cout << "Please select the mode: ";
		cin >> option;
		if (option == "1") administrator_mode();
		else if (option == "2") user_mode();
		else if (option == "3") going = false;
		else cout << "Invalid input\n";

	}
}

UI::~UI() = default;

