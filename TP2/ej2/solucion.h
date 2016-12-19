
#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <cmath>
#include <limits>       // std::numeric_limits

using namespace std;


class Tablero {
	/// Casillas
	int n_;
	/// Cantidad de caballos
	int k_;
	/// Casilla (f, c) elegida como destino final
	int f_;
	int c_;
	/// Cantidad de movimientos totales necesarios para llevar a todos los caballos a la casilla (f, c)
	int m_;


	typedef pair<int, int> coord_t;
	typedef vector<vector<int> > matriz_t;
	vector<coord_t> caballos_;

	inline bool esValido(const coord_t& c, int fila, int col) const {
		return ((c.first+fila <= n_) && (c.first+fila > 0) && (c.second+col <= n_) && (c.second+col > 0));
	}

	inline coord_t sumar(const coord_t& c1, const coord_t& c2) const {
		return coord_t(c1.first + c2.first,  c1.second + c2.second);
	}

	void dameAdyacentes(const coord_t& c, list<coord_t>& adyacentes) const {

		// movimiento de caballo arriba derecha
		if (esValido(c, 1, 2))
			adyacentes.push_back(sumar(c, coord_t(1, 2)));

		// movimiento caballo arriba izquierda
		if (esValido(c, -1, 2))
			adyacentes.push_back(sumar(c, coord_t(-1, 2)));

		// movimiento de caballo derecha abajo
		if (esValido(c, 2, -1))
			adyacentes.push_back(sumar(c, coord_t(2, -1)));

		// movimiento caballo derecha arriba
		if (esValido(c, 2, 1))
			adyacentes.push_back(sumar(c, coord_t(2, 1)));

		// movimiento caballo abajo derecha
		if (esValido(c, 1, -2))
			adyacentes.push_back(sumar(c, coord_t(1, -2)));

		// movimiento caballo abajo izquierda
		if (esValido(c, -1, -2))
			adyacentes.push_back(sumar(c, coord_t(-1, -2)));

		// movimiento caballo izquierda arriba
		if (esValido(c, -2, 1))
			adyacentes.push_back(sumar(c, coord_t(-2, 1)));

		// movimiento caballo izquierda abajo
		if (esValido(c, -2, -1))
			adyacentes.push_back(sumar(c, coord_t(-2, -1)));

	}

	void bfs(coord_t origen, matriz_t &m){
		queue<coord_t> cola;

		vector<bool> aux(n_, false);
		vector<vector<bool > > visitados(n_, aux);
		cola.push(origen);
		visitados[origen.first-1][origen.second-1]  = true;
		
		while(!cola.empty()){
			coord_t cab = cola.front(); cola.pop();

			list<coord_t> adyacentes;
			dameAdyacentes(cab, adyacentes);

			for(auto &v: adyacentes){
				if (visitados[v.first-1][v.second-1] == false){
					visitados[v.first-1][v.second-1] = true;
					m[v.first-1][v.second-1] = m[cab.first-1][cab.second-1] + 1;

					cola.push(v);
				}
			}
		}
	}


public:
	Tablero(): n_(0), k_(0), f_(0), c_(0), m_(numeric_limits<int>::max()) {}

	void resolver(){
		// Para acumular la cantidad de movimientos
		matriz_t acumMovimientos(n_, vector<int>(n_, 0));
		// Para contar si cada caballo pasó por cada posición (tienen que estar los k).
		matriz_t cantidad(n_, vector<int>(n_, 0));

		// Ejecuto k bfs (para cada caballo)
		for(int cab = 0; cab < k_; ++cab) {
			matriz_t movimientos(n_, vector<int>(n_, 0));

			bfs(caballos_[cab], movimientos);

			// Una vez que termino el BFS, acumulo los movimientos.
			for (int i = 0; i < n_; ++i) {
				for (int j = 0; j < n_; ++j) {
					acumMovimientos[i][j] += movimientos[i][j];
					// Ahora verifico que el caballo haya estado en esta posición
					if (movimientos[i][j] > 0)
						++cantidad[i][j];
					else {
						if ( (caballos_[cab].first-1 == i) && (caballos_[cab].second-1 == j))
							++cantidad[i][j];
					}
				}
			}
		}

		// Busco la casilla que tenga la mínima cantidad de movimientos y todos los caballos lleguen a esa casilla.
		m_ = numeric_limits<int>::max();
		for (int i = 0; i < n_; ++i) {
			for (int j = 0; j < n_; ++j) {
				if (cantidad[i][j] == k_) {
					if (acumMovimientos[i][j] < m_) {
						m_ = acumMovimientos[i][j];
						f_ = i+1;
						c_ = j+1;
					}
				}
			}
		}

	}

	void clear() {
		 f_ = 0;
		 c_ = 0;
		 m_ = numeric_limits<int>::max();
	}

	int size_n() const {
		return n_;
	}

	int size_k() const {
		return k_;
	}

	friend ostream & operator<<(ostream &os, Tablero& t);

	friend istream & operator>>(istream &is, Tablero& t);



};

ostream & operator<<(ostream &os, Tablero& t) {
	if (t.m_ < numeric_limits<int>::max())
		os << t.f_ << " " << t.c_ << " " << t.m_;
	else
		os << "no";

    return os;
}

istream & operator>>(istream &is, Tablero& t) {
	is >> t.n_;
	is >> t.k_;
	t.caballos_.resize(t.k_);
	for (int i = 0; i < t.k_; ++i) {
		is >> t.caballos_[i].first;
		is >> t.caballos_[i].second;
	}

	return is;
}

#endif /* SOLUCION_H_ */
