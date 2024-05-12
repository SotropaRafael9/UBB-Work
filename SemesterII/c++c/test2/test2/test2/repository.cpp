#include "Repository.h"
#include <vector>
#include <fstream>
#include <algorithm>


Controller::Controller(std::vector<HospitalDepartament>* repo_array)
{
	this->data = repo_array;
}

void Controller::addDepartament(HospitalDepartament newHospitalDepartament)
{
	this->data->push_back(newHospitalDepartament);
}

HospitalDepartament* Controller::getAllDepartaments()
{
	return this->data;
}

Controller::~Controller()
{
}


FileRepository::FileRepository(std::vector<HospitalDepartament>* repo_array, std::string file_name)
	:Controller(repo_array)
{
	this->file_name = file_name;
}

void FileRepository::load_file()
{
	if (!this->file_name.empty())
	{
		HospitalDepartament newHospitalDepartament;
		std::ifstream fin(this->file_name);
		while (fin >> newHospitalDepartament)
		{
			if (std::find(this->data->begin(), this->data->end(), newHospitalDepartament) == this->data->end())
				this->data->push_back(newHospitalDepartament);
		}
		fin.close();
}

void FileRepository::write_to_file()
{
	if (!this->file_name.empty())
	{
		std::ofstream fout(this->file_name);
		for (HospitalDepartament& const HospitalDepartament : *this->data)
		{
			fout << HospitalDepartament.toString() << "\n";
		}
		fout.close();
	}
}

void FileRepository::addDepartament(HospitalDepartament newHospitalDepartament)
{
	this->data->push_back(new_dog);
	write_to_file();
}

FileRepository::~FileRepository()
{
}


