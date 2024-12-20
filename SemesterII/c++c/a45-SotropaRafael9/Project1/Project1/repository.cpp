#include "Repository.h"
#include <fstream>
#include <algorithm>

Repository::Repository(std::vector<Dog>* repo_array)
{
	this->data = repo_array;

	initialise_repo();
}

void Repository::initialise_repo()
{
	add(Dog(1, "Labrador", "Johnny", "https://ro.wikipedia.org/wiki/Labrador_Retriever#/media/Fi%C8%99ier:YellowLabradorLooking.jpg", 5));
	add(Dog(2, "Corgi", "Alfie", "https://en.wikipedia.org/wiki/Welsh_Corgi#/media/File:Welchcorgipembroke.JPG", 2));
	add(Dog(3, "Husky", "Ice", "https://en.wikipedia.org/wiki/Husky#/media/File:Huskiesatrest.jpg", 3));
	add(Dog(4, "Golden Retriever", "Sarah", "https://en.wikipedia.org/wiki/Golden_Retriever#/media/File:Golden_Retriever_Dukedestiny01_drvd.jpg", 5));
	add(Dog(5, "Chihuahua", "Killer", "https://en.wikipedia.org/wiki/Chihuahua_(dog)#/media/File:Chihuahua1_bvdb.jpg", 3));
	add(Dog(6, "Labrador", "Aurelian", "https://ro.wikipedia.org/wiki/Labrador_Retriever#/media/Fi%C8%99ier:YellowLabradorLooking.jpg", 6));
	add(Dog(7, "German Shepherd", "Ilie", "https://en.wikipedia.org/wiki/German_Shepherd#/media/File:German_Shepherd_-_DSC_0346_(10096362833).jpg", 10));
	add(Dog(8, "Labrador", "Dash", "https://ro.wikipedia.org/wiki/Labrador_Retriever#/media/Fi%C8%99ier:YellowLabradorLooking.jpg", 4));
	add(Dog(9, "Doberman", "Tara", "https://en.wikipedia.org/wiki/Dobermann#/media/File:Dobermann_handling.jpg", 7));
	add(Dog(10, "Corgi", "Rita", "https://en.wikipedia.org/wiki/Welsh_Corgi#/media/File:Welchcorgipembroke.JPG", 2));
}

void Repository::add(Dog new_dog)
{
	this->data->push_back(new_dog);
}

void Repository::remove(int dog_id)
{
	int const position = get_position(dog_id);
	this->data->erase(this->data->begin() + position);
}

void Repository::update(Dog new_dog)
{
	int const position = get_position(new_dog.get_id());
	this->data->erase(this->data->begin() + position);
	this->data->insert(this->data->begin() + position, new_dog);
}

int Repository::get_position(int dog_id)
{
	int count = 0;
	for (Dog& it : *this->data)
	{
		if (it.get_id() == dog_id) return count;
		count++;
	}
	return -1;
}

int Repository::get_length()
{
	return this->data->size();
}

Dog Repository::get_element(int position)
{
	return this->data->at(position);
}

Dog* Repository::get_dogs()
{
	return this->data->data();
}

Repository::~Repository() = default;


//
//
//FileRepository::FileRepository(std::vector<Dog>* repo_array, std::string file_name)
//	:Repository(repo_array)
//{
//	this->file_name = file_name;
//}
//
//void FileRepository::load_file()
//{
//	if (!this->file_name.empty())
//	{
//		Dog new_dog;
//		std::ifstream fin(this->file_name);
//		while (fin >> new_dog)
//		{
//			if (std::find(this->data->begin(), this->data->end(), new_dog) == this->data->end())
//				this->data->push_back(new_dog);
//		}
//		fin.close();
//	}
//}
//
//void FileRepository::write_to_file()
//{
//	if (!this->file_name.empty())
//	{
//		std::ofstream fout(this->file_name);
//		for (Dog& const dog : *this->data)
//		{
//			fout << dog << "\n";
//		}
//		fout.close();
//	}
//}
//
//void FileRepository::initialise_repo()
//{
//	this->load_file();
//}
//
//void FileRepository::add(Dog new_dog)
//{
//	this->data->push_back(new_dog);
//	write_to_file();
//}
//
//void FileRepository::remove(int dog_id)
//{
//	int const position = this->get_position(dog_id);
//	this->data->erase(this->data->begin() + position);
//	write_to_file();
//}
//
//void FileRepository::update(Dog new_dog)
//{
//	int const position = get_position(new_dog.get_id());
//	this->data->erase(this->data->begin() + position);
//	this->data->insert(this->data->begin() + position, new_dog);
//	write_to_file();
//}
//
//FileRepository::~FileRepository() = default;
