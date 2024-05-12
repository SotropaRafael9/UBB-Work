#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UserWindow.h"
#include "Observer.h"
#include "User.h"
#include "Session.h"
#include <QMessageBox>

class UserWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    UserWindow(User& u, Session& s, QWidget *parent = nullptr);
    ~UserWindow();

    void update();  // to do -done

    void populateCombo();
    void connectStuff();
    void populateList(QString str = QString());
    void addItem();  // to link to session -done
    void populateOffers();
    void placeBid();

private:
    Ui::UserWindowClass ui;

    User& usr;
    Session& sess;
    QMessageBox* boxi;
};
