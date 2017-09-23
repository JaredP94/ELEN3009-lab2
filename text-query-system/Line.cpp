// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <sstream>

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	string extract_words = line;
	split(line_of_words, extract_words, " ", true);
}

bool Line::contains(const Word& search_word) const
{
	if (line_of_words.empty())
		return false;
	else if(!search_word.isQueryable())
		return false;
	else if (find(line_of_words.begin(), line_of_words.end(), search_word) != line_of_words.end())
		return true;
	else
		return false;
}

void Line::split(vector<Word>& vec, const string& input, const string& separators, bool remove_empty)
{
	ostringstream word;
	for (size_t n = 0; n < input.size(); ++n)
	{
		if (string::npos == separators.find(input[n]))
			word << input[n];
		else
		{
			if (!word.str().empty() || !remove_empty)
				vec.push_back(word.str());
			word.str("");
		}
	}
	if (!word.str().empty() || !remove_empty)
		vec.push_back(word.str());
}