#include "Domain.hpp"

ifstream& operator>>(ifstream& fin, Writer& data)
{
	string input;
	getline(fin, input);
	data.set_name(input);

	getline(fin, input);
	data.set_expertise(input);


	return fin;
}

ifstream& operator>>(ifstream& fin, Idea& data)
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
