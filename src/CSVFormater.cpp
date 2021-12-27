//============================================================================
// Name        : CSVFormater.cpp
// Author      : Iagoh Ribeiro Lima
// Version     : 1.0
// Description : CSVFormater Project
//============================================================================

#include <iostream>
#include "Lines.h"
#include "Table.h"

using namespace std;

int main() {

	string path;
	cout << "Enter the path along with the file name and extension: ";
	getline(cin, path);
	Lines lines (path);
	lines.buildTable();

	const Lines linesToBeConverted = lines;

	Table formatedTable;

	formatedTable = formatedTable.ToTable(linesToBeConverted);

	return 0;
}
