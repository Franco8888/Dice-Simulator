#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <QList>
class RandomNumberGeneratorMemento;

class RandomNumberGenerator{

public:
    RandomNumberGenerator();
    void setMinMax(int min, int max);
    QList<int> getRandomNumber(int n) ;
    RandomNumberGeneratorMemento* createMemento()const;
    void setMemento(RandomNumberGeneratorMemento* m);

private:
    int seed;
    int minimum;
    int maximum;
    void setSeed();
    bool flag;
    QList<int> generateNumbers(int n)const;
};

#endif // RANDOMNUMBERGENERATOR_H
