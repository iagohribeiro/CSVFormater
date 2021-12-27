/*
 * Lines.cpp
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#include "Lines.h"

Lines::Lines(string fileName) {
	// TODO Auto-generated constructor stub

	this->fileName = fileName;

}

Lines::~Lines() {
	// TODO Auto-generated destructor stub
}

void Lines::buildTable (){

	vector<string> row, lastLine;
	vector<int> wordSize;
	int wordSizeVecInd = 0;
	string line, word;
	fstream file (fileName);
	bool firstLine = true;

	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
			stringstream str(line);
			if (firstLine)
			{
				while(getline(str, word, ';'))
				{
					wordSize.push_back(word.length());
					row.push_back(word);
				}
				firstLine = false;
			}
			else
			{
				wordSizeVecInd = 0;

				while(getline(str, word, ';'))
				{
					if (word.length() > wordSize[wordSizeVecInd])
					{
						wordSize[wordSizeVecInd] = word.length();
					}
					wordSizeVecInd++;
					row.push_back(word);
				}

			}

			table.push_back(row);
		}
		//For test purpose
		//string lastLine = "";
		for(int i=0; i<wordSize.size(); i++)
		{
			lastLine.push_back(to_string(wordSize[i]));
		}

		table.push_back(lastLine);
	}
	else
	{
		cout<<"The file could not be opened.\n";
	}

	for(int i=0;i<table.size();i++)
		{
			for(int j=0;j<table[i].size();j++)
			{
				cout<<table[i][j]<<" ";
			}
			cout<<"\n";
		}

}
