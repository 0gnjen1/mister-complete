#include "../trie/trie.h"
#include "../node/node.h"
#include <iostream>
#include <string>

Trie::Trie() {
	std::cout << "trie: created\n";
}

void Trie::insert(std::string entry)
{
	std::cout << "trie: inserted " << entry << "\n";
}

