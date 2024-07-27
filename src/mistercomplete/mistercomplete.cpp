#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../trie/trie.h"
#include "mistercomplete.h"

Mistercomplete::Mistercomplete()
{
	std::cout << "mistercomplete: created\n";
}

void Mistercomplete::add_entry(int id, std::string text)
{
	std::cout << "mistercomplete: added entry " << text << "\n";
	trie.insert(text);
}

[[nodiscard]] std::vector<std::pair<int, std::string>> Mistercomplete::suggest(std::string text)
{
	std::cout << "mistercomplete: returning suggestions " << text << "\n";
	std::vector<std::pair<int, std::string>> suggestions (2, std::make_pair(5, "mock answer"));
	return suggestions;
}

