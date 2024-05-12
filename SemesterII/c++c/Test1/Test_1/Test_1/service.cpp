#include "Service.h"
#include <iostream>
Service::Service(Repo service)
{
	this->service = service;
	initial_sevice();
}

bool Service::add_Service(Player new_player)
{
	return this->service.add(new_player);
}

std::vector<Player> Service::get_Player_Service()
{
	return service.get_all();
}

void initial_sevice()
{
	Player new_player("Nora_Mork", "NOR", "Larvik", 83);
	Player new_player("Isabelle_Gullden", "SWE", "CSM_Bucurest", 80);
	Player new_player("Cristina_Neagu", "ROU", "Buducnost", 63);
	Player new_player("Allison_Pineau", "FRA", "HCM_Baia_Mare", 82);
	Player new_player("Ilina_Ekaterina", "RUS", "Rostov-Don", 80);
	Player new_player("Nerea_pena", "ESP", "FTC-Rail_Cargo_Hungaria", 59);

}