#include "LinkLayerIcarus.h"

LinkLayerIcarus::LinkLayerIcarus(const QFile &conf_file)
{
    this->config_file = QSharedPointer<ConfigFile>(new ConfigFile(conf_file));

    // Initialize buffer data input
    this->buffer = QSharedPointer<QByteArray>(new QByteArray());

}

LinkLayerIcarus::~LinkLayerIcarus()
{

}

void LinkLayerIcarus::saveData(QByteArray data_read)
{
    this->buffer->append(data_read);

}

QSharedPointer<MsgBase> LinkLayerIcarus::getNextMessage()
{
    QSharedPointer<MsgBase> message;
    int index_start = 0;

    // The token ":" must be the second in a message, so if the colon
    // appears at first position, the message type may be lost
    while((index_start = this->buffer->indexOf(":"), index_start)<1)
    {
        if(index_start == -1) // Not found
        {
            return message; //Empty
        }
    }

    // Now, we search for the end of the message. If the method indexOf
    // returns -1, the buffer has no token ";", so the message is incomplete
    int index_end = this->buffer->indexOf(";", index_start);
    if(index_end == -1) // Not found
    {
        return message; //Empty
    }

    // If we found a message in the buffer, we extract it and pop it from the buffer
    QString message_str(this->buffer->mid(index_start -1, index_end - index_start + 1));
    this->buffer->remove(0, index_end);

    message = QSharedPointer<MsgBase>(new MsgBase(message_str));
    return message;
}

