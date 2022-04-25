#pragma once

#include "word_frequency.h"
#include <list>

class Dict_list final : public word_frequency::Dict
{
public:
	void add_word(const std::string& word) override;
	size_t get_count(const std::string& word) override;
	~Dict_list() override = default;
private:
	std::list<word_frequency::record> dict_;
};