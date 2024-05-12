#pragma once
#include "Item.h"
#include <vector>

class Repository
{
private:
	std::vector<Item> items;

public:
	Repository();
	~Repository();

	void addItem(std::string n, std::string c, int p);
	void bidItem(int index, int sum, int userId);
	std::vector<Item>& getItems();
};

