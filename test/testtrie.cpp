#include <string>
#include <vector>
#include <utility>
#include <stack>
#include <iostream>
#include "../include/trie.h"
#include "./testtrie.h"

namespace Mistercomplete {

	TestTrie::TestTrie(){}

	std::vector<std::pair<int, std::string>> TestTrie::get_all_entries(const Mistercomplete::Trie& trie)
	{
		std::vector<std::pair<int, std::string>> all_entries;
		std::string current_word;
		get_all_entries_recursive(trie.root, all_entries, current_word);
		return all_entries;
	}


	void TestTrie::get_all_entries_recursive(Mistercomplete::Node* node, std::vector<std::pair<int, std::string>>& results, std::string& current_word){
		if(node->ending || !node->child_count())
		{
			if(current_word.size() > 0)
			{
				results.push_back(make_pair(node->id, current_word));
			}
		}
		for(int i=0; i<26; i++)
		{
			if(node->children[i] == nullptr) continue;
			current_word += (char)((int)'a'+ i);
			get_all_entries_recursive(node->children[i], results, current_word);
			current_word.pop_back();
		}
		return;
	}

} // end namespace Mistercomplete
