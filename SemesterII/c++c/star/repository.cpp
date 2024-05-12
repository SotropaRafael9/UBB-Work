#include "repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Repository::Repository()
{
	readAstronomersFromFile();
	readStarsFromFile(); 
}

Repository::~Repository()
{
}

std::vector<Astronomer>& Repository::getAstronomers() 
{
	return this->astronomers;
}

std::vector<Star>& Repository::getStars()
{
	return this->stars;
}

void Repository::addStar(Star s)
{
	for(auto star : stars)
		if (star.getName() == s.getName())
			throw std::exception("Star already exists!");

	stars.push_back(s);
	std::sort(this->stars.begin(), this->stars.end(), [](Star s1, Star s2) {
		if (s1.getConstellation() == s2.getConstellation())
			return s1.getDiameter() < s2.getDiameter();
		return s1.getConstellation() < s2.getConstellation();
		});

	this->writeStarsToFile();

}

void Repository::readAstronomersFromFile()
{
	std::ifstream file("a.txt");
	std::string line; 
	while (std::getline(file, line)) 
	{
		std::stringstream ss(line); 
		std::string name, constellation, x; 

		while (ss >> x)
		{
			if(x == "|")
				break;
			name += x + " ";
		}
		name.pop_back();

		while (ss >> x) 
		{
			if (x == "|")
				break;
			constellation += x + " "; 
		}
		constellation.pop_back(); 

		astronomers.push_back(Astronomer(name, constellation)); 
	}
}

void Repository::readStarsFromFile()
{
	std::ifstream file("star.txt");
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line); 
		std::string name, constellation, x;
		int ra, dec, diameter; 

		while (ss >> x)
		{
			if (x == "|")
				break;
			name += x + " ";
		}
		name.pop_back();

		while (ss >> x)
		{
			if (x == "|")
				break;
			constellation += x + " ";
		}
		constellation.pop_back(); 

		ss >> ra >> x >> dec >> x >> diameter; 

		this->addStar(Star(name, constellation, ra, dec, diameter)); 
	}
}

void Repository::writeStarsToFile()
{
	std::ofstream file("star.txt");
	for (int i = 0; i < stars.size(); i++)
	{
		file << stars[i].getName() << " | " << stars[i].getConstellation() << " | " << stars[i].getRA() << " | " << stars[i].getDec() << " | " << stars[i].getDiameter();
		if (i != stars.size() - 1) 
			file << "\n"; 
	}
	file.close();
}
