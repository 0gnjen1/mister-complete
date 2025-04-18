#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../include/trie.h"
#include "../include/completer.h"

Completer::Completer() {}

void Completer::add_entry(const int id, const std::string& text)
{
	trie.insert(id, text);
}

[[nodiscard]] std::vector<std::pair<int, std::string>> Completer::suggest(const std::string& text)
{
	return trie.autocomplete(text);
}

