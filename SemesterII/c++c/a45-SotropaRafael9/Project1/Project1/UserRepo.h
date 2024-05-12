#pragma once

#include <vector>
#include "Domain.h"


class UserRepo {
protected:
	std::vector<Dog>* data;

public:
	// the constructor of the user repository which receives a pointer to a dynamic vector of dogs
	explicit UserRepo(std::vector<Dog>* repo_array);

	UserRepo();

	virtual void initialise_user_repo();

	// a functions that adds an object dog to the user repository
	virtual void add_whishlist(Dog new_dog);

	// a function that returns the array of elements from the user repository
	virtual Dog* get_dogs_user();

	// a function that returns the length of the user repo
	virtual int get_length_user();

	//virtual std::string get_file_name() = 0;

	// class destructor
	~UserRepo();
};
