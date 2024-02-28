//
// Created by Alexe Andra on 08.05.2023.
//
#include "service.h"

Service::Service() {
    RepositoryFile* repository1;
    this -> repository = repository1;
}

Service::Service(RepositoryFile* &r) {
    this -> repository = r;
}

Service::~Service() {

}

Produs *Service::getAll() {
    return this -> repository -> getAll();
}

int *Service::getNumarProduse() {
    return this -> repository -> getNumarProduse();
}

int Service::getDistinctElements() {
    return this ->repository -> getDistinctElements();
}

void Service::add(int cod, int pret, char *nume) {
    Produs produs(cod, pret, nume);
    this -> repository -> add(produs);
}

int Service::giveProduct(char *nume) {
    return this -> repository -> give(nume);
}

int Service::getPrice(char *nume) {
    int i = repository -> search(nume);
    return getAll()[i].getPrice();
}

void Service::check(char *nume) {
    repository -> check(nume);
}
