#include "Domain.h"


istream& operator>>(istream& fin, Writer& data)
{
	string input;
	getline(fin, input);
	data.setName(input);
	getline(fin, input);
	
	data.setExpertise(input);
	return fin;
}

istream& operator>>(istream& fin, Idea& data)
{
	string input;
	getline(fin, input);
	data.set_description(input);
	getline(fin, input);
	data.set_status(input);
	getline(fin, input);
	data.set_creator(input);
	getline(fin, input);
	data.set_act(input);
	return fin;
}