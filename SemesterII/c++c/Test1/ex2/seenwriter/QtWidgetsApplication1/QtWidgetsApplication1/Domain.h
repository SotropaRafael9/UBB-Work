#pragma once

#include <string>
#include <fstream>

using namespace std;
class Writer
{
	string name;
	string expertise;
public:
	void setName(string newName) {
		name = newName;
	}
	void setExpertise(string newExpertise) {
		expertise = newExpertise;
	}
	
	string getName() {return name;}
	string getExpertise() {return expertise;}
	string toString() {
		return name + " " + expertise;}

};

istream& operator>>(istream& fin, Writer& data);

class Idea
{
private:
	string description;
	string status;
	string creator;
	string act;
public:
	void set_description(string newDescription) { description = newDescription; }
	void set_status(string newStatus) { status = newStatus; }
	void set_creator(string newCreator) { creator = newCreator; }
	void set_act(string newAct) { act = newAct; }

	string get_description() { return description; }
	string get_status() { return status; }
	string get_creator() { return creator; }
	string get_act() { return act; }

	string to_string() {
		return description + " " + status + " " + creator + " " + act;
	}
};

istream& operator>>(istream& fin, Idea& data);
