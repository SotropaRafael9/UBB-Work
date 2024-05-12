#define _CRT_SECURE_NO_WARNINGS

#include "Domain.h"
#include <vector>
#include <sstream>
#include <utility>



Dog::Dog(int dog_id, std::string bread, std::string name, std::string photograph, int age)
{
	this->Dog_id = dog_id;
	this->Breed = bread;
	this->Name = name;
	this->Photograph = photograph;
	this->Age = age;

}


std::string Dog::get_name()
{
	return this->Name;
}

std::string Dog::get_breed()
{
	return this->Breed;
}

std::string Dog::get_photograph()
{
	return this->Photograph;
}

int Dog::get_id()
{
	return this->Dog_id;
}


int Dog::get_age() 
{
	return this->Age;
}

void Dog::set_name(std::string name)
{
	this->Name = name;
}
void Dog::set_breed(std::string breed)
{
	this->Breed = breed;
}

void Dog::set_photograph(std::string photograph)
{
	this->Photograph = photograph;
}

void Dog::set_age(int age)
{
	this->Age = age;
}

void Dog::set_id(int id)
{
	this->Dog_id = id;
}

bool Dog::operator==(const Dog& dog_check)const
{
	return this->Dog_id == dog_check.Dog_id;
}
//
std::istream& operator>>(std::istream& input_stream, Dog& dog)
{
	std::string line;
	std::getline(input_stream, line);
	std::vector<std::string> tokens;

	if (line.empty()) return input_stream;
	for (auto it = strtok(&line[0], ","); it != NULL; it = strtok(NULL, ","))
		tokens.push_back(it);

	int id = std::stoi(tokens[0]);
	std::string name = tokens[1];
	std::string breed = tokens[2];
	int age = std::stoi(tokens[3]);
	std::string photo = tokens[4];

	dog.set_age(age);
	dog.set_id(id);
	dog.set_breed(breed);
	dog.set_name(name);
	dog.set_photograph(photo);

	return input_stream;
}
std::ostream& operator<<(std::ostream& output_stream, const Dog& dog_out)
{
	output_stream << dog_out.Dog_id << "," << dog_out.Name << "," << dog_out.Breed << "," << dog_out.Age << "," << dog_out.Photograph;
	return output_stream;
}
//
