/**
@file tester.cpp
@brief Tester de <>

@author Grupo P
@date 2014.04.12
*/

// std
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <stdint.h>
#include "solucion.h"

using namespace std;

void test(const string& input, const set<string>& output) {
	cout << "#### TEST" << endl << "in: \n" << input << endl;
	cout << "posibles resultados: \n";

	for (auto& r: output)
		cout << r << "|";
	cout << endl;

	istringstream istr(input);
	ostringstream out;

	Anillo test;
	istr >> test;
	test.resolver();
	out << test;

	if (output.count(out.str()) == 0)
		cerr << "resultado: ERROR --> result: " << out.str() << endl;
	else
		cout << "resultado: OK" << endl;

}

int main(int argc, char*argv[]) {

	// Test 1: Caso fácil
	{
		stringstream ssi;
		set<string> result;

		ssi << "4 0" << endl;
		result.insert("no");


		test(ssi.str(), result);
	}


    return 0;
}

