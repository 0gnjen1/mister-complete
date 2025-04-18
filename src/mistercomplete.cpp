#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../include/trie.h"
#include "../include/mistercomplete.h"

Mistercomplete::Mistercomplete() {}

void Mistercomplete::add_entry(const int id, const std::string& text)
{
	trie.insert(id, text);
}

[[nodiscard]] std::vector<std::pair<int, std::string>> Mistercomplete::suggest(const std::string& text)
{
	return trie.autocomplete(text);
}

