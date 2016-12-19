CXX = g++
DBG = gdb
CFLAGS = -ggdb -Wall -pedantic -m64 -fPIC -std=c++11

MAIN=horizontes
TEST=tester
TIME=timer

OBJS=src/horizontes.o

.PHONY: all test clean

all: $(MAIN) $(TEST) $(TIME)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ 

$(TEST): src/tester.o
	$(CXX) $(CFLAGS) $< -o $@ 

$(TIME): src/timer.o
	$(CXX) $(CFLAGS) $< -o $@ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(MAIN) $(TEST) $(TIME)
	rm -rf src/*.o
	
