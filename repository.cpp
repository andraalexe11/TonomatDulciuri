//
// Created by Alexe Andra on 07.05.2023.
//
#include "repository.h"
#include <cstring>
#include "exceptions.h"
Repository::Repository() {
    this -> size = 10;
    this -> distinctelements = 0;
    this -> produse = new Produs[size]();
    this -> numarProduse = new int[size]();
}

Repository::Repository(Produs *produse, int *numarProduse, int size, int distinctElements) {
    this -> size = size;
    this -> distinctelements =  distinctElements;
    delete[] this -> produse;
    delete[] this -> numarProduse;
    this -> produse = new Produs[size];
    this -> numarProduse = new int [size];
    this -> produse = produse;
    this -> numarProduse = numarProduse;
}

Repository::~Repository() {

}

int Repository::getDistinctElements(){
    return this -> distinctelements;
}

int *Repository::getNumarProduse() {
    return this -> numarProduse;
}

Produs *Repository::getAll() {
    return this -> produse;
}

void Repository::add(Produs produs) {
    if(this -> distinctelements == this -> size){
        resize();
    }
    if(search(produs.getName()) != -1){
        this -> numarProduse[search(produs.getName())] ++;
    }else{
        this -> produse[distinctelements] = produs;
        this -> numarProduse[distinctelements] = 1;
        distinctelements ++;
    }

}

int Repository::give(char* nume) {
    if(search(nume) == -1) {
        return 0;
    }
    this -> numarProduse[search(nume)] --;

    return 1;
}

void Repository::remove(int i) {
    char* sir = new char [10];
    sir = this -> produse[i].getName();
    for(int j = i; j < this -> distinctelements; j++){
        this -> produse[j] = this -> produse[j + 1];
    }
    this -> distinctelements --;
}

void Repository::resize() {
    this -> size *= 2;
    Produs* newArray = new Produs[this -> size];
    for(int i = 0; i <= this -> distinctelements; i++) {
        newArray[i] = this->produse[i];
    }
    delete[] this -> produse;
    this -> produse = newArray;
}

int Repository::search(char* nume) {
    for(int i = 0; i <= this -> distinctelements; i++)
        if(strcmp(nume, this -> produse[i].getName()) == 0){
            return i;
        }
    return -1;

}

void Repository::check(char* nume) {
    if(this -> numarProduse[search(nume)] == 0){
        remove(search(nume));
    }
}

void Repository::setFrequence(int i, int nr) {
    if(i > this -> distinctelements){
        throw MyException("Pozitia este invalida!");
    }
    if(nr < 0){
        throw MyException("Numarul de aparitii trebuie sa fie un numar pozitiv!");
    }
    this -> numarProduse[i] = nr;
}
