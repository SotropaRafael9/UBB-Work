#include "Item.h"

std::string Item::getName() const
{
    return name;
}

std::string Item::getCategory() const
{
    return category;
}

int Item::getCurrentPrice() const
{
    return currentPrice;
}

std::vector<std::tuple<int, std::string, int>>& Item::getOffers()
{
    return offers;
}

void Item::setCurrentPrice(int price)
{
    currentPrice = price;
}

Item::Item(std::string n, std::string c, int p, std::vector<std::tuple<int, std::string, int>> o)
{
    name = n;
    category = c;
    currentPrice = p;
    offers = o;
}
