#include "dict_map.h"

using namespace word_frequency;

void Dict_map::add_word(const std::string& word)
{
	const auto it = dict_.find(word);
	if (it == dict_.end())
	{
		dict_[word] = 1;
		return;
	}
	it->second++;
}

size_t Dict_map::get_count(const std::string& word)
{
	const auto it = dict_.find(word);
	if (it == dict_.end())
	{
		return 0;
	}
	return it->second;
}
