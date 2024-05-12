#include "Service.h"

ServiceException::ServiceException(std::string& message_error) :message(message_error){}

const char* ServiceException::what() const noexcept
{
	return this->message.c_str();
}

Service::Service(Repository* repository)
{
	this->repo = repository;
}

void Service::add_elem_service(int dog_id, std::string bread,std::string name, std::string photograph, int age)
{
	if (this->repo->get_position(dog_id) != -1)
	{
		std::string error;
		error += std::string("There is already a dog with this id.");
		throw(ServiceException(error));
	}
	if (age <= 0)
	{
		std::string error;
		error += std::string("There is already a dog with this id");
		throw(ServiceException(error));
	}
	Dog new_dog = Dog(dog_id, bread, name, photograph, age);
	this->repo->add(new_dog);
}

void Service::delete_elem_service(int dog_id)
{
	if (this->repo->get_position(dog_id) == -1)
	{
		std::string error;
		error += std::string("There isn't any dog with this id in the shelter.");
		throw(ServiceException(error));
	}

	this->repo->remove(dog_id);
}

void Service::update_elem_service(int dog_id, std::string breed, std::string name, std::string photograph, int age)
{
	if (this->repo->get_position(dog_id) == -1)
	{
		std::string error;
		error += std::string("There isn't any dog with this id in the shelter.");
		throw(ServiceException(error));
	}
	if (age <= 0)
	{
		std::string error;
		error += std::string("The age is an invalid integer.");
		throw(ServiceException(error));
	}

	Dog new_dog = Dog(dog_id, breed, name, photograph, age);
	this->repo->update(new_dog);
}

int Service::get_length_service()
{
	return this->repo->get_length();
}

Dog Service::get_element_service(int pos)
{
	return this->repo->get_element(pos);
}

Dog* Service::get_dogs_service()
{
	return this->repo->get_dogs();
}

Service::~Service() = default;

