#pragma once
#include "../include/trie.h"
#include <vector>
#include <string>
#include <utility>

namespace Mistercomplete {

	class TestTrie {

	public:
		TestTrie();
		std::vector<std::pair<int, std::string>> get_all_entries(const Mistercomplete::Trie& trie);
		void get_all_entries_recursive(Mistercomplete::Node* node, std::vector<std::pair<int, std::string>>& results, std::string& current_word);

	};

} // end namespace Mistercomplete
