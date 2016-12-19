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

using namespace std;

typedef struct edificio_st {
	size_t izq;
	size_t alt;
	size_t der;
	edificio_st() : izq(0), alt(0), der(0) {}
	edificio_st(size_t i, size_t a, size_t d) : izq(i), alt(a), der(d) {}

} edificio_t;

// Comparacion para el heap.
struct Comp {
	bool operator()(const edificio_t& s1, const edificio_t& s2) {
		return s1.alt <= s2.alt;
	}
};

bool orden(const edificio_t& a, const edificio_t& b) { // de menor a mayor con los valores de la izq
	return ((a.izq < b.izq) ||
			(a.izq == b.izq && a.alt > b.alt) ||
			(a.izq == b.izq && a.alt == b.alt && a.der < b.der));
}

bool orden2(const edificio_t& a, const edificio_t& b) { // de mayor a menor con los valores de la der
	return ((a.der > b.der) ||
			(a.der == b.der && a.alt > b.alt) ||
			(a.der == b.der && a.alt == b.alt && a.izq > b.izq));
}

class Horizonte {
public:
	Horizonte() : n(0) {

	}

	void resolver() {
		flancosAscendentes(piso);

		flancosDescendentes(piso);

		sort(solucion.begin(), solucion.end());
		solucion.erase(unique(solucion.begin(), solucion.end()), solucion.end());     // Para borrar los repetidos
	}

	void clear() {
		solucion.clear();
	}

	size_t size() const {
		return n;
	}

	friend ostream & operator<<(ostream &os, Horizonte& h);

	friend istream & operator>>(istream &is, Horizonte& h);

protected:
	size_t n;
	vector<edificio_t> edificios;
	vector<pair<size_t, size_t> > solucion;
	edificio_t piso;                   //Hay qe pasarlo a punteros a edificios_t

	void flancosAscendentes(const edificio_t& piso) {
		vector<edificio_t> heap;

		make_heap(heap.begin(), heap.end(), Comp()); // O(3*k) con k = heap.size(). Notar que al comienzo heap está vacío.
		heap.push_back(piso);						 // Ojo con los push_back en vector, puede ser traicionero.
		push_heap(heap.begin(), heap.end(), Comp()); // O(log k)

		sort(edificios.begin(), edificios.end(), orden); // O( n*log(n) ), n = edificios.size()

		for (size_t i = 0; i < n; i++) {  // O( n *
			edificio_t edi = heap.front();
			while (edificios[i].izq >= edi.der) {
				pop_heap(heap.begin(), heap.end(), Comp()); // O(2*log(n))
				heap.pop_back();							// O( c )
				edi = heap.front();							// O( c )
			}

			if (edi.alt < edificios[i].alt)
				solucion.push_back(make_pair(edificios[i].izq, edificios[i].alt));

			heap.push_back(edificios[i]);
			push_heap(heap.begin(), heap.end(), Comp());
		}
	}

	void flancosDescendentes(const edificio_t& piso) {
		vector<edificio_t> heap;

		make_heap(heap.begin(), heap.end(), Comp()); // O(3*k)
		heap.push_back(piso);
		push_heap(heap.begin(), heap.end(), Comp()); // O(log k)

		sort(edificios.begin(), edificios.end(), orden2); // O( n*log(n) )

		for (size_t i = 0; i < n; i++) {
			edificio_t edi = heap.front();
			while (edificios[i].der < edi.izq) {
				pop_heap(heap.begin(), heap.end(), Comp());
				heap.pop_back();
				edi = heap.front();
			}

			if (edi.alt < edificios[i].alt)
				solucion.push_back(make_pair(edificios[i].der, edi.alt));

			heap.push_back(edificios[i]);
			push_heap(heap.begin(), heap.end(), Comp());
		}
	}

};

ostream & operator<<(ostream &os, Horizonte& h) {
	for (size_t i = 0; i < h.solucion.size(); i++) {
		os << h.solucion[i].first << " " << h.solucion[i].second << " ";
	}
	os << endl;

    return os;
}

istream & operator>>(istream &is, Horizonte& h) {
	is >> h.n;
	size_t k = 0;

	for (size_t i = 0; i < h.n; i++) {
		size_t izq, alt, der;
		is >> izq >> alt >> der;
		k = std::max(k, der);
		h.edificios.push_back(edificio_t(izq, alt, der));
	}

	h.piso = edificio_t(0, 0, k);

	return is;
}



#endif /* SOLUCION_H_ */
