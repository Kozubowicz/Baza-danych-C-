#include<iostream>
using namespace std;
void rekordd();
void dis();
void createbase();
void addtablice();
void save();
void read();
int main(){
	string i;
	int o;
	std::cout<<"Czy chcesz teraz nadac nazwe bazie (y/n): ";
	std::cin>>i;
	if(i=="y"){
		createbase();
	}
	do{
		std::cout<<"Wybierz akcje: \n ";
		std::cout<<"6 Wyjscie z programu \n ";
		std::cout<<"0 Zmiana nazwy Bazy \n ";
		std::cout<<"1 Dodaj tabele do bazy \n ";
		std::cout<<"2 Dodaj rekord \n ";
		std::cout<<"3 Wyswietlenie \n ";
		std::cout<<"4 Zapis \n ";
		std::cout<<"5 Podglad danych z pliku \n";
		std::cin>> o;
		switch(o){
         		case 0:
				createbase();
				break;
       			case 1:
           			addtablice();
            			break;
       			case 2:
				rekordd();
				break;
        		case 3:
           			dis();
          			break;
        		case 4:
           			save();
           			break;
        		case 5:
        			read();
        			break;
      		}
	}while( o != 6 );
    	return 0;
}
