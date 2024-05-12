#include "Repository.h"
#include <fstream>
#include <tuple>

std::vector<Item>& Repository::getItems()
{
    return items;
}

Repository::Repository()
{
    std::ifstream file("items.txt");

    std::string auxName;
    std::string auxCategory;
    int auxCurrentPrice;
    int count;
    std::vector<std::tuple<int, std::string, int>> auxOffers;

    getline(file, auxName);
    while (!file.eof())
    {
        getline(file, auxCategory);
        std::string auxCurrentPriceS;
        getline(file, auxCurrentPriceS);
        auxCurrentPrice = stoi(auxCurrentPriceS);
        std::string countS;
        getline(file, countS);
        if (countS.compare("0") == 0)
            count = 0;
        else
           count = stoi(countS);
        auxOffers.clear();
        for (int i = 0; i < count; i++)
        {
            std::string auxUserId;
            getline(file, auxUserId, ';');
            std::string auxDate;
            getline(file, auxDate, ';');
            std::string auxSum;
            getline(file, auxSum);
            auxOffers.push_back(std::make_tuple(stoi(auxUserId), auxDate, stoi(auxSum)));
        }

        items.push_back(Item(auxName, auxCategory, auxCurrentPrice, auxOffers));

        getline(file, auxName);
    }

    file.close();
}

Repository::~Repository()
{
    std::ofstream file("items.txt");
    
    for (Item& item: items)
    {
        file << item.getName() << '\n';
        file << item.getCategory() << '\n';
        file << item.getCurrentPrice() << '\n';
        file << item.getOffers().size() << '\n';
        for (auto& offer: item.getOffers())
            file << std::get<0>(offer) << ';' << std::get<1>(offer) << ';' << std::get<2>(offer) << '\n';
    }

    file.close();
}

void Repository::addItem(std::string n, std::string c, int p)
{
    Item i(n, c, p, std::vector<std::tuple<int, std::string, int>>());

    items.push_back(i);
}

void Repository::bidItem(int index, int sum, int userId)
{
    items[index].setCurrentPrice(sum);
    items[index].getOffers().push_back(std::make_tuple(userId, "2023.06.13", sum));
}
