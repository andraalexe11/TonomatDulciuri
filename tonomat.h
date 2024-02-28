//
// Created by Alexe Andra on 09.05.2023.
//

#ifndef UNTITLED4_TONOMAT_H
#define UNTITLED4_TONOMAT_H
class Tonomat{
private:
    int suma;
    int* bancnote;
    int* aparitiiBancnote;
    int numar;
public:
    Tonomat();
    Tonomat(int suma, int* bancnote, int* aparitiiBancnote, int numar);
    ~Tonomat();
    int getSuma();
    int* getBancnote();
    int* getAparitii();
    int getAparitiiBancnota(int valoare);
    void addBancnota(int valoare);
    int getNumar();
    int search(int valoare);

};
#endif //UNTITLED4_TONOMAT_H
