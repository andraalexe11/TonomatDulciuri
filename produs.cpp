//
// Created by Alexe Andra on 02.05.2023.
//
#include "produs.h"
#include "exceptions.h"
#include <cstring>
Produs::Produs() {
    this -> pret = 0;
    this -> cod = 0;
    this -> nume = new char [15]();
}

Produs::Produs(int cod, int pret, char *nume) {
    if(pret <= 0){
        throw MyException("Pretul trebuie sa fie un numar pozitiv nenul!");
    }
    this -> pret = pret;
    this -> cod = cod;
    this -> nume = new char [15];
    strcpy(this -> nume, nume);
}

Produs::Produs(Produs &p) {
    this -> pret = p.pret;
    this -> cod = p.cod;
    this -> nume = new char [15];
    strcpy(this -> nume, p.nume);
}

Produs &Produs::operator=(Produs &p) {
    this -> pret = p.pret;
    this -> cod = p.cod;
    delete[] this -> nume;
    this -> nume = new char [15];
    strcpy(this -> nume, p.nume);
    return *this;
}

bool Produs::operator==(Produs &p) {
    if(this -> cod == p.cod){
        return true;
    }
    return false;
}

Produs::~Produs() {

}

int Produs::getPrice() {
    return this -> pret;
}

int Produs::getCode() {
    return this -> cod;
}

char *Produs::getName() {
    return this -> nume;
}

void Produs::setName(char *nume) {
    delete[] this -> nume;
    this -> nume = new char [15];
    strcpy(this -> nume, nume);
}

void Produs::setPrice(int pret) {
    if(pret <= 0){
        throw MyException("Pretul trebuie sa fie un numar pozitiv nenul!");
    }
    this -> pret = pret;
}

void Produs::setCode(int cod) {
    this -> cod = cod;
}
