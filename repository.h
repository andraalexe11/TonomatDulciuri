//
// Created by Alexe Andra on 02.05.2023.
//

#ifndef UNTITLED4_REPOSITORY_H
#define UNTITLED4_REPOSITORY_H
#include "produs.h"
class Repository{
protected:
    Produs* produse;
    int* numarProduse;
    int distinctelements;
    int size;
    void resize();
public:
    Repository();
    Repository(Produs* produse, int* numarProduse, int size, int distinctelements);
    ~Repository();
    int getDistinctElements();
    int* getNumarProduse();
    Produs* getAll();
    int search(char* nume);
    virtual void add(Produs produs);
    int give(char* nume);
    void remove(int i);
    void check(char* nume);
    void setFrequence(int i, int nr);
};
#endif //UNTITLED4_REPOSITORY_H
