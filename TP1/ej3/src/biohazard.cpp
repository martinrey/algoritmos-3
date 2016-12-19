/**
@file biohazard.cpp
@brief Programa principal para el problema Biohazard.

@author Grupo Theta
@date 2014.08.18
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
		Biohazard ej3;

		cin >> ej3;
		ej3.backtracking();
		cout << ej3;

		cin.get();
	}
	return 0;
}


