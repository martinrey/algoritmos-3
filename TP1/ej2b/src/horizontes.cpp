/**
@file horizontes.cpp
@brief Programa principal para el problema de Horizontes Lejanos.

@author Grupo Theta
@date 2014.08.16
*/


#include <iostream> 
#include <algorithm>
#include <vector>  
#include <limits>
#include <stdint.h>
#include "solucion.h"

using namespace std;


int main() {
	while (cin.peek() != 48) {
		Horizonte ej2;

		cin >> ej2;
		ej2.resolver();
		cout << ej2;

		cin.get();
	}
	return 0;
}

