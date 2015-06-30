#include "MsgBase.h"

MsgBase::MsgBase(const QString data_in):
    data(data_in)
{
    /// Payload data from Icarus has this structure
    /// T: data1 data2 ... dataN;
    /// where T: type (D - Scientific data, P - Particle info, ...)
    ///   dataN: parameter received

    QString data_aux(data_in);

    data_aux.remove(":");
    data_aux.remove(";");
    QStringList data_parameters = data_aux.split(" ");


    // Firstly, extract Data type
    this->data_type = data_parameters.at(0);

    // Now, we extract the rest of parameters
    for(int i = 1; i < data_parameters.size(); i++)
    {
        this->data_list.append(data_parameters.at(i));
    }

}

MsgBase::~MsgBase()
{

}


QString MsgBase::getMessage()
{
    return this->data;
}

QString MsgBase::getDataType() const
{
    return this->data_type;
}

QList<QVariant> MsgBase::getDataList() const
{
    return this->data_list;
}

