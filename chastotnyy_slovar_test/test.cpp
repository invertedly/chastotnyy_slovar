#include "pch.h"

#include "../chastotnyy-slovar/word_frequency.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace word_frequency;

Dict* fill_from_stream(std::istringstream& in, const container& type)
{
	Dict* dict = Dict::create(type);

	std::string word;

	while (in >> word)
	{
		dict->add_word(word);
	}

	return dict;
}

TEST(Frequency_dict, List) {
	std::istringstream in("a a a b b cde");

	Dict* dict = fill_from_stream(in, container::list);

	ASSERT_EQ(dict->get_count("a"), 3);
	ASSERT_EQ(dict->get_count("b"), 2);
	ASSERT_EQ(dict->get_count("cde"), 1);
	ASSERT_EQ(dict->get_count("hello"), 0);

	delete dict;
}

TEST(Frequency_dict, Map) {
	std::istringstream in("a a a b b cde");

	Dict* dict = fill_from_stream(in, container::map);

	ASSERT_EQ(dict->get_count("a"), 3);
	ASSERT_EQ(dict->get_count("b"), 2);
	ASSERT_EQ(dict->get_count("cde"), 1);
	ASSERT_EQ(dict->get_count("hello"), 0);

	delete dict;
}

TEST(Frequency_dict, Vector) {
	std::istringstream in("a a a b b cde");

	Dict* dict = fill_from_stream(in, container::vector);

	ASSERT_EQ(dict->get_count("a"), 3);
	ASSERT_EQ(dict->get_count("b"), 2);
	ASSERT_EQ(dict->get_count("cde"), 1);
	ASSERT_EQ(dict->get_count("hello"), 0);

	delete dict;
}