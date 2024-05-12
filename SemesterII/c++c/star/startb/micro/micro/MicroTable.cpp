#include "MicroTable.h"


int MyModel::rowCount(const QModelIndex& /*parent*/) const
{
    return repo.get_bacterii().size();
}

int MyModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 4;
}

QVariant MyModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();
        Bacterie b = repo.get_bacterii()[row];


        switch (column)
        {
            case 0:
				return QString::fromStdString(b.get_name());
            case 1:
                return QString::fromStdString(b.get_species());
            case 2:
                return QString::number(b.get_size());
            case 3:
            {
				std::string s;
                for (auto d : b.get_diseases())
                {
					s += d + ", ";
				}
				return QString::fromStdString(s);
			}
			default:
				break;


                

        }
    }

    return QVariant();
}

void MyModel::update()
{
    QModelIndex topLeft = this->index(0, 0);
    QModelIndex bottomRight = this->index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
}
