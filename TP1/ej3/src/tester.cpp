/**
@file tester.cpp
@brief Tester de Biohazard

@author Grupo Theta
@date 2014.08.18
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
	ostringstream out;

	Biohazard test;
	istr >> test;
	test.backtracking();
	out << test;

	if (output != out.str())
		cerr << "ERROR --> result: " << out.str() << endl;
	else
		cout << "OK" << endl;
		
}

int main(int argc, char*argv[]) {
	
	// Test 1: N=2 y M=2 <-- 2 ==>> Entra todo en 1 camion
	{
		stringstream ssi, sso;
		
		ssi << "2 2" << endl;
		ssi << "1" << endl;

		sso << "1 1 1 " << endl;
		test(ssi.str(), sso.str());
	}
	

	// Test 2: N=3 y M=6 ==>> Entra en 2 camiones
	{
		stringstream ssi, sso;

		ssi << "3 6" << endl;
		ssi << "6 7" << endl;
		ssi << "8" << endl;

		sso << "2 1 1 2 " << endl;
		test(ssi.str(), sso.str());
	}

	// Test 3: N=3 y M=6 ==>> Entra en 3 camiones
	{
		stringstream ssi, sso;

		ssi << "3 6" << endl;
		ssi << "7 7" << endl;
		ssi << "8" << endl;

		sso << "3 1 2 3 " << endl;
		test(ssi.str(), sso.str());
	}

	// Test 4: N=3 y M=6 ==>> Entra en 1 camion
	{
		stringstream ssi, sso;

		ssi << "3 8" << endl;
		ssi << "2 3" << endl;
		ssi << "3" << endl;

		sso << "1 1 1 1 " << endl;
		test(ssi.str(), sso.str());
	}

    return 0;
}
