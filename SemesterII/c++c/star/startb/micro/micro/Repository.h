#pragma once
#include <string>
#include <vector>
#include "Domain.h"
class Repository
{
private:
	std::vector<Bacterie> bacterii;
	std::vector<Biologist> biologists;
public:
	Repository();
	std::vector<Bacterie> get_bacterii();
	std::vector<Biologist> get_biologists();
	void readBacterii();
	void readBiologists();




};
