#include <cstddef>
#include <sstream>
#include <iomanip> //input output manipulation

#include "Book.h"

namespace sdds {

	string Book::removeSpaces(std::string& str) const
	{
		std::string trimmed = "";

		auto start = str.find_first_not_of(' ');
		auto end = str.find_last_not_of(' ');

		//trim only if string isn't empty
		if (end >= start)
			trimmed = str.substr(start, (end - start) + 1);

		return trimmed;
	}

	Book::Book(){}

	Book::Book(const std::string& strBook)
	{
		//converting our string into a stream
		stringstream ss(strBook);
		string token, token2;

		//getline functions receives 3 things
		//1. stream 
		//2. token/variable in which we need to store
		//3. delimiter
		getline(ss, token, ',');
		m_author = removeSpaces(token);

		getline(ss, token, ',');
		m_title = removeSpaces(token);

		getline(ss, token, ',');
		token2 = removeSpaces(token);
		m_country = token2;

		getline(ss, token, ',');
		token2 = removeSpaces(token);
		m_price = stod(token2); //string to double

		getline(ss, token, ',');
		token2 = removeSpaces(token);
		m_year = stoi(token2); //string to integer

		getline(ss, token); //by default, the delimiter is '\n'
		token2 = removeSpaces(token);
		m_desc = token2;
	}

	const string& Book::title() const { return m_title; }
	const string& Book::country() const { return m_country; }
	const size_t& Book::year() const { return m_year; }
	double& Book::price() { return m_price; }

	ostream& operator << (ostream& ostr, const Book& book)
	{
		ostr << setw(20) << setfill(' ') << right << book.m_author;
		ostr << " | ";

		//setwidth
		ostr << setw(22) << setfill(' ') << right << book.title();
		ostr << " | ";

		ostr << setw(5) << setfill(' ') << right << book.country();
		ostr << " | ";

		ostr << setw(4) << setfill(' ') << right << book.year();
		ostr << " | ";

		ostr << setw(6) << setprecision(2) << std::fixed << setfill(' ') << right << book.m_price;
		ostr << " | ";

		ostr << left << book.m_desc << endl;

		return ostr;
	}
}