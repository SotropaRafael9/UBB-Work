#include "Domain.h"

Player::Player(std::string name, std::string nationality, std::string team, int number_of_goals)
{
	std::string name = name;
	std::string nationality = nationality;
	std::string team = team;
	int number_of_goals = number_of_goals;
}

const std::string Player::get_name()
{
	return name;
}

const std::string Player::get_nationality()
{
	return nationality;
}

const std::string Player::get_team()
{
	return team;
}

int Player::get_number_of_goals()
{
	return number_of_goals;
}
