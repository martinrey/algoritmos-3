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
#include <chrono>
#include "solucion.h"

using namespace std;

int main() {
	while (cin.peek() != 48) {
		Horizonte ej2;
		cin >> ej2;
		using namespace chrono;
		high_resolution_clock::time_point start, end;
		microseconds acum_time(0);

		size_t cant = 50;
		for (size_t i=0; i<cant; ++i){
			start = high_resolution_clock::now();

			ej2.resolver();
			ej2.clear();

			end = high_resolution_clock::now();
			acum_time += duration_cast<microseconds >(end - start);
		}
		cout << ej2.size() << " " << duration_cast<microseconds>(acum_time).count() / cant;



		cin.get();
	}
	return 0;
}
