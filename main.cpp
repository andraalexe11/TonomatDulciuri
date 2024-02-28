#include <iostream>
using namespace std;
#include "ui.h"
#include "repositoryfile.h"
void alimentare(Tonomat &tonomat){
    for(int i = 0; i < 20; i++){
        tonomat.addBancnota(500);
        tonomat.addBancnota(200);
        tonomat.addBancnota(100);
        tonomat.addBancnota(50);
        tonomat.addBancnota(20);
        tonomat.addBancnota(10);
        tonomat.addBancnota(5);
        tonomat.addBancnota(1);
    }
}
int main() {
    RepositoryFile* repositoryfile = new RepositoryFile("C:\\Users\\Alexe Andra\\CLionProjects\\Lab 9-10\\produse.txt");
    Tonomat tonomat;
//    Service service(reinterpret_cast<Repository *&>(repositoryfile));
    Service service(repositoryfile);
    alimentare(tonomat);
    UI ui(service, tonomat);
    ui.printMenu();
}
