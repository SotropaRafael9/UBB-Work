#pragma once
#include"service.h"


class UI {
private:
	Service ui;
public:
	UI(Service ui) : ui{ ui } {};
	void addUi();
	void removeUi();
	void sortColourUi();
	void sortManufacturerModelUi();
	void menu();
	void run_menu();
};