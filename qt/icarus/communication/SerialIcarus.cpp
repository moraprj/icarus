#include "SerialIcarus.h"

SerialIcarus::SerialIcarus(const QFile &conf_file):
    LinkLayerIcarus(conf_file)
{
    // Initialize and configure
    this->puerto_com = new QSerialPort();

    this->puerto_com->setPortName(config_file->read<QString>(QString("Port_Name"), QString("/dev/ttyUSB0")));
    this->puerto_com->setBaudRate(config_file->read<qint32>(QString("Baudrate"), 115200));

    this->puerto_com->setDataBits(QSerialPort::Data8);
    this->puerto_com->setParity(QSerialPort::NoParity);
    this->puerto_com->setStopBits(QSerialPort::OneStop);
    this->puerto_com->setFlowControl(QSerialPort::NoFlowControl);


}

SerialIcarus::~SerialIcarus()
{
    this->puerto_com->close();

}

void SerialIcarus::initialize()
{
    this->puerto_com->open(QIODevice::ReadWrite);

    // Connect Serial buffer to readData function
    connect(this->puerto_com, SIGNAL(readyRead()), this, SLOT(readData()));

}

void SerialIcarus::readData()
{
    // Store data input into buffer
    this->saveData(this->puerto_com->readAll());

    QSharedPointer<MsgBase> message;
    while(!(message = this->getNextMessage()).isNull())
    {
        if(message->getDataType() == MsgData::Type)
        {
            MsgData msg_data(message->getMessage());
            // Create Event
        }

    }


}

