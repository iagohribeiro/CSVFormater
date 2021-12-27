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
	Table newTableObject;

	vector<int> wordSize;

	try{
		for (string element:csv_lines.table[csv_lines.table.size()-1])
		{
			wordSize.push_back(stoi(element));
		}

		for(int i=0; i<csv_lines.table.size(); i++)
		{
			if (i != csv_lines.table.size()-1)
			{
				if (i==1)
				{
					string format;
					string lineFormat;
					for(int j=0; j<csv_lines.table[i].size(); j++)
					{
						int difference =  wordSize[j] - strlen_utf8(csv_lines.table[i][j]);

						if (difference != 0)
						{
							format += csv_lines.table[i][j];
							size_t length = format.length();
							format.insert(length, wordSize[j] - strlen_utf8(csv_lines.table[i][j]), ' ');
							format.append("|");

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
	cout << "\n";

	for (int i = 0; i<convertedTable.size(); i++)
	{
		cout << convertedTable[i] + "\n";
	}
}

int Table::strlen_utf8(const string& string)
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
