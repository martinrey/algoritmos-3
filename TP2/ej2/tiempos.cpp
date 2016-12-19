/**
@file tiempos.cpp
@brief Utilidad para medir los tiempos del algoritmo de <>

@author Grupo P
@date 2014.04.12
*/

// std
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include "solucion.h"

// user
using namespace std;


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
		Tablero ej2;
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
		cout << ej2.size_n() << " " << ej2.size_k() << " " << duration_cast<microseconds>(acum_time).count() / cant << endl;



		cin.get();
	}
	return 0;
}
