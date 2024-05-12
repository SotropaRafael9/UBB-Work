#include "Tests.h"
#include "Domain.h"
#include <cassert>
#include <string.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "Service.h"
#include "UserRepo.h"
#include "UserService.h"
#include <vector>

using namespace std;

void test_dog()
{
	Dog new_dog = Dog(1, "Ciobanesk", "Relu", "rrr", 3);

	assert(new_dog.get_age() == 3);
	assert(new_dog.get_name() == "Relu");
	assert(new_dog.get_id() == 1);
	assert(new_dog.get_breed() == "Ciobanesk");
	assert(new_dog.get_photograph() == "rrr");

	new_dog.set_age(5);
	new_dog.set_name("Relache");
	new_dog.set_breed("Corgi");
	new_dog.set_photograph("aaa");

	assert(new_dog.get_age() == 5);
	assert(new_dog.get_name() == "Relache");
	assert(new_dog.get_id() == 1);
	assert(new_dog.get_breed() == "Corgi");
	assert(new_dog.get_photograph() == "aaa");
}

void test_dynamic_vect()
{
	DynamicVector<Dog> v{ 1 };
	Dog new_dog = Dog(1, "Ciobanesk", "Relu", "rrr", 3);
	Dog another_dog = Dog(2, "Labrador", "Macanache", "rtg", 5);
	v.add_elem(new_dog);
	v.add_elem(another_dog);

	assert(v.get_element(0).get_id() == 1);
	assert(v.get_element(0).get_breed() == "Ciobanesk");
	assert(v.get_element(0).get_name() == "Relu");
	assert(v.get_element(0).get_age() == 3);
	assert(v.get_element(0).get_photograph() == "rrr");

	assert(v.get_element(1).get_id() == 2);
	assert(v.get_size() == 2);

	v.delete_element(1);
	assert(v.get_size() == 1);

	Dog last_dog = Dog(1, "Corgi", "Alfie", "brb", 1);
	v.update_element(last_dog, 0);
	assert(v.get_element(0).get_id() == 1);
	assert(v.get_element(0).get_breed() == "Corgi");
	assert(v.get_element(0).get_name() == "Alfie");
	assert(v.get_element(0).get_age() == 1);
	assert(v.get_element(0).get_photograph() == "brb");

	Dog this_is_last_dog = Dog(3, "Corgi", "Relu", "basdsadrb", 3);
	v = v + this_is_last_dog;
	assert(v.get_element(1).get_id() == 3);
}

void test_repository()
{
	vector<Dog> v;
	Repository repo = Repository(&v);
	Dog dog1 = Dog(11, "Ciobanesk", "Relu", "rrr", 3);
	Dog dog2 = Dog(12, "Labrador", "Macanache", "rtg", 5);
	Dog dog3 = Dog(13, "Corgi", "Alfie", "brb", 1);

	repo.add(dog1);
	repo.add(dog2);
	repo.add(dog3); 

	assert(repo.get_length() == 13);
	assert(repo.get_position(11) == 10);
	assert(repo.get_position(12) == 11);
	assert(repo.get_position(13) == 12);

	repo.remove(12);
	assert(repo.get_length() == 12);
	Dog dog4 = Dog(13, "Corgi", "MARGI", "brb", 7);
	repo.update(dog4);

	assert(repo.get_element(11).get_age() == 7);
	assert(repo.get_element(11).get_breed() == "Corgi");
	assert(repo.get_element(11).get_name() == "MARGI");

	Dog* dog_list = repo.get_dogs();
	assert(dog_list[0].get_id() == 1);

	Dog dog5 = Dog(14, "Corgi", "Roger", "brb", 5);
	
}

void test_service()
{
	vector<Dog> v;
	Repository repo = Repository(&v);
	Service serv = Service(&repo);

	assert(serv.get_length_service() == 10);

	

	serv.add_elem_service(11, "Labrador", "Macanache", "rtg", 5);
	serv.add_elem_service(12, "Ciobanesk", "Relu", "rrr", 3);

	assert(serv.get_length_service() == 12);

	serv.delete_elem_service(11);
	assert(serv.get_length_service() == 11); 
	serv.update_elem_service(12, "Corgi", "Alfie", "brb", 1);
	Dog updated_dog = serv.get_element_service(10);
	assert(updated_dog.get_breed() == "Corgi");
	assert(updated_dog.get_photograph() == "brb");
	assert(updated_dog.get_name() == "Alfie");
	assert(updated_dog.get_age() == 1);

	Dog* dogs = serv.get_dogs_service();
	assert(dogs[0].get_id() == 1);
}

void test_user_repo()
{
	vector<Dog> v;
	UserRepo user_repo = UserRepo(&v);

	assert(user_repo.get_length_user() == 0);
	Dog dog1 = Dog(1, "Ciobanesk", "Relu", "rrr", 3);
	Dog dog2 = Dog(2, "Labrador", "Macanache", "rtg", 5);

	user_repo.add_whishlist(dog1);
	user_repo.add_whishlist(dog2);
	assert(user_repo.get_length_user() == 2);
	Dog* dogs = user_repo.get_dogs_user();
	assert(dogs[0].get_id() == 1);
	assert(dogs[0].get_breed() == "Ciobanesk");
	assert(dogs[0].get_name() == "Relu");

}

void test_user_service()
{
	vector<Dog> v;

	UserRepo user_repo = UserRepo(&v);
	UserService user_sv = UserService(&user_repo);

	assert(user_sv.get_lenght_service_user() == 0);
	Dog dog1 = Dog(1, "Ciobanesk", "Relu", "rrr", 3);
	user_sv.add_dog_wishlist_service(dog1);

	assert(user_sv.get_lenght_service_user() == 1);
	Dog dog2 = Dog(2, "Labrador", "Macanache", "rtg", 5);

	user_sv.add_dog_wishlist_service(dog2);

	Dog* dogs = user_sv.get_dogs_wishlist_service();

	assert(dogs[0].get_age() == 3);
	assert(dogs[0].get_id() == 1);
	assert(dogs[0].get_photograph() == "rrr");
	assert(dogs[0].get_name() == "Relu");
	assert(dogs[1].get_age() == 5);
	assert(dogs[1].get_breed() == "Labrador");
	assert(dogs[1].get_photograph() == "rtg");

	Dog dog3 = Dog(11, "Iakab", "Malakay", "ffftg", 5);
	Dog dog4 = Dog(12, "Iakab", "Marean", "rdsaftg", 2);
	Dog dog5 = Dog(13, "Iakab", "Edward", "rtasdasg", 4);

	vector<Dog> v2;
	Repository repo = Repository(&v2);
	repo.add(dog3);
	repo.add(dog4);
	repo.add(dog5);
	Dog* dogs_from_repo = repo.get_dogs();
	int length = repo.get_length();
	Dog* dogs_filtered = new Dog[length];
	int length_filtered = user_sv.filter_dogs("Iakab", 7, dogs_from_repo, dogs_filtered, length);

	assert(length_filtered == 3);
	delete[] dogs_filtered;
}

void test_all()
{
	test_dog();
	test_dynamic_vect();
	test_repository();
	test_service();
	test_user_repo();
	test_user_service();
}

