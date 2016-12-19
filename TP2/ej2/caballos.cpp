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
		Tablero ej2;

		cin >> ej2;
		ej2.resolver();
		cout << ej2;

		cin.get();
	}

    return 0;
}
