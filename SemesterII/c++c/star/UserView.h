#pragma once

#include <QMainWindow>
#include "ui_UserView.h"
#include "StarsTableModel.h"
#include "astronomer.h"

class UserView : public QMainWindow
{
	Q_OBJECT

public:
	UserView(Astronomer& a, StarsTableModel* model, QWidget* parent = nullptr);
	~UserView();

private:
	Ui::UserViewClass ui;
	StarsTableModel* starsModel; 
	Astronomer& astronomer;

	void connectSignalAndSlots(); 
};
