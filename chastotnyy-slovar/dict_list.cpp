#include "dict_list.h"

using namespace word_frequency;

void Dict_list::add_word(const std::string& word)
{
	auto it = find_if(dict_.begin(), dict_.end(), [word](const std::pair<std::string, size_t> rec) { return rec.first == word; });
	if (it == dict_.end())
	{
		dict_.push_back({ word, 1 });
		return;
	}
	it->second++;
}

size_t Dict_list::get_count(const std::string& word)
{
	const auto it = find_if(dict_.begin(), dict_.end(), [word](const std::pair<std::string, size_t> rec) { return rec.first == word; });
	if (it == dict_.end())
	{
		return 0;
	}
	return it->second;
}

