#include "Domain.h"
#include <vector>
#include <utility>
#include <sstream>

HospitalDepartament::HospitalDepartament(std::string name, int number_of_doctors)
{
	this->name = name;
	this->number_of_doctors = number_of_doctors;
}

bool HospitalDepartament::isEficient()
{
	return false;
}

std::string HospitalDepartament::toString()
{
	return std::string();
}

bool Surgery::isEficient()
{

	return false;
}

std::string Surgery::toString()
{
	return std::string();
}


std::istream& operator>>(std::istream input_stream, HospitalDepartament& HospitalDepartament)
{
	std::string line;
	std::getline(input_stream, line);
	std::vector<std::string> tokens;

	if (line.empty()) return input_stream;

	for (auto it = strtok(&line[0], ","); it != NULL; it = strtok(NULL, ","))
		tokens.push_back(it);

	HospitalDepartament.name = std::stoi(tokens[0]);
	HospitalDepartament.number_of_doctors = std::stoi(tokens[1]);
	
	return input_stream;
}

std::ofstream& operator<<(std::ofstream output_stream, const HospitalDepartament& HospitalDepartament_out)
{
	output_stream << HospitalDepartament_out.name << "," << HospitalDepartament_out.number_of_doctors;
	return output_stream;
}