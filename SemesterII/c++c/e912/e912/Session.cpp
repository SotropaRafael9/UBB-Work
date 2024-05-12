#include "Session.h"

std::vector<Item>& Session::getItems()
{
    return repo.getItems();
}

void Session::add(std::string n, std::string c, int p)
{
    repo.addItem(n, c, p);
    notify();
}

void Session::bid(int index, int sum, int userId)
{
    repo.bidItem(index, sum, userId);
    notify();
}
