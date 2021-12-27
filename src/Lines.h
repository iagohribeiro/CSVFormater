/*
 * Lines.h
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#ifndef LINES_H_
#define LINES_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Lines {
	string fileName;
	string lines;
public:
	vector < vector<string> > table;
	Lines(string fileName);
	virtual ~Lines();
	void buildTable ();
};

#endif /* LINES_H_ */
