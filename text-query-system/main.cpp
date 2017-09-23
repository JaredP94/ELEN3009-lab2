#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>

int main()
{
	string input_file, search_word;
	cout << "Please enter file name: ";
	cin >> input_file;
	
	FileReader filereader(input_file);
	Paragraph paragraph;
	filereader.readFileInto(paragraph);
	
	while (true)
	{
		cout << "Please enter a word to search for or ""."" to quit: ";
		cin >> search_word;
		cout << endl;
		if (search_word == ".") break;
		Word search_for(search_word);
		vector<int> line_number;
		
		if(paragraph.contains(search_word, line_number) == true)
			cout << "Word found: " << endl;
		for (size_t i = 0; i < line_number.size(); i++)
			cout << "\t\t line " << line_number.at(i) << endl;
		cout << endl;
	}
	return 0;
}

//Current program design returns line number when a word is found, this means that the same word will not be checked again if it occurs within the same line
//This would thus need a design modification to index through each line, incrementing a counter for words found per line