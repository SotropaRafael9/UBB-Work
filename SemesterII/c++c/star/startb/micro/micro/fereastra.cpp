#include "fereastra.h"
#include "MicroTable.h"
#include <qmessagebox.h>

fereastra::fereastra(Biologist b,Repository r, MyModel* model,QWidget *parent)
	: b(b), repo(r),model(model), QMainWindow(parent)
{
	
	ui.setupUi(this);
	connect();
	ui.tableView->setModel(model);
	

}

void fereastra::connect()
{
	for (auto& m : b.get_bacterii())
	{
		ui.comboBox->addItem(QString::fromStdString(m.get_species()));
	}
	QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
		std::string name = ui.nameline->text().toStdString();
		std::string species = ui.specieline->text().toStdString();
		int size = ui.sizeline->text().toInt();
		std::string disease = ui.diseasesline->text().toStdString();
		for (auto& m : b.get_bacterii())
		{
			if (m.get_species() == species && m.get_name() == name)
			{
				QMessageBox::warning(this, "Warning", "Bacterie deja existenta!");
				return;
			}

		}
		Bacterie b(name, species, size, { disease });

		repo.get_bacterii().push_back(b);

		model->update();
		});



	

}

fereastra::~fereastra()
{}


