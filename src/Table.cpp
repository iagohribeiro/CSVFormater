/*
 * Table.cpp
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#include "Table.h"

Table::Table() {

}

Table::~Table() {

	convertedTable.clear();
}

Table Table::ToTable(const Lines& csv_lines){

	/**
	 * @brief This function will take an array of data from a CSV file
	 * and format it to the standard "ASCII table" and store the rows in
	 * an array.
	 */

	Table newTableObject;
	vector<int> wordSize;

	try{
		for (string element:csv_lines.table[csv_lines.table.size()-1])
		{
			/**
			 * @note The last row of the data matrix is the largest
			 * size of one word in each column of data. This data is
			 * as a string, so this function converts these numbers
			 * from string to integer and passes them into another array.
			 */
			wordSize.push_back(stoi(element));
		}

		for(int i=0; i<csv_lines.table.size(); i++)
		{
			if (i != csv_lines.table.size()-1)
			{
				/**
				 * @note Identifies which line after the header to
				 * add the separator line.
				 */
				if (i==1)
				{
					string format;
					string lineFormat;
					for(int j=0; j<csv_lines.table[i].size(); j++)
					{
						/**
						 * @note If the difference is 0, it is because
						 * the current word being treated is the largest
						 * in the column. Thus, it is possible to save
						 * some operations.
						 */
						int difference =  wordSize[j] - strlen_utf8(csv_lines.table[i][j]);

						if (difference != 0)
						{
							format += csv_lines.table[i][j];
							size_t length = format.length();

							/**
							 * @note Inserts a number of spaces in the string so that it
							 * will be formatted according to the column's largest word length.
							 */

							format.insert(length, wordSize[j] - strlen_utf8(csv_lines.table[i][j]), ' ');
							format.append("|");

							/**
							 * @note Creates the delimiter line
							 */

							size_t lengthLineFormat = lineFormat.length();
							lineFormat.insert(lengthLineFormat, wordSize[j], '-');
							lineFormat.append("+");
						}
						else
						{
							format += csv_lines.table[i][j];
							format.append("|");
						}

					}
					newTableObject.convertedTable.push_back(lineFormat);
					newTableObject.convertedTable.push_back(format);

				}
				else
				{
					string format;

					for(int j=0; j<csv_lines.table[i].size(); j++)
					{
						int difference =  wordSize[j] - strlen_utf8(csv_lines.table[i][j]);

						if (difference != 0)
						{
							format += csv_lines.table[i][j];
							size_t length = format.length();
							format.insert(length, wordSize[j] - strlen_utf8(csv_lines.table[i][j]), ' ');
							format.append("|");
						}
						else
						{
							format += csv_lines.table[i][j];
							format.append("|");
						}

					}
					newTableObject.convertedTable.push_back(format);

				}
			}

		}
	}
	catch (exception &e)
	{
		cout << "\nThe Program has stopped due to the following exception: " << e.what() << "\n";
		cout << "File: " << __FILE__ << "\n" << "Line: " << __LINE__ << "\n";
	}
	return newTableObject;
}

void Table::printTable ()
{
	/**
	 * @brief Prints the table already formatted for "ASCII table"
	 */
	cout << "\n";

	for (int i = 0; i<convertedTable.size(); i++)
	{
		cout << convertedTable[i] + "\n";
	}
}

int Table::strlen_utf8(const string& string)
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
