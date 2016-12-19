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

	Tablero test;
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

		ssi << "3 2" << endl;
		ssi << "1 1" << endl;
		ssi << "1 3" << endl;

		result.insert("1 1 2");
		result.insert("1 3 2");
		result.insert("3 2 2");

		test(ssi.str(), result);
	}

	// Test 2: Sin solución
	{
		stringstream ssi;
		set<string> result;

		ssi << "3 2" << endl;
		ssi << "1 1" << endl;
		ssi << "2 2" << endl;

		result.insert("no");

		test(ssi.str(), result);
	}

	// Test 3: Una dificil
	{
		stringstream ssi;
		set<string> result;

		ssi << "4 3" << endl;
		ssi << "1 1" << endl;
		ssi << "3 2" << endl;
		ssi << "4 4" << endl;

		result.insert("3 2 2");

		test(ssi.str(), result);
	}

    return 0;
}

