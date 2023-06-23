#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


namespace sdds
{
	class Book {
		string m_author{}; //'\0'
		string m_title{};
		string m_country{};
		size_t m_year{}; //0
		double m_price{};
		string m_desc{};

		//private method that removes all trailing and leading spaces in a token
		string removeSpaces(std::string&) const;

	public:
		Book(); //default constructor
		const std::string& title() const; //returns the title of the book
		const std::string& country() const; //returns the publication country
		const size_t& year() const; //returns the publication year
		double& price(); //returns the price by reference
		Book(const std::string& strBook); //custom constructor
		friend ostream& operator<<(ostream&, const Book&); //friend helper

		//template function
		template <class T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_desc);
		}


	};


}

#endif#pragma once
