#pragma once
#include "Repository.h"


class UI{
private:
	Controller* controller;
public:
	UI(Controller controller);
	
	void print_menu();
	void run_console();
	void add_departament();
	~UI();
};
