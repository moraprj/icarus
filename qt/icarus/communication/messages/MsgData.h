#pragma once

#include "MsgBase.h"


class MsgData : public MsgBase
{
public:
    static const QString Type;
    static const int MAX_PARAMETERS = 5;

    MsgData(const QString data_in);
    ~MsgData();

private:
    QList<double> orientation;
    double altitude;
    double temperature;
};

