#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
	srand (time(NULL));
	int l = 50;
	int n = 2;
	int m = 100; 											// UMBRAL
	ofstream myfile;
	char buffer [50];



	for(int k=0; k<l ; k++, ++n)
	{
	  sprintf (buffer, "entradas/entrada_%03d.txt", k);
		myfile.open (buffer);
		for(int j=0; j<20 ; j++)
		{
			myfile << n << " " << m;
			for(int i = 0; i < n; i++)
			{
				myfile << endl;
				for (int j = i+1; j < n; j++)
				{
					if(i+2<n)
					{
						myfile << rand() % 20 << " ";
					}
					else
					{
						myfile << rand() % 20;
					}
				}
				
			}
		}
		myfile << "0";
		myfile.close();
	}
	
	return 0;
}

