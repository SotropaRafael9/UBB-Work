#pragma once

#include <string>

class Astronomer
{
private:
	std::string name;
	std::string constellation;
public:
	Astronomer();
	Astronomer(std::string name, std::string constelation);
	std::string getName() const;
	std::string getConstellation() const;
	//std::string toString();
};


class Star
{
private:
	std::string name;
	std::string constellation;
	int RA;
	int Dec;
	int diameter;
public:
	Star();
	Star(std::string name, std::string constelation, int RA, int Dec, int diameter);
	std::string getName() const;
	std::string getConstellation() const;
	int getRA() const;
	int getDec() const;
	int getDiameter() const;
	//std::string toString();

	void setName(std::string name);
	void setConstellation(std::string constellation);
	void setRA(int RA); 
	void setDec(int Dec); 
	void setDiameter(int diameter); 
};