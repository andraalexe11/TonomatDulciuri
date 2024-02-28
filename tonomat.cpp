//
// Created by Alexe Andra on 09.05.2023.
//
#include "tonomat.h"
#include "exceptions.h"
Tonomat::Tonomat() {
    this -> suma = 0;
    this ->bancnote = new int [10]();
    this ->aparitiiBancnote = new int[10]();
    this -> numar = 0;
}

Tonomat::Tonomat(int suma, int *bancnote, int *aparitiiBancnote, int numar) {
    if(suma < 0 ){
        throw MyException("Suma trebuie sa fie un numar pozitiv!");
    }
    this -> suma = suma;
    this -> bancnote = bancnote;
    this -> aparitiiBancnote = aparitiiBancnote;
    this -> numar = numar;
}

Tonomat::~Tonomat() {

}

int Tonomat::getSuma() {
    return this -> suma;
}

int *Tonomat::getBancnote() {
    return this -> bancnote;
}

int *Tonomat::getAparitii() {
    return this -> aparitiiBancnote;
}

int Tonomat::getAparitiiBancnota(int valoare) {
   if(search(valoare) != -1)
       return aparitiiBancnote[search(valoare)];
   return -1;
}

void Tonomat::addBancnota(int valoare) {
   if(search(valoare) != -1){
       aparitiiBancnote[search(valoare)] ++;
   } else{
       bancnote[this -> numar] = valoare;
       aparitiiBancnote[this -> numar] = 1;
       this -> numar ++;
   }
    this -> suma += valoare;
}

int Tonomat::getNumar() {
    return this -> numar;
}

int Tonomat::search(int valoare) {
    for(int i = 0; i < this -> numar; i++){
        if(this -> bancnote[i] == valoare)
            return i;
    }
    return -1;
}
