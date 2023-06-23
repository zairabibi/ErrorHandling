#include <cstddef>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		if (filename) {
			
			ifstream file(filename);
			size_t index = 0;

			try 
			{
				if (file)
				{
					do {
						string line;

						getline(file, line, '\n');

						stringstream ss(line);
						ss >> m_badWords[index];
						ss >> m_goodWords[index];

						index++;
					} while (file);
				}
				else
					throw std::string("** EXCEPTION: Bad file name!\n");
			}
			catch (const char* message)
			{
				cerr << message;
			}

		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (m_badWords[i].empty() || m_goodWords[i].empty())
				return;

			size_t found = 0;

			while ((found = text.find(m_badWords[i])) != string::npos)
			{
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
				m_cntReplacements[i] += 1;
			}
		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		if (m_badWords[0].empty())
			return;

		else
			cout << "Spellchecker Statistics\n";

		for (int i = 0; i < 6; i++)
		{
			if (!(m_badWords[i].empty()))
				out << setw(15) << setfill(' ') << right << m_badWords[i] << ": " << m_cntReplacements[i] << " replacements" << endl;
		}

	}

}