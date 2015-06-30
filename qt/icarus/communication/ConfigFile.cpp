#include "ConfigFile.h"

ConfigFile::ConfigFile(const QFile & conf_file):
    QFile(conf_file.fileName())
{

}

ConfigFile::~ConfigFile()
{

}

