#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "../src/mistercomplete/mistercomplete.h"

#include "../src/trie/trie.h"
#include "./testtrie.h"

int main(){

	Trie tr;
	tr.insert(1, "aa");
	tr.insert(2, "a");
	tr.insert(3, "ab");
	tr.insert(4, "aaab");
	tr.insert(5, "xzy");
	
	tr.remove("aa");
	tr.remove("gg");
	tr.remove("");
	tr.remove("xzy");

	TestTrie ttr;
	std::vector<std::pair<int, std::string>> results;
	results = ttr.get_all_entries(tr);
	std::cout << "found in trie:\n";
	for(const auto& result : results)
	{
		std::cout << " - id: " << result.first << " value: " << result.second << '\n';
	}

}

