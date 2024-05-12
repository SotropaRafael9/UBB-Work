#pragma once
#include "Domain.h"
#include <vector>


class Controller {
protected:
	std::vector<HospitalDepartament>* data;

public:
	Controller(std::vector<HospitalDepartament>* repo_array);
	virtual void addDepartament(HospitalDepartament newHospitalDepartament);
	virtual HospitalDepartament* getAllDepartaments();
	~Controller();
};


class FileRepository : public Controller
{
private:
	std::string file_name;

public:
	FileRepository(std::vector<HospitalDepartament>* repo_array, std::string file_name);

	void load_file();

	void write_to_file();

	void addDepartament(HospitalDepartament newHospitalDepartament) override;


	~FileRepository();
};