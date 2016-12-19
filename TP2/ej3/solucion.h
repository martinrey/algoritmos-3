#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <cmath>
#include <limits>       // std::numeric_limits

using namespace std;


class Nodo{
public:
    int numero, distancia;
    bool visitado, en_anillo;
    Nodo * padre;
    vector <pair <Nodo*, int> > adyacentes;
    vector <int> arista_en_AGM;

	Nodo(int numero, int N): numero(numero){
		padre = NULL;
		distancia = numeric_limits<int>::max();
		visitado = false;
        en_anillo = false;
        arista_en_AGM.resize(N+1);
	}

 	void agregarAdyacente(Nodo* adyacente, int costo)
 	{
 		adyacentes.push_back(make_pair(adyacente, costo));
 	}
};


struct Comp {
    bool operator()(const Nodo* s1, const Nodo* s2) {
        return (s1->distancia > s2->distancia);
    }
};





class LCdA{
public:
	int N, M, C;
	vector<Nodo> nodos;
    vector<pair < int , pair <Nodo*, Nodo* > > > aristas ;
    vector<pair<Nodo*, Nodo*> > anillo;
    vector<pair<Nodo*, Nodo*> > resto;

	LCdA():C(0){}
	int buscar_AGM();
	void formar_anillo();

};


int LCdA::buscar_AGM(){

    // Si M < N no puede ser conexo y tener un ciclo
    if(M < N)
        return 1;


    vector <Nodo*>  heap;
    for (int i = 1; i <= N; i++)
    {
        heap.push_back(&nodos[i]);
    }
    Nodo * u = heap[0];
    u->distancia = 0;

    while (!heap.empty())
    {   
        Nodo * u = heap.front(); pop_heap(heap.begin(), heap.end(), Comp()); 
        heap.pop_back();

        // Distancia es infinito <==> es no conexo
        if(u->distancia == numeric_limits<int>::max())
            return 1;

        // Anoto la arista como parte del AGM
        if (u->padre != NULL)
        {
            u->arista_en_AGM[u->padre->numero] = 1;
            u->padre->arista_en_AGM[u->numero] = 1;
        }

        C+= u->distancia;
        u->visitado = true;
        
        for (unsigned int i = 0; i < u->adyacentes.size(); i++)
        {
            Nodo * v = u->adyacentes[i].first;
            if (!v->visitado && v->distancia > u->adyacentes[i].second)
            {
                v->padre = u;
                v->distancia = u->adyacentes[i].second;
                // aca hay qe actualizar el heap, y no hacer el make_heap de ahi abajo (teoricamente se actualiza en log n y el make_heap es 3N)
            }              
        }
        // esto vendria ser la actulizacion del heap mal hecha
        make_heap(heap.begin(), heap.end(), Comp());
    }

    return 0;
}


void LCdA::formar_anillo()
{
    sort(aristas.begin(), aristas.end());


    pair<Nodo*, Nodo*> arista_extra;


    for (unsigned int i = 0; i < aristas.size(); i++)
    {
        if(aristas[i].second.first->arista_en_AGM[aristas[i].second.second->numero] == 0)
        {    
            C += aristas[i].first;
            arista_extra = aristas[i].second;
            break;
        }
    }


    Nodo * a = arista_extra.first;
    Nodo * b = arista_extra.second;

    // Formo el anillo llendo desde cada uno de los nodos de la arista extra hacia atras hasta llegar al otro nodo o a NULL
    for (int i = 0; i < 2; i++)
    {        
        while(a != NULL && a != b)
        {
            a->en_anillo = true;
            a = a->padre;
        }
        a = arista_extra.second;
        b = arista_extra.first;
    }


    anillo.push_back(arista_extra);

    // Separo las aristas del resto de las del anillo
    for (int i = 1; i <= N; i++)
    {
        Nodo* k = &nodos[i];
        if (k->padre != NULL)
        {
            if (k->en_anillo)
            {
                anillo.push_back(make_pair(k, k->padre));
            }
            else
                resto.push_back(make_pair(k, k->padre));
        }
          
    }
}




istream & operator>>(istream &is, LCdA& r) {
    is >> r.N >> r.M;

    
    Nodo ghost = Nodo(0, 0);            // Para que los nodos empiezen desde la posicion 1
    r.nodos.push_back(ghost);

    for (int i = 1; i <= r.N; i++) 
    {
        r.nodos.push_back(Nodo(i, r.N));
    }

    for (int i = 0; i < r.M; i++)
    {
        int a, b, c;
        is >> a >> b >> c;

        r.aristas.push_back(make_pair(c, make_pair(&r.nodos[a], &r.nodos[b])));
        r.nodos[a].agregarAdyacente(&r.nodos[b], c);
        r.nodos[b].agregarAdyacente(&r.nodos[a], c);
    }

    return is;
}





ostream & operator<<(ostream &os, LCdA& r) {

    os << r.C << " " << r.anillo.size() << " " << r.resto.size() << endl;

    for (unsigned int i = 0; i < r.anillo.size(); i++)
    {
        os << r.anillo[i].first->numero << " " << r.anillo[i].second->numero << endl;
    }

    for (unsigned int i = 0; i < r.resto.size(); i++)
    {
        os << r.resto[i].first->numero << " " << r.resto[i].second->numero << endl;
    }

    return os;
}



#endif /* SOLUCION_H_ */