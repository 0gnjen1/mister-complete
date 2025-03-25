#pragma once
#include "../src/trie/trie.h"
#include <vector>
#include <string>
#include <utility>

class TestTrie {

public:
	TestTrie();
	std::vector<std::pair<int, std::string>> get_all_entries(const Trie& trie);
	void get_all_entries_recursive(Node* node, std::vector<std::pair<int, std::string>>& results, std::string& current);

};
