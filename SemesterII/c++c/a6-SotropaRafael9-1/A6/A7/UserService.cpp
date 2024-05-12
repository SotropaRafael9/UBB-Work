#include "UserService.h"

UserServiceException::UserServiceException(std::string& message_error) : message(message_error) {}

const char* UserServiceException::what() const noexcept
{
	return this->message.c_str();
}


UserService::UserService(UserRepo* user_repository)
{
	this->user_repo = user_repository;
}

void UserService::add_dog_wishlist_service(Dog new_dog)
{
	this->user_repo->add_whishlist(new_dog);
}

int UserService::get_lenght_service_user()
{
	return this->user_repo->get_length_user();
}

Dog* UserService::get_dogs_wishlist_service()
{
	return this->user_repo->get_dogs_user();
}

std::string UserService::get_file_name_service()
{
	return this->user_repo->get_file_name();
}

int UserService::filter_dogs(std::string breed, int age, Dog* dogs_list, Dog* dogs_list_filtered, int length)
{
	int dogs_filtered_length = 0;

	for (int i = 0; i < length; i++)
	{
		if (dogs_list[i].get_breed() == breed && dogs_list[i].get_age() < age)
			dogs_list_filtered[dogs_filtered_length++] = dogs_list[i];
	}


	if (dogs_filtered_length <= 0)
	{
		std::string error;
		error += std::string("There aren't any dogs that obey the filters.");
		throw(UserServiceException(error));
	}
	return dogs_filtered_length;


}

UserService::~UserService() = default;


