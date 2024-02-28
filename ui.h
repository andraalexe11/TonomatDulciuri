//
// Created by Alexe Andra on 08.05.2023.
//

#ifndef UNTITLED4_UI_H
#define UNTITLED4_UI_H
#include "service.h"
#include "tonomat.h"
class UI{
private:
    Service service;
    void add();
    void getAll();
    void giveProduct();
    void products();
    void plataProdus(char* nume);
    void rest(int value);
    Tonomat tonomat;
public:
    UI();
    UI(Service& service1, Tonomat& tonomat1);
    ~UI();
    void printMenu();
};
#endif //UNTITLED4_UI_H
