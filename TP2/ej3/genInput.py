#!/usr/bin/python
# -*- coding: utf-8 -*-

import random, math
from optparse import OptionParser

def dispersos(pueblos, maxCoord, porcentajeCentrales):
	centrales = int(pueblos * porcentajeCentrales)
	print pueblos, centrales
	
	for i in range(1,pueblos):
	  x = random.randint(1, maxCoord)
	  y = random.randint(1, maxCoord)
	  print x, y
	
	

usage="Generador de inputs para < >."
parser = OptionParser(usage=usage)

parser.add_option("-i", "--instancias", dest="instancias", help="cantidad de instancias", default=10) 
parser.add_option("-a", "--algoritmo", dest="algoritmo", help="Algoritmos: dispersos", default="dispersos") 
parser.add_option("-c", "--maxcoord", dest="maxcoord", help="Valor de la coordenada mas grande", default=50) 
parser.add_option("-p", "--porccent", dest="porccent", help="Porcentaje de centrales", default=0.5)
(options, args) = parser.parse_args()



if options.algoritmo== "dispersos":
	dispersos(int(options.instancias), int(options.maxcoord), float(options.porccent));
