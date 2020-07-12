#ifndef BAZA_H
#define BAZA_H
class baza
{
	public:
		int lb;
		int lt;
		char *bname= new char[lb];

		char **tname=new char *[lt];
		int *k=new int[lt];
		int **type=new int*[lt];
		char ***kolumna=new char **[lt];
		virtual void stworzbaze(){
		}
		virtual void dodajtablice(){
		}
		virtual void displey(){
		}
		virtual void dodajrekord(){
		}
		virtual void saveToFile(){
		}
		virtual void readFromFile(){
		}
};
#endif
