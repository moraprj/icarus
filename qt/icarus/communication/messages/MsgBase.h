#pragma once

#include <QString>
#include <QVariant>


class MsgBase
{
public:
    MsgBase(const QString data_in);
    ~MsgBase();

    QString getMessage();
    QString getDataType()const;
    QList<QVariant> getDataList()const;

protected:
    QString data;
    QString data_type;
    QList<QVariant> data_list;


};

