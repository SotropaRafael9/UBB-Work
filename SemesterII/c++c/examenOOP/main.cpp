#include "examenOOP.h"
#include <QtWidgets/QApplication>
#include"repository.h"
#include"domain.h"
#include"UserView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{};
    for (auto& x : repo.get_drivers())
    {
        UserView* users = new UserView{ repo,x };
        users->setWindowTitle(QString::fromStdString(x.get_name() + " " + to_string(x.get_lat()) + " " + to_string(x.get_long())));
        users->show();
    }
    return a.exec();
}
