/**
@file tester.cpp
@brief Tester de PlanVuelo

@author Grupo Theta
@date 2014.09.15
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

	PlanVuelo test;
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

		ssi << "Rosario Madrid 6" << endl;
		ssi << "Rosario Buenos_Aires 2 3" << endl;
		ssi << "Buenos_Aires Madrid 6 18" << endl;
		ssi << "Buenos_Aires Madrid 7 20" << endl;
		ssi << "Rosario San_Pablo 3 6" << endl;
		ssi << "San_Pablo Madrid 8 17" << endl;
		ssi << "San_Pablo Madrid 7 16" << endl;
		result.insert("17 2 4 5 ");

		test(ssi.str(), result);
	}

	// Test 2: Caso
	{
		stringstream ssi;
		set<string> result;

		ssi << "Rosario Paris 10" << endl;
		ssi << "Rosario Buenos_Aires 2 3" << endl;
		ssi << "Buenos_Aires Madrid 6 18" << endl;
		ssi << "Buenos_Aires Madrid 7 20" << endl;
		ssi << "Rosario San_Pablo 3 6" << endl;
		ssi << "San_Pablo Madrid 8 17" << endl;
		ssi << "San_Pablo Madrid 7 16" << endl;
		ssi << "Madrid Paris 17 19" << endl;
		ssi << "Barcelona Paris 19 20" << endl;
		ssi << "Madrid Paris 18 20" << endl;
		ssi << "Madrid Paris 19 20" << endl;
		result.insert("20 3 4 5 10 ");

		test(ssi.str(), result);
	}


	// Test 3: Caso
	{
		stringstream ssi;
		set<string> result;

		ssi << "Miami Londres 12" << endl;
		ssi << "Miami Madrid 0 8" << endl;
		ssi << "Miami Roma 2 9" << endl;
		ssi << "Miami Barcelona 3 10" << endl;
		ssi << "Miami Atlanta 1 2" << endl;
		ssi << "Atlanta Londres 4 12" << endl;
		ssi << "Barcelona Londres 8 10" << endl;
		ssi << "Barcelona Londres 12 13" << endl;
		ssi << "Madrid Londres 5 6" << endl;
		ssi << "Madrid Londres 9 10" << endl;
		ssi << "Madrid Londres 12 13" << endl;
		ssi << "Roma Londres 11 12" << endl;
		ssi << "Londres MIami 18 24" << endl;

		result.insert("12 2 2 11 ");
		result.insert("12 2 4 5 ");

		test(ssi.str(), result);
	}

	// Test 4: Caso
	{
		stringstream ssi;
		set<string> result;

		ssi << "Miami Tokio 14" << endl;
		ssi << "Miami Atlanta 0 1" << endl;
		ssi << "Miami Boston 0 3" << endl;
		ssi << "Atlanta Roma 3 11" << endl;
		ssi << "Atlanta Barcelona 3 10" << endl;
		ssi << "Boston Madrid 5 9" << endl;
		ssi << "Boston Londres 5 8" << endl;
		ssi << "Roma Bangkok 13 21" << endl;
		ssi << "Roma Delhi 14 20" << endl;
		ssi << "Madrid Bangkok 12 22" << endl;
		ssi << "Londres Kuala_Lumpur 10 21" << endl;
		ssi << "Delhi Tokio 22 26" << endl;
		ssi << "Bangkok Tokio 24 27" << endl;
		ssi << "Kuala_Lumpur Tokio 23 26" << endl;
		ssi << "Roma Tokio 12 23" << endl;

		result.insert("26 4 2 6 10 13 ");
		result.insert("26 4 1 3 8 11 ");

		test(ssi.str(), result);
	}

	// Test 5: Sin solucion
	{
		stringstream ssi;
		set<string> result;

		ssi << "Rosario Madrid 4" << endl;
		ssi << "Rosario Buenos_Aires 2 3" << endl;
		ssi << "Rosario San_Pablo 3 6" << endl;
		ssi << "San_Pablo Barcelona 8 17" << endl;
		ssi << "Barcelona Madrid 7 16" << endl;
		result.insert("no");

		test(ssi.str(), result);
	}

    return 0;
}

