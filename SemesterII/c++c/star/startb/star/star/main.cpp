#include "star.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    star w;
    w.show();
    return a.exec();
}
