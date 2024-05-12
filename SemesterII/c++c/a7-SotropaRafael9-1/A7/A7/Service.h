#pragma once

#include "Repository.h"



class Service {
private:
	Repository* repo;

public:

	// the constructor of the service which receives a pointer to a Repository object
	Service(Repository* repository);

	// a function that receives the data about a dog, creates a new object of type dog and passes it to the repo for adding it
	void add_elem_service(int dog_id, std::string breed, std::string name, std::string photograph, int age);

	// a function that receives the id of a dog and deletes the dog with the corresponding id from the repo
	void delete_elem_service(int dog_id);

	// a function that receives the data about a dog, creates a new object of type dog and passes it to the repo for updating the dog with the same id
	void update_elem_service(int dog_id, std::string breed, std::string name, std::string photograph, int age);

	// a function that returns the array of dogs from the repo
	Dog* get_dogs_service();

	// a function that returns the length of the repo
	int get_length_service();

	// a function that gets an element from the repo 
	Dog get_element_service(int pos);

	// the destructor of the class
	~Service();
};

class ServiceException : public std::exception {
private:
	std::string message;
public:

	ServiceException(std::string& message_error);

	const char* what() const noexcept override;
};