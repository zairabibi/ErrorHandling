#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <cstddef>
#include <string>
#include <stdexcept>

using namespace std;

namespace sdds
{
	template <typename T>
	class Collection
	{
		T* m_collections;
		string m_name;
		size_t m_size;
		
		void(*fptr)(const Collection<T>&, const T&);

	public:
		Collection<T>() {}

		Collection(const std::string& name)
		{
			m_name = name;
			m_size = 0;
			m_collections = nullptr;
			fptr = nullptr;
		}

		//deleted copy operations
		Collection(const Collection&) = delete;
		Collection<T>& operator=(const Collection&) = delete;

		~Collection<T>() {
			delete[] m_collections;
		}

		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			fptr = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool ifExists = false;

			if (m_collections)
			{
				//check if item already exists
				for (size_t i = 0; i < m_size; i++)
				{
					if (item.title() == m_collections[i].title())
					{
						ifExists = true;
						break;
					}
				}
			}
			else
			{
				//if no element exists
				m_collections = new T[m_size + 1];
				m_collections[m_size] = item;
				m_size++;

				if (fptr != nullptr)
					fptr(*this, item);

				return *this;
			}



			if (!ifExists)
			{
				//resizing the array
				T *temp = new T[m_size + 1];

				for (size_t i = 0; i < m_size; i++)
					temp[i] = m_collections[i];

				delete[] m_collections;

				m_collections = temp;

				m_collections[m_size] = item;
				m_size++;

				if (fptr != nullptr)
					fptr(*this, item);

			}

			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx < 0 || idx >= m_size)
			{
				throw std::out_of_range("Bad index [" + to_string(idx) + "]. Collection has [" + to_string(m_size) + "] items.");
			}

			return m_collections[idx];
		}

		T* operator[](const std::string& title) const
		{
			T* ret = nullptr;

			for (size_t i = 0; i < m_size; i++)
			{
				if (m_collections[i].title() == title)
					ret = &m_collections[i];
			}
			return ret;
		}

	};

	template <typename T>
	ostream& operator<<(ostream& os, const Collection<T>& col)
	{
		for (size_t i = 0; i < col.size(); i++)
			os << col[i];

		return os;
	}
}

#endif
