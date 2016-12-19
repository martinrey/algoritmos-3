/**
@file solucion.h
@brief Solución para el problema Horizontes.

@author Grupo Theta
@date 2014.08.16
*/


#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

typedef struct edificio_st {
	uint16_t izq;
	uint16_t alt;
	uint16_t der;
	edificio_st() : izq(0), alt(0), der(0) {}
	edificio_st(uint16_t i, uint16_t a, uint16_t d) : izq(i), alt(a), der(d) {}

} edificio_t;

bool orden(const edificio_t& a, const edificio_t& b) {
	return ((a.izq < b.izq) ||
			(a.izq == b.izq && b.alt < a.alt ) ||
			(a.izq == b.izq && b.alt == a.alt && b.der < a.der ));

}


void horizontes(std::vector<edificio_t>& edificios, std::vector<uint16_t>& valores) {

	sort(edificios.begin(), edificios.end(), orden);

	auto edi = edificios.begin();

	if (edi != edificios.end()) {
		uint16_t izq = edi->izq;
		uint16_t alt = edi->alt;
		uint16_t der = edi->der;

		valores.push_back(izq);
		valores.push_back(alt);

		edi++;
		while (edi != edificios.end()) {
			if (izq < edi->izq) { // el nuevo edificio empieza despues del anterior.
				if (der < edi->izq) { // el edificio esta separado del anterior
					valores.push_back(der);
					valores.push_back(0);

					izq = edi->izq;
					alt = edi->alt;

					valores.push_back(izq);
					valores.push_back(alt);
					der = edi->der;
				}
				else {
					if (der < edi->der) { // parte del nuevo edificio está contenido en el anterior

						// el mas alto gana.
						if (alt < edi->alt)
							izq = edi->izq;
						else
							izq = der;

						alt = edi->alt;

						valores.push_back(izq);
						valores.push_back(alt);
						der = edi->der;
					}
					else { // esta totalmente contenido
						if (alt < edi->alt) {
							izq = edi->izq;
							alt = edi->alt;
							der = edi->der;
							valores.push_back(izq);
							valores.push_back(alt);
						}
					}
				}
			}
			else { // arranca en el mismo x.
				if (der < edi->der) { // El edificio nuevo es a lo sumo de la misma altura.
					valores.push_back(der);
					der = edi->der;
					alt = edi->alt;
					valores.push_back(alt);

				}
				else { // esta contenido
					// No hago nada.
				}
			}
			edi++;
		}

		valores.push_back(der);
		valores.push_back(0);

	}


}


#endif /* SOLUCION_H_ */
