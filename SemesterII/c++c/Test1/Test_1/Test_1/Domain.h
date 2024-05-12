#pragma once
#include <iostream>

class Player
{
	std::string name;
	std::string nationality;
	std::string team;
	int number_of_goals;

public:
	Player(std::string name, std::string nationality, std::string team, int number_of_goals);

	

	std::string get_name();
	std::string get_nationality();
	std::string get_team();
	int get_number_of_goals();
	~Player() = default;
};


