#pragma once

#include <vector>
#include "astronomer.h"


class Repository
{
private:
	std::vector<Astronomer> astronomers;
	std::vector<Star> stars;
public:
	Repository();
	~Repository();
	std::vector<Astronomer>& getAstronomers();
	std::vector<Star>& getStars();
	void addStar(Star s);

	void readAstronomersFromFile();
	void readStarsFromFile();

	void writeStarsToFile(); 
};