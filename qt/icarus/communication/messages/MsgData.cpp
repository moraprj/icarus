#include "MsgData.h"

const QString MsgData::Type = QString("D");

MsgData::MsgData(const QString data_in):
    MsgBase(data_in)
{
    if(this->getDataType() == MsgData::Type)
    {
        QList<QVariant> scientific_data = this->getDataList();

        if(scientific_data.size() != MsgData::MAX_PARAMETERS)
        {
            throw;
        }

        for(int i = 0; i < 3; i++)
        {
            this->orientation.append(scientific_data.at(i).toDouble());
        }

        this->altitude = scientific_data.at(3).toDouble();
        this->temperature = scientific_data.at(4).toDouble();

    }else{
        throw;
    }

}

MsgData::~MsgData()
{

}

