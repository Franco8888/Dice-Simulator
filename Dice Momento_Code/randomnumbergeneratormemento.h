#ifndef RANDOMNUMBERGENERATORMEMENTO_H
#define RANDOMNUMBERGENERATORMEMENTO_H

#include "randomnumbergenerator.h"

class RandomNumberGeneratorMemento
{
private:
    RandomNumberGeneratorMemento();    
    friend class RandomNumberGenerator;
    void setState(int s);
    int getState() const;
    int seed;
};

#endif // RANDOMNUMBERGENERATORMEMENTO_H
