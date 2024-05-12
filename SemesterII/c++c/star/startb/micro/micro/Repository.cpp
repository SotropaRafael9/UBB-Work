#include "Repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<Biologist> Repository::get_biologists()
{
	return biologists;
}

void Repository::readBacterii()
{
	std::ifstream file("bacterii.txt");
	std::string line;
	std::string name;
	std::string species;
	int size;
	std::vector<std::string> diseases;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		while (ss >> name >> species >> size)
		{
			std::string disease;
			while (ss >> disease)
			{
				diseases.push_back(disease);
			}
			Bacterie b(name, species, size, diseases);
			bacterii.push_back(b);
		}


		
	}
	file.close();

}

void Repository::readBiologists()
{
	std::ifstream file("biologist.txt");
	std::string line;
	std::string name;
	std::vector<Bacterie> bacterii;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		while (ss >> name)
		{
			std::string bacterie;
			while (ss >> bacterie)
			{
				for (auto b : bacterii)
				{
					if (b.get_name() == bacterie)
					{
						bacterii.push_back(b);
					}
				}
			}
			Biologist bi(name, bacterii);
			biologists.push_back(bi);
		}
	}
}

Repository::Repository()
{
	readBacterii();
	readBiologists();
}

std::vector<Bacterie> Repository::get_bacterii()
{
	std::vector<Bacterie> bacteri = this->bacterii;
	for (auto b : this->bacterii)
	{
		sort(bacteri.begin(), bacteri.end(), [](Bacterie b1, Bacterie b2) {return b1.get_name() < b2.get_name(); });
	}
	return bacteri;
}

