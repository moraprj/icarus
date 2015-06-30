#pragma once

#include <QFile>
#include <QTextStream>

class ConfigFile : public QFile
{
public:
    ConfigFile(const QFile &conf_file);
    ~ConfigFile();

    template<class T>
    T read(QString key, T default_value){
        if(!this->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&this->fichero);
            QString value;

            while(!stream.atEnd() && value.isEmpty())
            {
                QString line = stream.readLine();
                if(line.contains(key, Qt::CaseInsensitive))
                {
                    value = line.split("=").at(1);
                }
            }

            if(value.isEmpty())
            {
                QString string_to_store = key + QString("=%1").arg(default_value);
                this->write(string_to_store.toLatin1());
            }

            this->close();
            QVariant value_returned(value);
            return value_returned.value<T>();
        }
    }

private:
    QFile fichero;
};
