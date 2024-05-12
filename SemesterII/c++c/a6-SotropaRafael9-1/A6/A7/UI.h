#pragma once

#include "Service.h"
#include "UserService.h"

class UI {
private:
	Service* serv;
	UserService* user_serv;
public:

	UI(Service* service, UserService* user_service);
	void administrator_mode();

	void user_mode();

	void run_console();

	void print_administrator_user_menu();

	static void print_menu_administrator();

	void print_menu_user();

	void ui_add_dog();

	void ui_delete_dog();

	void ui_update_dog();

	void ui_list_dogs();

	bool validate_string(std::string something);

	void adopt_from_all_dogs();

	void adopt_dogs_filtered();

	void ui_list_one_dog(Dog dog);

	std::string make_string_lower(std::string str);

	void see_adoption_list();

	void display_adoption_list();

	~UI();
};
