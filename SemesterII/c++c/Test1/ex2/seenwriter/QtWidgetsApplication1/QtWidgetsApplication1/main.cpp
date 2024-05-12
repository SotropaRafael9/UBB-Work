#include "WriterWindow.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Domain.h"
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    Repository<Writer> writers("writers.txt");
    Repository<Idea> ideas("ideas.txt");
    vector<WriterWindow*> writersVector;

    QApplication a(argc, argv);
    for (int i = 0; i < writers.getSize(); i++) {
        WriterWindow* aux = new WriterWindow(writers[i]);
        writersVector.push_back(aux);
        aux->show();
    }
    return a.exec();
}
