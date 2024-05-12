#pragma once
#include <iostream>
#include<vector>
#include "Domain.h"
class Repo
{
private:
	std::vector<Player> data;
public:
	Repo(std::vector<Player>* repo_array);
	bool add(Player new_player);
	std::vector<Player>get_all();
	void sort_all_players_for_a_team();

};

class FileRepository : public Repo
{
private:
	std::string file_name;

public:
	FileRepository(std::vector<Player>* repo_array, std::string file_name);

	void load_file();

	void write_to_file();

	void initialise_repo() override;

	void add(Player new_dog) override;

	void remove(int dog_id) override;

	void update(Dog new_dog) override;

	//int get_position(int dog_id);

	//int get_length();

	//Dog get_element(int position);

	//Dog* get_dogs();

	~FileRepository();
};