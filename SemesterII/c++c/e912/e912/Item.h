#pragma once
#include <string>
#include <vector>
#include <tuple>

class Item
{
private:
	std::string name;
	std::string category;
	int currentPrice;
	std::vector<std::tuple<int, std::string, int>> offers;

public:
	std::string getName() const;
	std::string getCategory() const;
	int getCurrentPrice() const;
	std::vector<std::tuple<int, std::string, int>>& getOffers();

	void setCurrentPrice(int price);

	Item(std::string n, std::string c, int p, std::vector<std::tuple<int, std::string, int>> o);
};

