#include "User.h"

std::string User::getName() const
{
    return name;
}

int User::getId() const
{
    return id;
}

std::string User::getType() const
{
    return type;
}

User::User(std::string n, int i, std::string t)
{
    name = n;
    id = i;
    type = t;
}
