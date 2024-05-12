#include "UserRepo.h"
#include <fstream>
#include <algorithm>


UserRepo::UserRepo() = default;

void UserRepo::initialise_user_repo()
{
}

void UserRepo::add_whishlist(Dog new_dog)
{
	this->data->push_back(new_dog);
}

Dog* UserRepo::get_dogs_user()
{
	return this->data->data();
}

int UserRepo::get_length_user()
{
	return this->data->size();
}

UserRepo::UserRepo(std::vector<Dog>* repo_array)
{
	this->data = repo_array;
}

UserRepo::~UserRepo() = default;

// =============== FileRepo ==============

