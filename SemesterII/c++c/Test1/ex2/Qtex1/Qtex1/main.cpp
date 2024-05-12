#include "Qtex1.h"
#include "Domain.hpp"
#include "Repository.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qtex1 w;
    w.show();
    return a.exec();
}
