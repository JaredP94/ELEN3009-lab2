// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word): _word{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (_word.empty()) throw WordContainsNoLetters();
	string no_punc_word = remove_punc();
	if (no_punc_word.empty()) throw WordContainsNoLetters();
	if (space_check()) throw WordContainsSpace();

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	Word LHS = Word(lower_case(_word));
	Word RHS = Word(lower_case(rhs._word));
	LHS = LHS.remove_punc();
	RHS = RHS.remove_punc();
 	if (LHS._word == RHS._word)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
	const int MIN_SIZE_FOR_QUERY = 3;
	if  (_word.length() >= MIN_SIZE_FOR_QUERY)
		return true;
	else
		return false;
}

Word Word::lower_case(const string& entered_word) const
{
	string lower_word = entered_word;
	transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
	return Word(lower_word);
}

string Word::remove_punc() const
{
	string no_punc_word = _word;
	char chars_to_remove[] = "~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\"";
	for ( unsigned int i = 0; i < char_traits<char>::length(chars_to_remove); i++)
	{
		no_punc_word.erase( remove( no_punc_word.begin(), no_punc_word.end(), chars_to_remove[i]), no_punc_word.end());
	}
	return no_punc_word;
}

bool Word::space_check() const
{
	string check_word = _word;
	if (check_word.find(' ') != string::npos)
		return true;
	else
		return false;
 }