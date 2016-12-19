//GENERA ENTRADAS PARA EL PROBLEMA 4 Y LAS GUARDA EN EL ARCHIVO entrada.txt

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
	srand (time(NULL));
	int l = 50;
	int n = 10;
	ofstream myfile;
	char buffer [50];



	for(int k=0; k<l ; k++, ++n)
	{
	  sprintf (buffer, "entradas/entrada_%03d.txt", k);
		myfile.open (buffer);
		for(int j=0; j<20 ; j++)
		{
			myfile << n << " ";
			myfile << (rand()%6) +1 << " ";
			for(int i = 0; i < n; i++){
				myfile << rand() % 2 << " ";
			}
			myfile << endl;
		}
		myfile << "0";
		myfile.close();
	}
	
	return 0;
}

