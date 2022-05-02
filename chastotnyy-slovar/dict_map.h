#pragma once

#include "word_frequency.h"
#include <map>

namespace word_frequency
{
	class Dict_map final : public word_frequency::Dict
	{
	public:
		void add_word(const std::string& word) override;
		size_t get_count(const std::string& word) override;
		~Dict_map() override = default;
	private:
		std::map<std::string, size_t> dict_;
	};
}
