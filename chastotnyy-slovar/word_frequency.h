#pragma once

#include <string>
#include <optional>
#include <string>

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
		static Dict* create(container type);

		virtual void add_word(const std::string& word) = 0;
		virtual size_t get_count(const std::string& word) = 0;

		virtual ~Dict() = default;
	};
}