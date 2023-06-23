#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

namespace sdds
{
	class Movie
	{
		string m_title;
		size_t m_year;
		string m_desc;

		//function that removes all trailing and leading spaces in a token
		string removeSpaces(std::string& str) const;
	public:
		Movie();
		Movie(const std::string& strMovie);

		const string& title() const;

		friend ostream& operator<<(ostream& os, const Movie&);

		template <class T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}

	};


}

#endif#pragma once
