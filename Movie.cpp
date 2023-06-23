#include <sstream>
#include <iomanip>
#include "Movie.h"

namespace sdds
{
	Movie::Movie()
	{
		m_title = "";
		m_desc = "";
		m_year = 0;
	}

	Movie::Movie(const std::string& strMovie)
	{
		stringstream ss(strMovie);
		string token, token2;

		getline(ss, token, ',');
		token2 = removeSpaces(token);
		m_title = token2;

		getline(ss, token, ',');
		token2 = removeSpaces(token);
		m_year = stoi(token2);

		getline(ss, token);
		token2 = removeSpaces(token);
		m_desc = token2;
	}

	const string& Movie::title() const
	{
		return m_title;
	}

	ostream& operator<<(ostream& os, const Movie& movie)
	{
		os << setw(40) << setfill(' ') << right << movie.title();
		os << " | ";

		os << setw(4) << setfill(' ') << movie.m_year;
		os << " | ";

		os << movie.m_desc << endl;

		return os;

	}

	string Movie::removeSpaces(std::string& str) const
	{
		std::string trimmed = "";

		auto start = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');

		//trim only if string isn't empty
		if (end >= start)
			trimmed = str.substr(start, (end - start) + 1);

		return trimmed;
	}
}