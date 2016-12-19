/**
@file horizontes.cpp
@brief Programa principal para el problema de Horizontes Lejanos.

@author Grupo Theta
@date 2014.08.16
*/


#include <iostream>
#include <sstream>
#include "solucion.h"
using namespace std;

int main() {
	string input;
	while (getline(cin, input)) {
		istringstream istr(input);
		uint16_t n;
		istr >> n;

		vector<edificio_t> edificios(n);
		for (uint16_t i = 0; i < n; ++i) {
			getline(cin, input);
			istringstream istr2(input);
			uint16_t izq, alt, der;
			istr2 >> izq >> alt >> der;
			edificios[i] = edificio_t(izq, alt, der);
		}

		vector<uint16_t> valores;
		horizontes(edificios, valores);

		for(auto& v: valores) {
			cout << v << " ";
		}
		cout << endl;

	}
	return 0;
}
