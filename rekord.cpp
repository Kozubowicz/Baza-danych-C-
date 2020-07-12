#include "rekord.h"
baza* jeden = new rekord;
void createbase(){
	jeden->stworzbaze();
}
void addtablice(){
	jeden->dodajtablice();
}
void dis(){
	jeden->displey();
}
void rekordd(){
   jeden->dodajrekord();
}
void save(){
	jeden->saveToFile();
}
void read(){
	jeden->readFromFile();
}
