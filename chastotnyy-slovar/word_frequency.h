#pragma once

#include <string>
#include <optional>
#include <string>

namespace word_frequency
{
	class invalid_argument_exception final : public std::exception
	{
	public:
		explicit invalid_argument_exception(const std::string& message) : m_msg_(message) { }
		const char* what() const noexcept override { return m_msg_.c_str(); }
	private:
		const std::string m_msg_;
	};

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