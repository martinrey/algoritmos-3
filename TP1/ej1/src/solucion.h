/**
@file solucion.h
@brief Solución para el problema de Puentes sobre lava caliente.

@author Grupo Theta
@date 2014.08.16
*/


#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <stdint.h>

void puentes(const std::vector<bool>& tablones, uint16_t c, std::vector<uint16_t>& saltos) {
	uint16_t j = 0, k = 0, n = tablones.size();

    // caso que puedo saltar todo de una
    if (c < n){
		// no puedo saltar todo de una
		while (j < n){
			for(k = c; k > 0; k--){
				if ((j+k-1 < n) && (tablones[j+k-1] != false)){
					saltos.push_back(j+k);
					break;
				}
			}
	        if (k == 0){ // "No hay solucion";
	        	saltos.clear();
	            break;
	        }

			j += k;
		}
    }
    else {
    	saltos.push_back(n);
    }
}


#endif /* SOLUCION_H_ */
