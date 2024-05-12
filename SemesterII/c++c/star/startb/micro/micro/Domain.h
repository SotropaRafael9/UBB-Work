#pragma once
#include <string>
#include <vector>

class Bacterie
{
private:
	std::string name;
	std::string species;
	int size;
	std::vector<std::string> diseases;
public:
	std::string get_name()
	{
		return name;
	}
	std::string get_species()
	{
		return species;
	}
	int get_size()
	{
		return size;
	}
	std::vector<std::string> get_diseases()
	{
		return diseases;
	}
	Bacterie(std::string name, std::string species, int size, std::vector<std::string> diseases)
	{
		this->name = name;
		this->species = species;
		this->size = size;
		this->diseases = diseases;
	}



};

class Biologist 
{
private:
	std::string name;
	std::vector <Bacterie> bacterii;
public:
	std::string get_name()
	{
		return name;
	}
	std::vector<Bacterie> get_bacterii()
	{
		return bacterii;
	}
	Biologist(std::string name,std::vector<Bacterie> bacterii)
	{
		this->name = name;
		this->bacterii = bacterii;
	}
};
