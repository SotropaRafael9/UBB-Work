#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename TData>
class Repository
{
	vector<TData> data;
public:
	Repository(string fileName) {
		ifstream fin(fileName.c_str());
		if (!fin.is_open() || !fin.good())
			throw std::exception("File does not exist!");

		TData temp;
		while (fin >> temp) {
			data.push_back(temp);
		}
		fin.close();
	}
	vector <TData> getAll() {
		return data;
	}
	void add(TData newData) {
		data.push_back(newData);
	}
	void remove(int index) {
		swap(data[index], data.end());
		data.pop_back();
	}
	void update(int index, TData newData) {
		data[index] = newData;
	}
	void sort(bool (*compare)(TData, TData)) {
		std::sort(data.begin(), data.end(), compare);
	}
	int getSize() {
		return data.size();
	}
	TData& operator[](int index) {
		return data[index];
	}

};