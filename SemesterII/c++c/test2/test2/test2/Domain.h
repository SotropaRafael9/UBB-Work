#pragma once
#include <string>
#include <vector>

class HospitalDepartament
{
private:
		std::string name;
		int number_of_doctors;
public:
	HospitalDepartament(std::string name = "", int number_of_doctors = 0);
	bool isEficient();
	std::string toString();
	~HospitalDepartament() = default;


};

class Surgery : public HospitalDepartament
{
public:
	int number_of_patience;
private:
	Surgery(int number_of_patience = 0);
	bool isEficient();
	std::string toString();
	~Surgery();
};

class NeonatalUnit : public HospitalDepartament
{
public:
	double averageGrade;
private:
	NeonatalUnit(double averageGrade);
	bool isEficient();
	std::string toString();
	~NeonatalUnit();


};