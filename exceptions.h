//
// Created by Alexe Andra on 22.05.2023.
//

#ifndef UNTITLED4_EXCEPTIONS_H
#define UNTITLED4_EXCEPTIONS_H
#include <exception>
class MyException{
private:
    char* message;
public:
    const char* what()throw();
    MyException(const char * msg);
    ~MyException();
};
#endif //UNTITLED4_EXCEPTIONS_H
