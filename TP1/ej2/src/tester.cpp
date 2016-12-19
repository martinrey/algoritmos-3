/**
@file tester.cpp
@brief Tester de puentes

@author Grupo Theta
@date 2014.08.16
*/

// std
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdint.h>
#include "solucion.h"

using namespace std;

void test(const string& input, const string& output) {
	cout << "#### TEST" << endl << "in: " << input << endl << "out: " << endl << output << endl;
	
	istringstream istr(input);
	
	uint16_t n;
	istr >> n;

	vector<edificio_t> edificios(n);
	for (uint16_t i = 0; i < n; ++i) {
		uint16_t izq, alt, der;
		istr >> izq >> alt >> der;
		edificios[i] = edificio_t(izq, alt, der);
	}

	vector<uint16_t> valores;
	horizontes(edificios, valores);

	stringstream out;
	for(auto& v: valores) {
		out << v << " ";
	}
	out << endl;

	if (output != out.str())
		cerr << "ERROR --> result: " << out.str() << endl;
	else
		cout << "OK" << endl;
		
}

int main(int argc, char*argv[]) {
	
	// Test 1
	{
		stringstream ssi, sso;
		
		ssi << "4" << endl;
		ssi << "9 11 15" << endl;
		ssi << "7 12 10" << endl;
		ssi << "2 5 5" << endl;
		ssi << "10 10 14" << endl;

		// sso << "2 5 5 0 7 12 9 11 15 0 " << endl;
		sso << "2 5 5 0 7 12 10 11 15 0 " << endl;
		test(ssi.str(), sso.str());
	}
	
	// Test 2
	{
		stringstream ssi, sso;

		ssi << "3" << endl;
		ssi << "4 1 5" << endl;
		ssi << "0 4 2" << endl;
		ssi << "2 2 4" << endl;

		sso << "0 4 2 2 4 1 5 0 " << endl;
		test(ssi.str(), sso.str());
	}

	// Test 3
	{
		stringstream ssi, sso;

		ssi << "3" << endl;
		ssi << "0 4 2" << endl;
		ssi << "0 2 2" << endl;
		ssi << "0 3 2" << endl;

		sso << "0 4 2 0 " << endl;
		test(ssi.str(), sso.str());
	}

	// Test 4
	{
		stringstream ssi, sso;

		ssi << "3" << endl;
		ssi << "0 3 2" << endl;
		ssi << "0 2 4" << endl;
		ssi << "3 2 4" << endl;

		sso << "0 3 2 2 4 0 " << endl;
		test(ssi.str(), sso.str());
	}

	// Test 5
	{
		stringstream ssi, sso;

		ssi << "2" << endl;
		ssi << "1 2 6" << endl;
		ssi << "5 1 8" << endl;

		sso << "1 2 6 1 8 0 " << endl;
		test(ssi.str(), sso.str());
	}

    return 0;
}

