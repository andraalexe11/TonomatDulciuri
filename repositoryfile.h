//
// Created by Alexe Andra on 15.05.2023.
//

#ifndef UNTITLED4_REPOSITORYFILE_H
#define UNTITLED4_REPOSITORYFILE_H
#include "repository.h"
class RepositoryFile: public Repository{
private:
    Produs* produse;
    char* fileName;
    void saveToFile();
    int* numarProduse;
public:
    RepositoryFile();
    RepositoryFile(char* filename);
    ~RepositoryFile();
    Produs* getAll();
    void add(Produs& produs);
    int search(char* nume);
    int getDistinctElements();
    int* getNumarProduse();
    int give(char* nume);
    void remove(int i);
    void check(char* nume);
};



#endif //UNTITLED4_REPOSITORYFILE_H
