#pragma once
#include "Service.h"

class UI
{
private:
	Service ui;
public:
	UI(Service ui) : ui{ ui } {};
	void add_ui();
	void list_all();
	void menu();
	void run_menu();

};