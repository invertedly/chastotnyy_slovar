#include "word_frequency.h"
#include <functional>
#include <iostream>
#include <string>
#include <optional>

using namespace word_frequency;

namespace
{
	std::optional<std::string> get_word(std::istream& source)
	{
		std::string word;
		source >> word;

		if (word.empty())
		{
			return {  };
		}
		return {word  };
	}

	class Dict_map final : public Dict
	{
	public:
		Dict_map(std::istream& input);
		bool output(std::ostream& output) override;

		void destroy() override;
		Dict* copy() override;
		size_t get_count(const std::string& word) override;
		void set_count(const std::string& word, size_t count) override;
		void remove(const std::string& word) override;

	private:
		std::map<std::string, size_t> dict_;
	};

	class Dict_vector final : public Dict
	{
	public:
		Dict_vector(std::istream& input);	
		bool output(std::ostream& output) override;

		void destroy() override;
		Dict* copy() override;
		size_t get_count(const std::string& word) override;
		void set_count(const std::string& word, size_t count) override;
		void remove(const std::string& word) override;

	private:
		std::vector<record> dict_;
	};

	class Dict_list final : public Dict
	{
	public:
		Dict_list(std::istream& input);
		bool output(std::ostream& output) override;

		void destroy() override;
		Dict* copy() override;
		size_t get_count(const std::string& word) override;
		void set_count(const std::string& word, size_t count) override;
		void remove(const std::string& word) override;

	private:
		std::list<record> dict_;
	};
}

Dict* Dict::create(std::istream& input, const container type)
{
	switch (type)
	{
	case container::vector:
		return new Dict_vector(input);
	case container::list:
		return new Dict_list(input);
	case container::map:
		return new Dict_map(input);
	default:
		throw std::invalid_argument("invalid container type");
	}
}

Dict_map::Dict_map(std::istream& input)
{
	std::optional<std::string> word = get_word(input);
	while (word)
	{
		if (const auto it = dict_.find(*word); it != dict_.end())
		{
			it->second++;
		}
		else
		{
			dict_[*word] = 1;
		}
		word = get_word(input);
	}
}

bool Dict_map::output(std::ostream& output)
{
	return do_output(output, dict_);
}

void Dict_map::destroy()
{
	delete this;
}

Dict* Dict_map::copy()
{
	return new Dict_map(*this);
}

size_t Dict_map::get_count(const std::string& word)
{
	if (const auto it = dict_.find(word); it != dict_.end())
	{
		return it->second;
	}
	return 0;
}

void Dict_map::set_count(const std::string& word, const size_t count)
{
	dict_[word] = count;
}

void Dict_map::remove(const std::string& word)
{
	if (const auto it = dict_.find(word); it != dict_.end())
	{
		dict_.erase(it);
	}
}

Dict_vector::Dict_vector(std::istream& input)
{
	std::optional<std::string> word = get_word(input);
	while (word)
	{
		auto it = dict_.begin();
		for (; it != dict_.end(); it = next(it))
		{
			if (it->first == word)
			{
				it->second++;
				break;
			}
		}

		if (it == dict_.end())
		{
			dict_.push_back({ *word, 1 });
		}
		
		word = get_word(input);
	}
}

bool Dict_vector::output(std::ostream& output)
{
	return do_output(output, dict_);
}

void Dict_vector::destroy()
{
	delete this;
}

Dict* Dict_vector::copy()
{
	return new Dict_vector(*this);
}

size_t Dict_vector::get_count(const std::string& word)
{
	return;
}













