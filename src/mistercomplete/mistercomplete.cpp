#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../trie/trie.h"
#include "mistercomplete.h"

Mistercomplete::Mistercomplete() {}

void Mistercomplete::add_entry(const int id, const std::string& text)
{
	trie.insert(id, text);
}

[[nodiscard]] std::vector<std::pair<int, std::string>> Mistercomplete::suggest(const std::string& text)
{
	std::vector<std::pair<int, std::string>> suggestions (2, std::make_pair(5, "mock answer"));
	return suggestions;
}

