#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


namespace sdds
{
	class SpellChecker {
		string m_badWords[6];
		string m_goodWords[6];
		int m_cntReplacements[6] = { 0 };

	public:

		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;

	};


}

#endif#pragma once
