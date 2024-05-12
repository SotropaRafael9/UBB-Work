#include "StarsTableModel.h"

int StarsTableModel::rowCount(const QModelIndex& parent) const
{
    return repository.getStars().size();
}

int StarsTableModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant StarsTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
		int row = index.row();
		int column = index.column();
		Star s = repository.getStars()[row];
        switch (column)
        {
		case 0:
			return QString::fromStdString(s.getName());
		case 1:
			return QString::fromStdString(s.getConstellation());
		case 2:
			return QString::number(s.getRA());
		case 3:
			return QString::number(s.getDec());
		case 4:
			return QString::number(s.getDiameter());
		default:
			break;
		}
	}

    return QVariant();
}

QVariant StarsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if(orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Name" };
			case 1:
				return QString{ "Constellation" };
			case 2:
				return QString{ "RA" };
			case 3:
				return QString{ "Dec" };
			case 4:
				return QString{ "Diameter" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool StarsTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if(role != Qt::EditRole)
		return false; 

	int row = index.row();
	int column = index.column();

	Star& star = this->repository.getStars()[row];

	switch (column)
	{
	case 0:
	{
		std::string name = value.toString().toStdString();
		if(!name.empty())
			star.setName(name); 
		break;
	}
	case 1:
	{
		std::string constellation = value.toString().toStdString();
		star.setConstellation(constellation);
		break;
	}
	case 2:
	{
		int ra = value.toInt();
		star.setRA(ra); 
		break;
	}
	case 3:
	{
		int dec = value.toInt();
		star.setDec(dec); 
		break;
	}
	case 4:
	{
		int diameter = value.toInt();
		if(diameter > 10)
			star.setDiameter(diameter); 
		break;
	}
	default:
		break;
	}

	emit dataChanged(index, index); 
	
	return true;
}

Qt::ItemFlags StarsTableModel::flags(const QModelIndex& index) const
{
	if(index.column() == 1)
		return Qt::ItemFlags{};

	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled; 
}

void StarsTableModel::updateInternalData()
{
	QModelIndex topLeft = this->index(0, 0); 
	QModelIndex bottomRight = this->index(this->rowCount() - 1, this->columnCount() - 1); 
	emit dataChanged(topLeft, bottomRight); 
}

void StarsTableModel::addStar(std::string name, std::string constellation, int RA, int dec, int diameter)
{
	beginInsertRows(QModelIndex{}, this->rowCount(), this->rowCount());  
	repository.addStar(Star{name, constellation, RA, dec, diameter});   
	endInsertRows();  

	emit dataChanged(this->index(0, 0), this->index(this->rowCount() - 1, this->columnCount() - 1)); 
}
