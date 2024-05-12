#pragma once
#include <QAbstractTableModel>
#include "Domain.hpp"
#include "Repository.hpp"
#include <algorithm>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qformlayout.h>
#include <qtablewidget.h>
#include <qmessagebox.h>
#include <qcombobox.h>
#include <qboxlayout.h>
#include <qwidget.h>
#include <qdialog.h>

class WriterTableModel : public QAbstractTableModel
{
private:
	Q_OBJECT
		Repository<Writer>& repo;
	string headerStrings[2] = { "Name", "Expertise" };
public:
	/*vector<Writer> get_sorted_writers()const
	{
		auto writers = repo.get_all();
		sort(write)
		return writers;
	}*/
	WriterTableModel(Repository<Writer>& r) : repo{ r } {}
		int rowCount(const QModelIndex& parent = QModelIndex()) const override
		{
			return repo.get_size();
		}
		int columnCount(const QModelIndex& parent = QModelIndex()) const override
		{
			return 2;
		}
		QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
		{
			int row = index.row();
			int column = index.column();
			Writer w = repo[row];
			if (role == Qt::DisplayRole)
			{
				if (column == 0)
					return QString::fromStdString(w.get_name());
				else if (column == 1)
					return QString::fromStdString(w.get_expertise());
			}
			return QVariant();
		}
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
		{
			if (role == Qt::DisplayRole)
			{
				if (orientation == Qt::Horizontal)
					return QString::fromStdString(headerStrings[section]);
				else if (orientation == Qt::Vertical)
					return QString::fromStdString(to_string(section + 1));
			}
			return QVariant();
		}
		void setRepo(Repository<Writer>& r)
		{
			repo = r;
		}
		void update()
		{
			emit layoutChanged();
		}
};

class AddWindow : public QDialog
{

};



