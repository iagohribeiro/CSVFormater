/*
 * Lines.cpp
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#include "Lines.h"

Lines::Lines(string fileName) {

	this->fileName = fileName;

}

Lines::~Lines() {
	table.clear();
}

void Lines::buildTable (){

	/**
	 * @brief Builds a table from data read from a CSV file
	 */

	vector<string> row, lastLine;
	vector<int> wordSize;
	int wordSizeVecInd = 0;
	string line, word;
	fstream file (fileName);
	bool firstLine = true;

	try
	{
		if(file.is_open())
		{
			while(getline(file, line))
			{
				row.clear();
				stringstream str(line);
				if (firstLine)
				{
					/**
					 * @note considers ";" as the separator of the CSV data
					 */

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
							/**
							 * @note Checks the word size and stores the largest
							 * size in the word size array.
							 */

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

			/**
			 * @note Adds the word size array as the last row of the table.
			 * This row will be used later to find out which is the largest
			 * word in a column.
			 */

			table.push_back(lastLine);

			file.close();
		}
		else
		{
			cout<<"The file could not be opened.\n";
		}
	}
	catch (exception &e)
	{
		cout << "\nThe Program has stopped due to the following exception: " << e.what() << "\n";
		cout << "File: " << __FILE__ << "\n" << "Line: " << __LINE__ << "\n";
		file.close();
	}
}

int Lines::strlen_utf8(const string& string)
{
	/**
	 * @brief Counts the character number in UTF8.
	 * This function helps to disregard the bytes "wrongly"
	 * counted by the length and size functions when the
	 * string has special characters.
	 */

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
