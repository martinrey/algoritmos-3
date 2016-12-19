import math
import sys

class vuelo:
    def __init__(self, origen, destino, partida, llegada):
        self.origen = origen
        self.destino = destino
        self.partida = partida
        self.llegada = llegada
        

def plan(origen, llegada, destino, vuelos):
    if origen == destino:
        return llegada
    else:
        minimo = sys.maxint
        for v in vuelos:
            if (origen == v.origen) and (llegada <= v.partida-2):
                minimo = min(minimo, plan(v.destino, v.llegada, destino, vuelos))
        return minimo


vuelos = [vuelo(1, 2, 2, 3), vuelo(2, 4, 6, 18), vuelo(2, 4, 7, 20), vuelo(1, 3, 3, 6), vuelo(3, 4, 8, 17), vuelo(3, 4, 7, 16)]
print plan(1, 0, 4, vuelos)

vuelos = [vuelo(1, 4, 2, 3)]
print plan(1, 0, 4, vuelos)

vuelos = [vuelo(1, 2, 2, 3), vuelo(3, 4, 5, 8)]
print plan(1, 0, 4, vuelos)
