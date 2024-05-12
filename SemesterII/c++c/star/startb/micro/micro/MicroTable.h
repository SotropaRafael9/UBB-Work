#pragma once
#include <QAbstractTableModel>
#include "Repository.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    Repository& repo;
public:
    MyModel(Repository& repo) : repo(repo) {};

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    void update();
};
