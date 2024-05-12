#pragma once
#include "Subject.h"
#include "Item.h"
#include "Repository.h"
#include <vector>

class Session: public Subject
{
private:
	Repository repo;

public:
	Session() = default;
	std::vector<Item>& getItems();
	void add(std::string n, std::string c, int p);
	void bid(int index, int sum, int userId);
};

