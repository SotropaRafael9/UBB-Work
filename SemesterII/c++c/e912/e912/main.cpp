#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include <vector>
#include "User.h"
#include "Session.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<User> users;

    std::string auxName;
    int auxId;
    std::string auxType;
    std::ifstream file("users.txt");
    getline(file, auxName);
    while (!file.eof())
    {
        std::string auxIdS;
        getline(file, auxIdS);
        auxId = stoi(auxIdS);
        getline(file, auxType);

        users.push_back(User(auxName, auxId, auxType));

        getline(file, auxName);
    }

    file.close();

    Session session;

    std::vector<UserWindow*> windows;
    for (User& user: users)
    {
        windows.push_back(new UserWindow(user, session));
    }

    for (auto& wind: windows)
        session.addObserver(wind);

    for (auto& wind: windows)
        wind->show();

    return a.exec();
}
