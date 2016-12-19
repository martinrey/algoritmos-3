CXX = g++
DBG = gdb
# CFLAGS = -ggdb -Wall -pedantic -m64 -fPIC -std=c++11
CFLAGS = -O2 -Wall -pedantic -m64 -s -std=c++11

MAIN=caballos
TEST=tester
TIME=tiempos


OBJS=caballos.o
HDRS=solucion.h

.PHONY: all test clean

all: $(MAIN) $(TEST) $(TIME)

$(MAIN): $(OBJS) $(HDRS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ 

$(TEST): tester.o $(HDRS)
	$(CXX) $(CFLAGS) tester.o -o $@ 

$(TIME): tiempos.o $(HDRS)
	$(CXX) $(CFLAGS) tiempos.o -o $@ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(MAIN) $(TEST) $(TIME)
	rm -rf *.o
	
