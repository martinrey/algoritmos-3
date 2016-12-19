CXX = g++
DBG = gdb
# CFLAGS = -ggdb -pg -Wall -m64 -std=c++11
CFLAGS = -s -O2 -Wall -m64 -std=c++11

MAIN=biohazard
TIME=timer
GEN=genera
TEST=tester
OBJS=src/biohazard.o

.PHONY: all test clean

all: $(MAIN) $(TIME) $(GEN) $(TEST)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ 

$(TIME): src/timer.o
	$(CXX) $(CFLAGS) $< -o $@ 
	
$(GEN): src/genera.o
	$(CXX) $(CFLAGS) $< -o $@ 

$(TEST): src/tester.o
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
	rm -rf $(MAIN) $(TIME) $(GEN)
	rm -rf src/*.o
	rm -rf entradas/*.txt
