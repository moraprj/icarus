#pragma once

#include <QFile>
#include <QPointer>
#include <communication/messages/MsgBase.h>
#include "ConfigFile.h"

class LinkLayerIcarus : public QObject
{
public:
    LinkLayerIcarus(const QFile & conf_file);
    ~LinkLayerIcarus();

    virtual void saveData(QByteArray data_read);

    virtual QSharedPointer<MsgBase> getNextMessage();

protected:
    QSharedPointer<ConfigFile> config_file;
    QSharedPointer<QByteArray> buffer;
};

