#include "UserView.h"
#include "StarsTableModel.h"
#include <QMessageBox>
#include <qsortfilterproxymodel.h>
#include <qpainter.h>


UserView::UserView(Astronomer& a, StarsTableModel* model, QWidget *parent) 
	: QMainWindow(parent), starsModel{ model }, astronomer{ a } 
{
	ui.setupUi(this);
	connectSignalAndSlots();
	ui.starsTableView->setModel(this->starsModel);
}

UserView::~UserView()
{}

void UserView::connectSignalAndSlots()
{
	QObject::connect(ui.checkBox, &QCheckBox::clicked, [&]() {

		if (!ui.checkBox->isChecked()) 
		{
			ui.starsTableView->setModel(this->starsModel);
			return;
		}
		
		QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
		proxyModel->setSourceModel(this->starsModel);
		proxyModel->setFilterFixedString(QString::fromStdString(astronomer.getConstellation())); 
		proxyModel->setFilterKeyColumn(1); 
		ui.starsTableView->setModel(proxyModel); 

		});

	QObject::connect(ui.addButton, &QPushButton::clicked, [&]() {

		std::string name = ui.nameLineEdit->text().toStdString();
		std::string constellation = astronomer.getConstellation();
		int RA = ui.raLineEdit->text().toInt(); 
		int dec = ui.decLineEdit->text().toInt(); 
		int diameter = ui.diameterLineEdit->text().toInt(); 

		if (name == "" || diameter < 11)
		{
			QMessageBox::critical(this, "Error", "Introduce a valid input");
			return;
		}

		try
		{
			starsModel->addStar(name, constellation, RA, dec, diameter);
		}
		catch (std::exception& e)
		{
			QMessageBox::critical(this, "Error", e.what());
			return;
		}
		});

}

