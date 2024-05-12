#pragma once

#include <string>
#include <fstream>

using namespace std;
class Writer
{
private:
	string name, expertise;
public:
	void set_name(string n) { name = n; }
	void set_expertise(string e) { expertise = e; }

	string get_name() { return name; }
	string get_expertise() { return expertise; }

	string to_string() { return name + " " + expertise; }

};


class Idea
{
	string description, status, creator, act;
public:
	void set_description(string d) { description = d; }
	void set_status(string s) { status = s; }
	void set_creator(string c) { creator = c; }
	void set_act(string a) { act = a; }
	string get_description() { return description; }
	string get_status() { return status; }
	string get_creator() { return creator; }
	string get_act() { return act; }
	string to_string() { return description + " " + status + " " + creator + " " + act; }

	
};

