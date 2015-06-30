#pragma once
#include <QFileInfo>
#include <QPointer>
#include <QSerialPort>
#include "LinkLayerIcarus.h"

#include <communication/messages/MsgBase.h>
#include <communication/messages/MsgData.h>

class SerialIcarus : public LinkLayerIcarus
{
    Q_OBJECT
public:
    SerialIcarus(const QFile &conf_file);
    ~SerialIcarus();

    virtual void initialize();

private slots:
    void readData();

private:
    QPointer<QSerialPort> puerto_com;
};

