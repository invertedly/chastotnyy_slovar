#include "word_frequency.h"

#include <memory>

#include "dict_map.h"
#include "dict_list.h"
#include "dict_vec.h"

word_frequency::Dict* word_frequency::Dict::create(const container type)
{
	switch (type)
	{
	case container::map: return new Dict_map();
	case container::list: return new Dict_list();
	case container::vector: return new Dict_vector();
	default: throw word_frequency::invalid_argument_exception("wrong container type");
	}
}
