//
// Created by Alexe Andra on 16.05.2023.
//
#include "repositoryfile.h"
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
RepositoryFile::RepositoryFile() {
    this -> fileName = nullptr;
}

RepositoryFile::RepositoryFile(char *filename) {
    this->fileName = filename;
    ifstream f(this->fileName);
    if (f.is_open()){
        int x = 99;
    }
    while(!f.eof()){
        int cod, pret, frecventa;
        string name;
        char *nume = new char [20];
        f >> cod;
        f >> name;
        f >> pret >> frecventa;
        strcpy(nume, name.c_str());
        Produs p(cod, pret, nume);
        Repository::add(p);
        int i = Repository::search(nume);
        Repository::setFrequence(i, frecventa + 1);
    }
    f.close();
}

RepositoryFile::~RepositoryFile() {

}

Produs *RepositoryFile::getAll() {
    return Repository::getAll();
}

void RepositoryFile::add(Produs &produs) {
    Repository::add(produs);
    saveToFile();
}

int RepositoryFile::search(char * nume) {
    return Repository::search( nume);
}

int RepositoryFile::getDistinctElements() {
    return Repository::getDistinctElements();
}

int *RepositoryFile::getNumarProduse() {
    return Repository::getNumarProduse();
}

int RepositoryFile::give(char *nume) {
    return Repository::give(nume);
}

void RepositoryFile::remove(int i) {
    Repository::remove(i);
}

void RepositoryFile::check(char *nume) {
    Repository::check(nume);
}

void RepositoryFile::saveToFile() {
    ofstream f(this -> fileName);
    int l = getDistinctElements();
    for(int i = 0; i < l; i++){
        std::cout << this ->produse[i].getCode() << " " << this ->produse[i].getName() << " " << this ->produse[i].getPrice() << " " << this -> numarProduse[i] << endl;
        f << this ->produse[i].getCode() << " " << this ->produse[i].getName() << " " << this ->produse[i].getPrice() << " " << this -> numarProduse[i] << endl;
    }
}
