/**
@file puentes.cpp
@brief Programa principal para el problema de Puentes sobre lava.

@author Grupo Theta
@date 2014.08.16
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <stdint.h>

#include "solucion.h"


using namespace std;

int main() {
	string input, output;
	while (getline(cin, input)) {
		istringstream istr(input);
		uint16_t n, c;

		istr >> n >> c;

		vector<bool> tablones(n+1);
		for (uint16_t i = 0; i < n; ++i) {
			uint16_t estado;
			istr >> estado;
			tablones[i] = (bool)estado;
		}

		tablones[n] = true;
		vector<uint16_t> saltos;

		puentes(tablones, c, saltos);

		if (saltos.size() > 0) {
			cout << saltos.size() << " ";
			for (auto& it: saltos) {
				cout << it << " ";
			}
			cout << endl;
		}
		else
			cout << "no" << endl;
	}
	return 0;
}
