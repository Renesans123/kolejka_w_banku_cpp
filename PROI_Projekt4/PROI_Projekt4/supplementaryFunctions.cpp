#include "mainHeader.h"
#include <iterator>
using namespace std;

void removeAllSpaces(std::string& s)
{
	s.erase(remove(s.begin(), s.end(), ' '), s.end()); // removes all occurences of ' ' from string s
}

void removeEndSpaces(std::string& s)
{
	while (s[0] == ' ')
		s = s.substr(1);
	while (s[s.length() - 1] == ' ')
		s = s.substr(0, s.length() - 2);
}

bool compareStrings(std::string s1, std::string s2)
{
	int compare = s1.compare(s2);
	return (compare == 0);
}