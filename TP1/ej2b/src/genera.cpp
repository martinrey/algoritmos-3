#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
	srand (time(NULL));
	int l = 50;
	int n = 1;
	ofstream myfile;
	char buffer [50];



	for(int k=0; k<l ; k++, ++n)
	{
	  sprintf (buffer, "entradas/entrada_%03d.txt", k);
		myfile.open (buffer);
		for(int j=0; j<20 ; j++)
		{
			myfile << n << endl;
			for(int i = 0; i < n; i++){
				int izq = 0;
				int der = 0;
				while (izq>=der)
				{
					izq = rand() % (n*10);
					der = rand() % (n*10);				
				}
				
			
			
			
				myfile << izq << " " << (rand() % 20)+1 << " " << der << endl;
			}
		}
		myfile << "0";
		myfile.close();
	}
	
	return 0;
}

