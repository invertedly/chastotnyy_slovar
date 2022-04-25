#include "dict_vec.h"

using namespace word_frequency;

void Dict_vector::add_word(const std::string& word)
{
	const auto it = find_if(dict_.begin(), dict_.end(), [word](const std::pair<std::string, size_t> rec) { return rec.first == word; });
	if (it == dict_.end())
	{
		dict_.push_back({ word, 1 });
		return;
	}
	it->second++;
}

size_t Dict_vector::get_count(const std::string& word)
{
	const auto it = find_if(dict_.begin(), dict_.end(), [word](const std::pair<std::string, size_t>& rec) { return rec.first == word; });
	if (it == dict_.end())
	{
		return 0;
	}
	return it->second;
}
