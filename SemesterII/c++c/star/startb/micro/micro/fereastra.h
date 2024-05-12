#pragma once

#include <QMainWindow>
#include "ui_fereastra.h"
#include "Domain.h"
#include "Repository.h"
#include "MicroTable.h"

class fereastra : public QMainWindow
{
	Q_OBJECT
	
public:
	fereastra(Biologist b,Repository r, MyModel* model,QWidget *parent = nullptr);
	void connect();

	~fereastra();

private:
	Ui::fereastraClass ui;
	Biologist b;
	Repository repo;
	MyModel* model;
};
