#pragma once

#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <map>
#include <vector>
#include <optional>

namespace word_frequency
{
	using record = std::pair<std::string, size_t>;

	enum class container
	{
		map, vector, list
	};

	class Dict
	{
	public:
		static Dict* create(std::istream& input, container type);
		virtual bool output(std::ostream& output) = 0;
		virtual size_t get_count(const std::string& word) = 0;
		virtual void set_count(const std::string& word, size_t count) = 0;
		virtual void remove(const std::string& word) = 0;
		virtual void destroy() = 0;
		virtual Dict* copy() = 0;

	protected:
		Dict() = default;
		Dict(const Dict&) = default;
		~Dict() = default;  // prohibits using operator delete from client side

		template <typename T>
		bool do_output(std::ostream& output, T& dict)
		{
			for (const auto& record : dict)
			{
				output << record.first << " - " << record.second << std::endl;
			}
			return output.fail();
		}
	};
}