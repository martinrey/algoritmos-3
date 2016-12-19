#!/usr/bin/python
# -*- coding: utf-8 -*-

import random, math
from optparse import OptionParser
from sets import Set

def aleatorio(max_n, max_k):
	n = random.randint(1, max_n)
	k = random.randint(1, min(max_k, n))
	print n, k
	caballos = Set()
	while len(caballos) < k:
		f = random.randint(1, n)
		c = random.randint(1, n)
		caballo = (f, c)
		if not caballo in caballos:
			caballos.add(caballo)
	
	for cab in caballos:
		print cab[0], cab[1]


usage="Generador de inputs para Caballos."
parser = OptionParser(usage=usage)

parser.add_option("-i", "--instancias", dest="instancias", help="cantidad de instancias", default=10) 
parser.add_option("-k", "--kcaballos", dest="caballos", help="cantidad de maxima de caballos", default=20)
parser.add_option("-n", "--ntablero", dest="tablero", help="cantidad de filas del tablero", default=40)
(options, args) = parser.parse_args()


instancias = int(options.instancias)
k = int(options.caballos)
n = int(options.tablero)
for i in xrange(1, instancias+1):
	aleatorio(n, k)

