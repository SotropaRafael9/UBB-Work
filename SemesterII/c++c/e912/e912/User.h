#pragma once
#include <string>

class User
{
private:
	std::string name;
	int id;
	std::string type;

public:
	std::string getName() const;
	int getId() const;
	std::string getType() const;

	User(std::string n, int i, std::string t);
};

