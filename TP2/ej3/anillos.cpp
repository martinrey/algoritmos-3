/**
@file caballos.cpp
@brief Programa principal.

Este archivo contiene el main para el problema la caballos salvajes.


@author Grupo X
@date 2014.09.06
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <stdint.h>
#include "solucion.h"

using namespace std;

int main() {

	while (cin.peek() != 48) {
		LCdA ej3;
		cin >> ej3;
		
		if(ej3.M < ej3.N || ej3.buscar_AGM())
		{	
			cout << -1 << endl;
			return 0;
		}
/*
		for (int i = 1; i <= ej3.N; i++)
		{
			for (int j = 1; j <= ej3.N; j++)
			{
				cout << ej3.nodos[i].arista_en_AGM[j] << " ";
			}
			cout << endl;
		}
*/


		ej3.formar_anillo();


		cout << ej3;

		cin.get();
	}

    return 0;
}
