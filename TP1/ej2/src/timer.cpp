/**
@file timer.cpp
@brief Programa para calcular la performance del programa puentes.

@author Grupo Theta
@date 2014.08.16
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <stdint.h>
#include <chrono>
#include <ctime>

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

		using namespace chrono;
		high_resolution_clock::time_point start, end;
		duration<double> acum_time(0);

		size_t cant = 50;
		for (size_t i=0; i<cant; ++i){
			start = high_resolution_clock::now();

			vector<uint16_t> valores;
			horizontes(edificios, valores);

			end = high_resolution_clock::now();
			acum_time += duration_cast<duration<double>>(end - start);
		}
		cout << n << " " << acum_time.count()/cant;

	}
	return 0;
}
