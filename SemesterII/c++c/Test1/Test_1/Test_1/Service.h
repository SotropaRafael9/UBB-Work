#pragma once
#include "Repository.h"

class Service {
private:
	Repo service;
public:
	Service(Repo service);
	bool add_Service(Player new_player);
	std::vector<Player> get_Player_Service();
	void initial_sevice();
};