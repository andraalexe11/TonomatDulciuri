//
// Created by Alexe Andra on 08.05.2023.
//
#include "ui.h"
#include <iostream>
#include "tonomat.h"
#include "exceptions.h"
using namespace std;
void UI::add() {
    int cod, pret;
    char* nume = new char [15]();
    cout << "Dati codul: "; cin >> cod;
    cin.ignore();
    cout << "Dati numele: "; cin.getline(nume, 15);
    cout << "Dati pretul: "; cin >> pret;
    try {
        this->service.add(cod, pret, nume);
    }
    catch (MyException &exception) {
        cout << exception.what() << endl;
    }
    delete[] nume;
}

void UI::getAll() {
    for(int i = 0; i < this -> service.getDistinctElements(); i++){
        cout << i + 1 << ". ";
        cout << "Cod: " <<this -> service.getAll()[i].getCode() <<", Nume: " << this -> service.getAll()[i].getName() << ", Pret: " << service.getAll()[i].getPrice() << " lei";
        cout << endl;
    }
}

void UI::plataProdus(char* nume){
    cout << "Pretul produsului este de " << service.getPrice(nume) << endl;
    cout << "Introduceti suma pe care doriti sa o platiti: ";
    int plata;
    cin >> plata;
    while (plata < service.getPrice(nume)){
        cout << "Suma insuficienta. Incercati din nou!";
        cout << endl << "Introduceti suma pe care doriti sa o platiti: ";
        cin >> plata;
    }
    if(plata > service.getPrice(nume)){
        if( tonomat.getSuma() < plata - service.getPrice(nume)) {
            cout << "Tonomatul nu dispune de suma necesara pentru rest. Introduceti o suma mai mica!" << endl;
        } else{
            int i = 0;
            int rest = plata - service.getPrice(nume);
            while(i < tonomat.getNumar()&& rest != 0 ){
                if(tonomat.getBancnote()[i] <= rest && tonomat.getAparitii()[i] > 0){
                    rest -= tonomat.getBancnote()[i];
                }else{
                    i ++;
                }
            }
            if(rest == 0) {
                cin.ignore();
                cout << "Ridicati restul de " << plata - service.getPrice(nume) << " lei" << endl;
                int rest1 = plata - service.getPrice(nume);
                this ->rest(rest1);
            }

        }
    }else{
        cout <<"Ati introdus suma exacta! Selectia a fost realizata cu succes!" << endl;
    }
}
void UI::giveProduct() {
    char* nume = new char [15];
    cout << "Introduceti numele produsului dorit: ";
    cin.ignore();
    cin.getline(nume, 15);
    if(this -> service.giveProduct(nume) == 1){
        plataProdus(nume);
    }else{
        cout << endl << "Produsul nu este in stoc sau nu este corect introdus!" << endl;
    }
    service.check(nume);
    delete[] nume;
}

UI::UI() {
    Service service1;
    this -> service = service1;
    Tonomat tonomat1;
    this -> tonomat = tonomat1;
}

UI::UI(Service &service1, Tonomat& tonomat1) {
    this -> service = service1;
    this -> tonomat = tonomat1;
}

UI::~UI() {

}
void UI::products(){
    for(int i = 0; i < this -> service.getDistinctElements(); i++){
        cout << i + 1 << ". ";
        cout << "Cod: " <<this -> service.getAll()[i].getCode() <<", Nume: " << this -> service.getAll()[i].getName() << ", Pret: " << service.getAll()[i].getPrice() << " lei";
        cout << endl;
    }

}
void UI::printMenu() {
    bool value = true;
    while (value) {
        cout << "Alegeti o optiune: " << endl;
        cout << "1. Adaugare Produs" << endl;
        cout << "2. Selectare Produs" << endl;
        cout << "3. Afisare produse" << endl;
        cout << "0. Exit" << endl;
        int command;
        cout << "Dati comanda: ";
        cin >> command;
        switch (command) {
            case 1:
                this -> add();
                break;
            case 2:
                if(this -> service.getDistinctElements() == 0){
                    cout << "Momentan nu sunt produse disponibile" << endl;
                }else{
                    cout << "Produse disponibile: " << endl;
                    this->products();
                    this->giveProduct();
                }
                break;
            case 3:
                this -> getAll();
                break;
            default:
                cout << "La revedere!";
                value = false;
                break;
        }
    }

}

void UI::rest(int value) {
    int i = 0;
    while(i < tonomat.getNumar() && value > 0){
        if(tonomat.getBancnote()[i] <= value && tonomat.getAparitii()[i] > 0){
            value -= tonomat.getBancnote()[i];
            tonomat.getAparitii()[i] --;
        }
        i++;
    }
}
