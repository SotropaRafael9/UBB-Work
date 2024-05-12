#include "micro.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "fereastra.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{};
    MyModel* model = new MyModel{ repo };
    for (auto& b : repo.get_biologists())
    {
		fereastra* f = new fereastra{b, repo, model };
        f->setWindowTitle(QString::fromStdString(b.get_name()));
        f->show();

	}



    return a.exec();
}
