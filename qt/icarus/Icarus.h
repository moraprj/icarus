#ifndef ICARUS_H
#define ICARUS_H

#include <communication/SerialIcarus.h>



class Icarus
{
public:
    Icarus();
    ~Icarus();

private:
    SerialIcarus serial;
};

#endif // ICARUS_H
