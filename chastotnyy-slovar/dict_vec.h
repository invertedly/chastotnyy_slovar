#pragma once

#include "word_frequency.h"
#include <vector>

class Dict_vector final : public word_frequency::Dict
{
public:
	void add_word(const std::string& word) override;
	size_t get_count(const std::string& word) override;
	~Dict_vector() override = default;
private:
	std::vector<word_frequency::record> dict_;
};