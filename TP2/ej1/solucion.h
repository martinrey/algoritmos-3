
#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <list>
#include <queue>
#include <map>
#include <utility>
#include <limits>

#define INFINITO			std::numeric_limits<size_t>::max()

class Tupla: public std::pair<size_t, size_t> {
public:
	Tupla(const size_t& f, const size_t& s) : std::pair<size_t, size_t>(f, s) {}
	bool operator()(const Tupla& lhs, const Tupla&rhs) const {
			return (lhs.second > rhs.second);
	}
};

class PlanVuelo {

    typedef struct VueloIn {
    	size_t id_;
        std::string ori_;
        std::string des_;
        size_t ini_;
        size_t fin_;
        VueloIn() : id_(0), ini_(0), fin_(0) {}
        VueloIn(const VueloIn& v) : id_(v.id_), ori_(v.ori_), des_(v.des_), ini_(v.ini_), fin_(v.fin_) {}
    } VueloIn;

    typedef struct Vuelo {
    	size_t id_;
        size_t ori_;
        size_t des_;
        size_t ini_;
        size_t fin_;
        Vuelo() : id_(0), ori_(0), des_(0), ini_(0), fin_(0) {}
        Vuelo(size_t id, size_t ori, size_t des, size_t ini, size_t fin) : id_(id), ori_(ori), des_(des), ini_(ini), fin_(fin) {}
        Vuelo(const Vuelo& v) : id_(v.id_), ori_(v.ori_), des_(v.des_), ini_(v.ini_), fin_(v.fin_) {}
    } Vuelo;
    
    std::vector<VueloIn> vuelos_;
    std::vector<Vuelo> vuelosId_;

	/// Cantidad de equipos
	size_t n_;

    /// Ciudad de Origen del plan de vuelo
    std::string origen_;

    /// Ciudad de Destino Final del plan vuelo
    std::string destino_;

    /// Diccionario de ciudad <Nombre ciudad, id ciudad>
    std::map<std::string, size_t> ciudades_;

    /// Resultado.
    size_t minimo_;

    /// Listado de vuelos a tomar para la solucion óptima.
    std::list<size_t> itenerario_;

    typedef std::vector< std::list<Vuelo> > adyacencias_t;

    size_t dijkstra(size_t origen, size_t destino, adyacencias_t& adyacencias, std::list<size_t>& itenerario) {

    	std::priority_queue< Tupla > cola;

    	std::vector<size_t> distancia(ciudades_.size(), INFINITO);
    	std::vector<size_t> padre(ciudades_.size(), INFINITO);
    	std::vector<size_t> vuelo(ciudades_.size(), INFINITO);

    	distancia[origen] = 0;
    	cola.push(Tupla(origen, 0));

    	while (!cola.empty()) {
    		Tupla u =cola.top(); cola.pop();
    		for(auto& v: adyacencias[u.first]) {
    			if (distancia[v.des_] > v.fin_) {
    				if ((distancia[u.first] == 0) || ((int)distancia[u.first] <= (int)(v.ini_ - 2))) {
						distancia[v.des_] = v.fin_;
						padre[v.des_] = u.first;
						vuelo[v.des_] = v.id_;
						cola.push(Tupla(v.des_, distancia[v.des_]));
    				}
    			}
    		}
    	}
        
    	if (distancia[destino] != INFINITO) {
			size_t ciudad = padre[destino];
			itenerario.push_front(vuelo[destino]);
			while (ciudad != origen && ciudad != INFINITO) {
				itenerario.push_front(vuelo[ciudad]);
				ciudad = padre[ciudad];
			}
			// Si la última ciudad no es el origen, entonces no hay itinerario.
			if (ciudad == INFINITO) {
				itenerario.clear();
				return INFINITO;
			}
    	}
    	return distancia[destino];
    }

public:
	PlanVuelo(): n_(0), minimo_(INFINITO) {}

	void resolver() {
		size_t ciudades(0);
		if (vuelos_.size() > 0) {
			// A cada ciudad le asigno un identificador único (numérico)
			for (auto& vuelo: vuelos_) {
				auto origen = ciudades_.find(vuelo.ori_);
				if (origen == ciudades_.end())
					origen = ciudades_.insert(std::make_pair(vuelo.ori_, ciudades++)).first;

				auto destino = ciudades_.find(vuelo.des_);
				if (destino == ciudades_.end())
					destino = ciudades_.insert(std::make_pair(vuelo.des_, ciudades++)).first;

				vuelosId_.push_back(Vuelo(vuelo.id_, origen->second, destino->second, vuelo.ini_, vuelo.fin_));
			}

			// Cargo la matriz de adyacencia
			adyacencias_t adyacencias(ciudades_.size());
			for(auto& v: vuelosId_)
				adyacencias[v.ori_].push_back(v);

			auto origen = ciudades_.find(origen_);
			auto destino = ciudades_.find(destino_);

			if (origen != ciudades_.end() && destino != ciudades_.end())
				minimo_ = dijkstra(origen->second, destino->second, adyacencias, itenerario_);
		}
	}

	void clear() {
		minimo_ = INFINITO;
		itenerario_.clear();
	}

	int size_n() const {
		return n_;
	}

    int size_k() const {
		return ciudades_.size();
	}
    
	friend std::ostream & operator<<(std::ostream &os, PlanVuelo& p);

	friend std::istream & operator>>(std::istream &is, PlanVuelo& p);

};

std::ostream & operator<<(std::ostream &os, PlanVuelo& p) {
	if (p.vuelos_.size() > 0) { // Esto es para evitar imprimir en la última línea
		if (p.minimo_ != INFINITO) {
			os << p.minimo_ << " " << p.itenerario_.size() << " ";
			for(auto& v: p.itenerario_)
				os << v << " ";
		}
		else {
			os << "no";
		}
	}
    return os;
}

std::istream & operator>>(std::istream &is, PlanVuelo& p) {
    is >> p.origen_ >> p.destino_ >> p.n_;
    if (p.origen_ != "0") {
		p.vuelos_.resize(p.n_);
		size_t id = 1;
		for (auto& vuelo: p.vuelos_) {
			vuelo.id_ = id++;
			is >> vuelo.ori_ >> vuelo.des_ >> vuelo.ini_>> vuelo.fin_;
		}
    }
	return is;
}

#endif /* SOLUCION_H_ */
