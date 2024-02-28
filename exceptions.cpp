//
// Created by Alexe Andra on 22.05.2023.
//
#include "exceptions.h"
#include <cstring>

using namespace std;
const char *MyException::what() throw() {
    return this -> message;
}

MyException::MyException(const char *msg) {
    if(msg != nullptr){
        this -> message = new char [strlen(msg) + 1];
        strcpy(this -> message, msg);
    }
}

MyException::~MyException() {
    if(this -> message!= nullptr){
        delete[] this -> message;
    }
}

