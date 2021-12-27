/*
 * Table.cpp
 *
 *  Created on: Dec 25, 2021
 *      Author: iagohribeiro
 */

#include "Table.h"

Table::Table() {
	// TODO Auto-generated constructor stub

}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

Table Table::ToTable(const Lines& csv_lines){
	Table newTableClass;

	vector<int> wordSize;
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
					int difference =  wordSize[j] - csv_lines.table[i][j].size();
					if (difference != 0)
					{
						format += csv_lines.table[i][j];
						//format.append((difference-1) - format.length(), ' ').append("|");
						//lineFormat.append((wordSize[j] - 1) - lineFormat.length(), '-').append("+");
						size_t length = format.length();
						format.insert(length, wordSize[j] - csv_lines.table[i][j].size(), ' ');
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
				newTableClass.convertedTable.push_back(lineFormat);
				newTableClass.convertedTable.push_back(format);

			}
			else
			{
				string format;
				for(int j=0; j<csv_lines.table[i].size(); j++)
				{
					int difference =  wordSize[j] - csv_lines.table[i][j].size();
					if (difference != 0)
					{
						format += csv_lines.table[i][j];
						//format.append((difference-1) - format.length(), ' ').append("|");
						size_t length = format.length();
						//cout<<"tamanho da palavra: "+ to_string(wordSize[j]) + "\n";
						//cout<<"tamanho da string: "+ to_string(length)+"\n";

						format.insert(length, wordSize[j] - csv_lines.table[i][j].size(), ' ');
						format.append("|");
					}
					else
					{
						format += csv_lines.table[i][j];
						format.append("|");
					}

				}
				//cout<<"String formatada: "+ format+"\n";
				newTableClass.convertedTable.push_back(format);

			}
		}

	}
	cout << "\n";
	for (int i = 0; i<newTableClass.convertedTable.size(); i++)
	{
		cout << newTableClass.convertedTable[i] +"\n";
	}

	return newTableClass;
}
