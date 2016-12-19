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
	
	stringstream out;

	if (output != out.str())
		cerr << "ERROR --> result: " << out.str() << endl;
	else
		cout << "OK" << endl;
		
}

int main(int argc, char*argv[]) {
	
	// Test 1
	{
		stringstream ssi, sso;
		
		ssi << "3 1 1 3 3 0" << endl;
		ssi << "1 1 1" << endl;
		ssi << "1 1 1" << endl;
		ssi << "1 1 1" << endl;

		sso << "4" << endl;
		sso << "2 1 0" << endl;
		sso << "3 1 0" << endl;
		sso << "3 2 0" << endl;
		sso << "3 3 0" << endl;
		test(ssi.str(), sso.str());
	}
	

    return 0;
}

