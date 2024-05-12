#include <QtWidgets/QApplication>
#include "UserView.h"
#include "repository.h"
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repository{};
    StarsTableModel* model = new StarsTableModel{ repository }; 

    std::vector<Astronomer> astronomers  = repository.getAstronomers(); 

    for (auto& astronomer : astronomers)
    {
		UserView* userView = new UserView{ astronomer, model };
        userView->setWindowTitle(QString::fromStdString(astronomer.getName())); 
		userView->show();
	}


    return a.exec();
}
