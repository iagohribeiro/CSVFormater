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

	/**
	 * @note gets the file path via user input
	 */
	string path;
	cout << "Enter the path along with the file name and extension: ";
	getline(cin, path);

	/**
	 * @note Create a Lines object and call the buildTable method
	 * to read the CSV file and create the data table.
	 */
	Lines lines (path);
	lines.buildTable();

	const Lines linesToBeConverted = lines;

	/**
	 * Creates a Table object, calls the ToTable method
	 * to format the sent table data, and then calls the
	 * printTable method to print the formatted table.
	 */
	Table formatedTable;
	formatedTable = formatedTable.ToTable(linesToBeConverted);
	formatedTable.printTable();

	return 0;
}
