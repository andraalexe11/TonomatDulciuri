//
// Created by Alexe Andra on 07.05.2023.
//

#ifndef UNTITLED4_SERVICE_H
#define UNTITLED4_SERVICE_H
#include "repositoryfile.h"
class Service{
private:
    RepositoryFile* repository;
public:
    Service();
    Service(RepositoryFile* &r);
    ~Service();
    Produs* getAll();
    int* getNumarProduse();
    int getDistinctElements();
    void add(int cod, int pret, char* nume);
    int giveProduct(char* nume);
    int getPrice(char * nume);
    void check(char* nume);
};
#endif //UNTITLED4_SERVICE_H
