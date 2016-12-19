CXX = g++
DBG = gdb
CFLAGS = -ggdb -Wall -pedantic -m64 -fPIC -std=c++11

MAIN=puentes
TEST=tester
TIME=timer
GEN=genera

OBJS=src/puentes.o

.PHONY: all test clean

all: $(MAIN) $(TEST) $(TIME) $(GEN)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ 

$(TEST): src/tester.o
	$(CXX) $(CFLAGS) $< -o $@ 

$(TIME): src/timer.o
	$(CXX) $(CFLAGS) $< -o $@ 
	
$(GEN): src/genera.o
	$(CXX) $(CFLAGS) $< -o $@ 
	
generar:
	./genera
	
run:
	b=0
	for a in entradas/entrada_*; do  \
		b=$$(($$b+1)); \
  	echo $$a ; \
  	./timer < $$a > salidas/$$b.txt ; \
  	echo "****************************" ; \
	done 



%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(MAIN) $(TEST) $(TIME) $(GEN)
	rm -rf src/*.o
	rm -rf entradas/*.txt
	
