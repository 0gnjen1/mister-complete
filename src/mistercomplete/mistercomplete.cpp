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
	std::cout << "mistercomplete: added entry\n";
}

std::vector<std::pair<int, std::string>> suggest(std::string text)
{
	std::cout << "mistercomplete: returning suggestions\n";
	std::vector<std::pair<int, std::string>> suggestions (2, std::make_pair(5, "mock answer"));
	return suggestions;
}

