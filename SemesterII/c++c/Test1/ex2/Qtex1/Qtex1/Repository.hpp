#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename TData>

class Repository
{
	vector <TData> data;
public:
	Repository(string fileName)
	{
		ifstream fin(fileName);
		if(!fin.is_open() || !fin.good())
			throw exception("File could not be opened!");
		TData element;
		while (fin >> element)
			data.push_back(element);
		fin.close();

	}

	vector<TData> get_all() { return data; }

	void add(TData element)
	{
		data.push_back(element);
	}

	void remove(TData element)
	{
		data.erase(remove(data.begin(), data.end(), element), data.end());
	}

	void sort(bool (*compare)(TData, TData))
	{
		std::sort(data.begin(), data.end(), compare);
	}

	TData& operator[](int index)
	{
		return data[index];
	}

	int get_size()
	{
		return data.size();
	}

};
