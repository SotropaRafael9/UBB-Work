#pragma once

#include <QAbstractTableModel>
#include "repository.h"


class StarsTableModel : public QAbstractTableModel
{
private:
	Repository& repository; 
public:
	StarsTableModel(Repository& r) : repository{ r } {}   
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;

	void updateInternalData();
	void addStar(std::string name, std::string constellation, int RA, int dec, int diameter);

	std::vector<Star> getAllStars() const { return this->repository.getStars(); } 
};

