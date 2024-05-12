#pragma once
#include "DynamicVector.h"
#include "Domain.h"
#include <vector>
#include<iostream>

class Repository {
private:
	std::vector<Dog>* data;

public:

	Repository(std::vector<Dog>* repo_array);

	virtual void initialise_repo();

	virtual void add(Dog new_dog);

	virtual void remove(int dog_id);

	virtual void update(Dog new_dog);

	virtual int get_position(int dog_id);

	virtual int get_length();

	virtual Dog get_element(int position);

	virtual Dog* get_dogs();

	~Repository();

	

};