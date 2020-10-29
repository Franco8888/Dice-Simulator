#include "randomnumbergeneratormemento.h"

RandomNumberGeneratorMemento::RandomNumberGeneratorMemento(){
}

void RandomNumberGeneratorMemento::setState(int s){
    seed = s;
}

int RandomNumberGeneratorMemento::getState()const{
    return seed;
}
