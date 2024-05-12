#include "Repository.h"
#include <iostream>	
Repo::Repo(std::vector<Player>* repo_array)
{
	this->data = std::vector<Player>();
}

bool Repo::add(Player new_player)
{
	for (auto current_player : this->data)
	{
		if(current_player.get_name() ==new_player.get_name())
		{
			return false;
		}
	}
	this->data.push_back(new_player);
	return true;
}

std::vector<Player> Repo::get_all()
{
	return this->data;
}

void Repo::sort_all_players_for_a_team()
{
}

FileRepository::FileRepository(std::vector<Player>* repo_array, std::string file_name)
	:Repo(repo_array)
{
	this->file_name = file_name;
}

void FileRepository::load_file()
{
	if (!this->file_name.empty())
	{
		Player new_player;
		std::ifstream fin(this->file_name);
		while (fin >> new_player)
		{
			if (std::find(this->data->begin(), this->data->end(), new_player) == this->data->end())
				this->data->push_back(new_player);
		}
		fin.close();
	}
}

void FileRepository::write_to_file()
{
	if (!this->file_name.empty())
	{
		std::ofstream fout(this->file_name);
		for (Player& const dog : *this->data)
		{
			fout << dog << "\n";
		}
		fout.close();
	}
}

void FileRepository::initialise_repo()
{
	this->load_file();
}

void FileRepository::add(Player new_dog)
{
	this->data->push_back(new_dog);
	write_to_file();
}

void FileRepository::remove(int dog_id)
{
	int const position = this->get_position(dog_id);
	this->data->erase(this->data->begin() + position);
	write_to_file();
}

void FileRepository::update(Dog new_dog)
{
	int const position = get_position(new_dog.get_id());
	this->data->erase(this->data->begin() + position);
	this->data->insert(this->data->begin() + position, new_dog);
	write_to_file();
}

FileRepository::~FileRepository() = default;
