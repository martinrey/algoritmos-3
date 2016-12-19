#!/usr/bin/python
# -*- coding: utf-8 -*-

import random, math
import fileinput
from sets import Set
from optparse import OptionParser

ciudades = []

def cargarCiudades():
	global ciudades
	fciudades = open('ciudades.txt')
	for ciudad in fciudades:
		ciudades.append(ciudad.replace('\n', ' '))
	
	fciudades.close()

def generar_vuelos(n, mis_ciudades):
    global ciudades

    vuelos = Set()
    k = len(mis_ciudades)
    while len(vuelos) < n:
        o = random.randint(0, k-1)
        d = random.randint(0, k-1)
        i = random.randint(0, (k-1)*10)
        f = random.randint(i+1, k*10)
        vuelos.add( (ciudades[mis_ciudades[o]], ciudades[mis_ciudades[d]], i, f) )

    for vuelo in vuelos:
        print vuelo[0], vuelo[1], vuelo[2], vuelo[3]

def aleatorio(max_n):
    global ciudades

    n = random.randint(1, max_n)
    k = len(ciudades)
    n = min(n, k)
    
    o = random.randint(0, k-1)
    d = random.randint(0, k-1)	

    print ciudades[o], ciudades[d], n
    ## Ahora elijo a lo sumo 2*n ciudades.
    mis_ciudades = [o, d]

    # k = random.randint(2, min(n, 2*k))
    for i in xrange(1, k):
        mis_ciudades.append(i-1)
    generar_vuelos(n, mis_ciudades)
    
def dos_n(max_n):
    global ciudades

    n = random.randint(8, max_n)
    k = len(ciudades)
    o = random.randint(0, k-1)
    d = random.randint(0, k-1)	

    print ciudades[o], ciudades[d], n
    ## Ahora elijo a lo sumo 2*n ciudades.
    mis_ciudades = [o, d]
    cant = 2*n;
    intentos = 0
    while len(mis_ciudades) < cant:
        c = random.randint(0, k-1)
        intentos += 1
        if not c in mis_ciudades:
            mis_ciudades.append(c)
            intentos = 0
        if intentos > 3:
            break
    generar_vuelos(n, mis_ciudades)

def igual_n(max_n):
    global ciudades

    n = random.randint(8, max_n)
    k = len(ciudades)
    o = random.randint(0, k-1)
    d = random.randint(0, k-1)	

    print ciudades[o], ciudades[d], n
    mis_ciudades = [o, d]
    ## Ahora elijo a lo sumo 2*n ciudades.
    cant = n
    intentos = 0
    while len(mis_ciudades) < cant:
        c = random.randint(0, k-1)
        intentos += 1
        if not c in mis_ciudades:
            mis_ciudades.append(c)
            intentos = 0
        if intentos > 3:
            break

    generar_vuelos(n, mis_ciudades);

def medio_n(max_n):
    global ciudades

    n = random.randint(8, max_n)
    k = len(ciudades)
    o = random.randint(0, k-1)
    d = random.randint(0, k-1)	

    print ciudades[o], ciudades[d], n
    ## Ahora elijo a el resto de las ciudades
    mis_ciudades = [o, d]
    cant = int(n/2)
    intentos = 0
    while len(mis_ciudades) < cant:
        c = random.randint(0, k-1)
        intentos += 1
        if not c in mis_ciudades:
            mis_ciudades.append(c)
            intentos = 0
        if intentos > 3:
            break

    generar_vuelos(n, mis_ciudades);

usage="Generador de inputs para < >."
parser = OptionParser(usage=usage)

parser.add_option("-i", "--instancias", dest="instancias", help="cantidad de instancias", default=10) 
parser.add_option("-n", "--nvuelos", dest="vuelos", help="cantidad maxima de vuelos", default=500) 
parser.add_option("-t", "--tipo", dest="tipo", help="tipo de instancias: aleatorio, dos_n, igual_n, medio_n", default="aleatorio") 
(options, args) = parser.parse_args()

cargarCiudades();

instancias = int(options.instancias)

n = int(options.vuelos)
if options.tipo == "aleatorio":
    for i in xrange(1, instancias+1):
        aleatorio(n)
elif options.tipo == "dos_n":
    for i in xrange(1, instancias+1):
        dos_n(n)
elif options.tipo == "igual_n":
    for i in xrange(1, instancias+1):
        igual_n(n)
elif options.tipo == "medio_n":
    for i in xrange(1, instancias+1):
        medio_n(n)
print 0
