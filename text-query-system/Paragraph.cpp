// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	lines.push_back(line);
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	bool word_was_found = false;
	for (size_t n = 0; n < lines.size(); n++)
	{
		if (lines.at(n).contains(search_word))
		{
			line_numbers.push_back(n + 1);
			word_was_found = true;
		}
	}
	return word_was_found;
}