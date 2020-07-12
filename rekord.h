#ifndef REKORD_H
#define REKORD_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include "baza.h"
using namespace std;
class rekord : public  baza
{
	public:
		int *lr=new int[lt];
		char ****rec=new char ***[lt];
		int ***Irec=new int **[lt];
		virtual void stworzbaze();
		virtual void dodajtablice();
		virtual void displey();
		virtual void dodajrekord();
		virtual void saveToFile();
		virtual void readFromFile();
};
void rekord::readFromFile(){
	string linia;
	int nr_linii=1;
	std::fstream plik;
   	plik.open( "tekst.txt", std::ios::in );
    	while (getline(plik, linia)){
        	std::cout<<linia<<endl;
        	nr_linii++;
    	}
}
void rekord::stworzbaze(){
	std::cout<<"Podaj nazwe bazy: ";
	std::cin>>bname;
	lb=strlen(bname);
}
void rekord::dodajtablice(){
   	std::cout<<"Podaj nazwe tabeli: ";
   	int i;
   	char tmp[255];
   	std::cin>>tmp;
   	tname[lt]=new char[255];
   	while(tmp[i]){
		tname[lt][i]=tmp[i];
		i++;
   	}
	std::cout<<"Podaj liczbe kolumn: ";
	std::cin>>k[lt];
	int q=0;
	kolumna[lt]=new char*[q];
	type[lt]=new int[q];
	while(q<k[lt]){
		i=0;
		std::cout<<"Podaj nazwe kolumny nr "<<q<<" : ";
		char tmp2[48];
   	std::cin>>tmp2;
   	int pf=strlen(tmp2);
 	kolumna[lt][q]=new char[pf];
   	while(tmp2[i]){
			kolumna[lt][q][i]=tmp2[i];
			i++;
  		}
  		std::cout<<"Podaj typ kolumny(0-int, 1-char): ";
  		std::cin>>type[lt][q];
      	Irec[lt]=new int*[q];
      	rec[lt]=new char**[q];
		q++;
	}
	lt++;
	std::cout<<endl;
}
void rekord::dodajrekord(){
	std::cout<<"Podaj numer tabeli: ";
	int r;
	std::cin>>r;
	int q=0;
	int i;
 	Irec[r][lr[r]]=new int[q];
 	rec[r][lr[r]]=new char*[q];
	while(q<k[r]){
		i=0;
		std::cout<<"Wprowadz dane do kolumny NR. "<<q;
 		if(type[r][q]==0){
         		std::cout<<" (int) : ";
  			std::cin>>Irec[r][lr[r]][q];
		}
		else if(type[r][q]==1){
        		std::cout<<" (char) : ";
      			rec[r][lr[r]][q]=new char[48];
			char tmp3[48];
 	  		std::cin>>tmp3;
 	  		while(tmp3[i]){
				rec[r][lr[r]][q][i]=tmp3[i];
				i++;
  			}
 		}
		q++;
	}
	lr[r]++;
	std::cout<<endl;
}
void rekord::displey(){
   	std::cout<<"Baza: "<<bname<<endl<<endl;
	int j=0;
	int i;
	for(i=0; i<lt; i++){
      		std::cout<<"Tabela Nr. "<<i<<" : ";
     		while(tname[i][j]){
         		std::cout<< tname[i][j];
         		j++;
    		}
     		std::cout<<endl;
		int q=0;
		std::cout<<"Kolumny: ";
    		while(q<k[i]){
			int l=0;
    			while(kolumna[i][q][l]){
    				std::cout<< kolumna[i][q][l];
    				l++;
         		}
         		std::cout<<".  ";
         		q++;
      		}
      		std::cout<<endl;
		j=0;
		int s=0;
		while(s<lr[i]){
			std::cout<<"  "<<s<<"      ";
			q=0;
			while(q<k[i]){
				int l=0;
   				if(type[i][q]==0){
               				std::cout<<Irec[i][s][q];
            			}
				else if(type[i][q]==1){
               				while(rec[i][s][q][l]){
                  				std::cout<<rec[i][s][q][l];
                  				l++;
                			}
            			}
    				std::cout<<"  |  ";
    				q++;
         		}
         		std::cout<<endl;
         		s++;
      		}
   	}
	std::cout<<endl;
}
void rekord::saveToFile(){
	std::fstream plik;
   	plik.open( "tekst.txt", std::ios::out | std::ios::app);
	plik<<"Baza: "<<bname<<endl<<endl;
	int j=0;
	int i=0;
	for(i=0; i<lt; i++){
      		plik<<"Tabela Nr. "<<i<<" : ";
      		while(tname[i][j]){
         		plik<< tname[i][j];
         		j++;
    		}
     		plik<<endl;
		int q=0;
		plik<<"Kolumny: ";
    		while(q<k[i]){
			int l=0;
    			while(kolumna[i][q][l]){
    				plik<< kolumna[i][q][l];
    				l++;
         		}
         		plik<<".  ";
         		q++;
      		}
      		plik<<endl;
		j=0;
		int s=0;
		while(s<lr[i]){
			plik<<"  "<<s<<"      ";
			q=0;
			while(q<k[i]){
				int l=0;
   				if(type[i][q]==0){
                			plik<<Irec[i][s][q];
            			}
            			else if(type[i][q]==1){
                			while(rec[i][s][q][l]){
                    				plik<<rec[i][s][q][l];
                    				l++;
                			}
            			}
    				plik<<"  |  ";
    				q++;
         		}
         	plik<<endl;
         	s++;
      		}
	}
	plik<<endl;
	std::cout<<endl;
	std::cout<<"Zapis do pliku tekst.txt "<<endl;
}
#endif
