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
					wordSize.push_back(strlen_utf8(word));
					row.push_back(word);
				}
				firstLine = false;
			}
			else
			{
				wordSizeVecInd = 0;

				while(getline(str, word, ';'))
				{
					if (strlen_utf8(word) > wordSize[wordSizeVecInd])
					{
						wordSize[wordSizeVecInd] = strlen_utf8(word);
					}
					wordSizeVecInd++;
					row.push_back(word);
				}

			}

			table.push_back(row);
		}

		for(int i=0; i<wordSize.size(); i++)
		{
			lastLine.push_back(to_string(wordSize[i]));
		}

		table.push_back(lastLine);

		file.close();
	}
	else
	{
		cout<<"The file could not be opened.\n";
	}
}

int Lines:: strlen_utf8(const string& string)
{
	int length = 0;

	for (char character:string)
	{
		if ((character & 0xC0) != 0x80)
		{
			++length;
		}
	}
	return length;
}
