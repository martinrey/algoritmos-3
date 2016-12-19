/**
@file solucion.h
@brief Solución para el problema Biohazard.

@author Grupo Theta
@date 2014.08.18
*/

#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <iostream>
#include <limits>
#include <stdint.h>

using namespace std;

typedef struct sustancia_st {
	uint16_t numero;
	vector<uint16_t> coeficiente;

	sustancia_st(uint16_t i, uint16_t n) : numero(i)  {
		coeficiente.resize(n);
	}

} sustancia_t;


class Camion {
public:
	vector<sustancia_t*> sustanciasTransportadas; // Sustancias transportadas por el camion
	uint16_t peligrosidad; // Nivel de peligrosidad de las sustancias transportadas

	/// Constructor
	Camion() : peligrosidad(0) {
	}

	/// Agrega sust al camion y le sube la peligrosidad
	void agregarSustancia(sustancia_t * sust) {
		peligrosidad += calcularPeligrosidad(sust);
		sustanciasTransportadas.push_back(sust);
	}

	/// Saca "sust" del camion y baja la peligrosidad. Siempre es la ultima sustancia agregada por el contexto en que la uso.
	void sacarSustancia(sustancia_t * sust)  {
		sustanciasTransportadas.pop_back();
		peligrosidad -= calcularPeligrosidad(sust);
	}

	/// Chequea si al agregar "sust" al camion no se pasa el umbral de peligrosidad
	bool noEsPeligroso(const uint16_t &umbral, const sustancia_t * sust) {
		uint16_t x = calcularPeligrosidad(sust) + peligrosidad;
		return (x <= umbral);
	}

private:

	/// Calcula la peligrosidad de agregar "sust" al camion (no la agrega, solo la calcula)
	uint16_t calcularPeligrosidad(const sustancia_t * sust) {
		uint16_t suma = 0;
		for (auto& st: sustanciasTransportadas)
			suma += sust->coeficiente[st->numero];
		return suma;
	}
};

class Biohazard {
public:
	Biohazard() :
		n(0), m(0),
		minimosCamionesUsados(numeric_limits<uint16_t>::max()),
		usadas(0) {
	}

	void backtracking() {
		camiones.resize(n);
		recursion(0);
		return;
	}

	void clear() {
		camiones.clear();
		solucion.clear();
		transportados.clear();
		usadas = 0;
	}

	uint16_t size() const {
		return n;
	}

	friend ostream & operator<<(ostream &os, Biohazard& b);

	friend istream & operator>>(istream &is, Biohazard& b);

protected:
	uint16_t n;
	uint16_t m;
	uint16_t minimosCamionesUsados;

	vector<sustancia_t> productos;
	vector<Camion> camiones;
	vector<uint16_t> transportados;
	uint16_t usadas;		/// Cantidad de sustancias utilizadas
	vector<uint16_t> solucion;

	void recursion(const uint16_t &x) {
		uint16_t contador = contar();

		if (contador < minimosCamionesUsados) {

			if (todosUsados()) {
				minimosCamionesUsados = contador;
				solucion = transportados;
			}

			for (uint16_t i = x; i < n; i++) { 			// i itera las sustancias
				if (transportados[i] == 0)   { 			// Si no esta en ningun camion...
					sustancia_t * sust = &productos[i];
					for (uint16_t c = 0; c < n; c++) {          // c itera los camiones
						Camion * truck = &camiones[c];
						if (truck->noEsPeligroso(m, sust)) { 	// Si no supera el umbral de peligrosidad al agregar la sustancia sust al truck...
							truck->agregarSustancia(sust);      // Agrego sust al camion
							usar(sust->numero, c + 1); 			// Agendo sust como ya transportada
							recursion(i); 						// Y llamo a la recursion																																			PODAAA->> this->recursion(i);
							desUsar(sust->numero); 		// Vuelvo a dejar como si no lo lo hubiese agregado, para probar con la siguiente sustancia
							truck->sacarSustancia(sust);
						}
					}
				}
			}
		}

	}

	/// Agenda "sust" como ya transportada por el camion "c"
	void usar(uint16_t sust, uint16_t c) {
		transportados[sust] = c;
		++usadas;
	}

	/// Agenda "sust" como no transportada por ningun camion
	void desUsar(uint16_t sust) {
		transportados[sust] = 0;
		--usadas;
	}

	/// Devuelve true <==> estan todas las sustancias en algun camion
	inline bool todosUsados() {
		return (usadas == n);
	}

	/// Para saber cuantos camiones se usaron y tambien sirve para un par de "podas"
	uint16_t contar() {
		uint16_t res = 0;
		for (uint16_t i = 0; i < n; i++)
			res = max(res, transportados[i]);
		return res;
	}
};


ostream & operator<<(ostream &os, Biohazard& b) {
	os << b.minimosCamionesUsados << " "; // Esta es la salida que nos piden
	for (uint16_t i = 0; i < b.n; i++)
		os << b.solucion[i] << " ";
	os << endl;

    return os;
}

istream & operator>>(istream &is, Biohazard& b) {
	is >> b.n >> b.m;

	for (uint16_t i = 0; i < b.n; i++) {
		sustancia_t x = sustancia_t(i, b.n);
		b.productos.push_back(x);
	}

	for (uint16_t i = 0; i < b.n; i++) {
		b.productos[i].coeficiente[i] = numeric_limits<uint16_t>::max();// No hace falta creo
		for (uint16_t j = i + 1; j < b.n; j++) {
			is >> b.productos[i].coeficiente[j];
			b.productos[j].coeficiente[i] = b.productos[i].coeficiente[j];
		}
	}

	b.transportados.resize(b.n);

	return is;
}

#endif /* SOLUCION_H_ */

