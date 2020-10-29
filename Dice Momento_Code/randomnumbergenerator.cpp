#include "randomnumbergenerator.h"
#include "randomnumbergeneratormemento.h"
#include <QTime>

RandomNumberGenerator::RandomNumberGenerator(): seed(999), minimum(0), maximum(0), flag(false){
}

void RandomNumberGenerator::setMinMax(int min, int max){
    minimum = min;
    maximum = max;
}

QList<int> RandomNumberGenerator::getRandomNumber(int n){
    if(flag){
        flag = false;
    } else
        setSeed();
    return generateNumbers(n);
}

RandomNumberGeneratorMemento* RandomNumberGenerator::createMemento()const{
    RandomNumberGeneratorMemento* m = new RandomNumberGeneratorMemento();
    m->setState(seed);
    return m;
}

void RandomNumberGenerator::setMemento(RandomNumberGeneratorMemento *m){
    seed = m->getState();
    qsrand(seed);
    flag = true;
}

void RandomNumberGenerator::setSeed(){
    seed = QTime::currentTime().msec();
    qsrand(seed);
}

QList<int> RandomNumberGenerator::generateNumbers(int n) const{
    QList<int> result;
    for(int i = 0; i < n; i++){
      result.append(qrand() % (maximum) + (minimum));
    }
    return result;
}
