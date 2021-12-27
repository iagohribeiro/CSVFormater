/*
 * Table.h
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#ifndef TABLE_H_
#define TABLE_H_
#include <iomanip>
#include <codecvt>
#import "Lines.h"

class Table {

public:
	string formatedString;
	vector <string> convertedTable;

	Table();
	Table ToTable(const Lines& csv_lines);
	virtual ~Table();
	int strlen_utf8 (const string& str);
	void printTable ();
};

#endif /* TABLE_H_ */
