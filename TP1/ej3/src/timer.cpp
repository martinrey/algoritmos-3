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
#include <chrono>
#include <stdint.h>
#include "solucion.h"


using namespace std;


int main() {
	while (cin.peek() != 48) {
		Biohazard ej3;
		cin >> ej3;

		using namespace chrono;
		high_resolution_clock::time_point start, end;
		microseconds acum_time(0);


		size_t cant = 10;
		for (size_t i=0; i<cant; ++i){
			start = high_resolution_clock::now();

			ej3.backtracking();
			ej3.clear();

			end = high_resolution_clock::now();
			acum_time += duration_cast<microseconds >(end - start);
		}
		cout << ej3.size() << " " << duration_cast<microseconds>(acum_time).count() / cant << endl;

		cin.get();
	}
	return 0;
}

