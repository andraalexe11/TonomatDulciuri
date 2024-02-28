    //
// Created by Alexe Andra on 02.05.2023.
//

#ifndef LAB_9_10_PRODUS_H
#define LAB_9_10_PRODUS_H
class Produs{
private:
    int cod;
    int pret;
    char* nume;
public:
    Produs();
    Produs(int cod, int pret, char* nume);
    Produs(Produs& p);
    Produs &operator=(Produs& p);
    bool operator==(Produs& p);
    ~Produs();
    int getPrice();
    int getCode();
    char* getName();
    void setName(char* nume);
    void setPrice(int pret);
    void setCode(int cod);
};



#endif //LAB_9_10_PRODUS_H
