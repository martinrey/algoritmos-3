/**
@file vuelos.cpp
@brief Programa principal.

Este archivo contiene el main para el problema plan de vuelo.


@author Grupo Theta
@date 2014.09.15
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
		PlanVuelo ej1;

		cin >> ej1;
		ej1.resolver();
		cout << ej1 << endl;

		cin.get();
	}

    return 0;
}
