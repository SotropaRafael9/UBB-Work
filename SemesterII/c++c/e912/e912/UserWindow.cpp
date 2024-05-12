#include "UserWindow.h"
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

UserWindow::UserWindow(User& u, Session& s, QWidget *parent)
    : QMainWindow(parent), usr(u), sess(s)
{
    ui.setupUi(this);
    boxi = new QMessageBox{};

    setWindowTitle(QString::fromStdString(u.getName()));

    if (usr.getType().compare("administrator") != 0)
    {
        ui.formLayout->setEnabled(false);
        ui.addButton->hide();
    }
    else
    {
        ui.formLayout_2->setEnabled(false);
        ui.bidButton->hide();
    }

    populateCombo();
    populateList();

    connectStuff();
}

UserWindow::~UserWindow()
{}

void UserWindow::update()
{
    populateList();
    populateCombo();
    ui.offersList->clear();
}

void UserWindow::populateCombo()
{
    ui.categoriesBox->clear();

    std::vector<std::string> categories;
    for (Item& item : sess.getItems())
    {
        bool found = false;
        for (auto& cat: categories)
            if (cat.compare(item.getCategory()) == 0)
            {
                found = true;
                break;
            }

        if (!found)
            categories.push_back(item.getCategory());
    }

    ui.categoriesBox->addItem(QString());
    for (auto& cat: categories)
        ui.categoriesBox->addItem(QString::fromStdString(cat));
}

void UserWindow::connectStuff()
{
    QObject::connect(ui.categoriesBox, &QComboBox::currentTextChanged, this, &UserWindow::populateList);
    QObject::connect(ui.addButton, &QPushButton::clicked, this, &UserWindow::addItem);
    QObject::connect(ui.itemsList, &QListWidget::clicked, this, &UserWindow::populateOffers);
    QObject::connect(ui.bidButton, &QPushButton::clicked, this, &UserWindow::placeBid);
}

void UserWindow::populateList(QString str)
{
    ui.itemsList->clear();

    std::vector<Item> auxv = sess.getItems();

    std::sort(auxv.begin(), auxv.end(), 
        [](Item& a, Item& b) {
            return a.getCurrentPrice() < b.getCurrentPrice();
        });

    sess.getItems() = auxv;

    for (Item& item: sess.getItems())
        if (QString::fromStdString(item.getCategory()).compare(str) == 0 || str.isEmpty())
            ui.itemsList->addItem(QString::fromStdString(item.getName() + std::string(" - ") + item.getCategory() + std::string(" - ") + std::to_string(item.getCurrentPrice())));
}

void UserWindow::addItem()
{
    std::string name = ui.nameEdit->text().toStdString();
    if (name.size() == 0)
    {
        boxi->setText(QString::fromStdString(std::string("Error: Empty name")));
        boxi->show();
        return;
    }
    std::string category = ui.categoryEdit->text().toStdString();
    std::string price = ui.priceEdit->text().toStdString();
    int currentP = stoi(price);
    if (currentP <= 0)
    {
        boxi->setText(QString::fromStdString(std::string("Error: Price is not positive")));
        boxi->show();
        return;
    }

    sess.add(name, category, currentP);
}

void UserWindow::populateOffers()
{
    ui.offersList->clear();

    int index = ui.itemsList->currentRow();

    std::vector<std::tuple<int, std::string, int>> offers = sess.getItems()[index].getOffers();

    std::sort(offers.begin(), offers.end(), 
        [](std::tuple<int, std::string, int> a, std::tuple<int, std::string, int> b) {
            return std::get<1>(a) > std::get<1>(b);
        });

    for (auto& offer : offers)
        ui.offersList->addItem(QString::fromStdString(std::to_string(std::get<0>(offer)) + std::string(" - ") + std::get<1>(offer) + std::string(" - ") + std::to_string(std::get<2>(offer))));
}

void UserWindow::placeBid()
{
    int index = ui.itemsList->currentRow();
    int sum = stoi(ui.bidEdit->text().toStdString());

    if (sum < sess.getItems()[index].getCurrentPrice())
    {
        boxi->setText(QString::fromStdString(std::string("Error: Price is too low")));
        boxi->show();
        return;
    }

    sess.bid(index, sum, usr.getId());
}
