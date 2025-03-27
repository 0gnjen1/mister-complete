#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "../src/mistercomplete/mistercomplete.h"

#include "../src/trie/trie.h"
#include "./testtrie.h"

int main(){

	Trie tr;
	tr.insert(1, "aaa");
	tr.insert(2, "aa");
	tr.insert(3, "aab");
	tr.insert(4, "aaa");
	tr.insert(5, "baa");
	tr.insert(6, "bbb");
	tr.insert(7, "bbbx");
	tr.insert(8, "xyz");
	tr.insert(9, "aaa");

	std::vector<std::string> searches;
	searches.push_back("");
	searches.push_back("a");
	searches.push_back("aaaaa");
	searches.push_back("b");
	searches.push_back("bb");

	for(const std::string& search : searches)
	{
		std::cout << "autocomplete for search '" << search << "':\n";
		std::vector<std::pair<int, std::string>> results;
		results = tr.autocomplete(search);
		for(const auto& result : results)
		{
			std::cout << " - id: " << result.first << " value: " << result.second << '\n';
		}
	}

	std::cout << "AFTER REMOVAL\n";
	tr.remove("");
	tr.remove("bbb");
	tr.remove("ijk");
	tr.remove("aa");

	for(const std::string& search : searches)
	{
		std::vector<std::pair<int, std::string>> results;
		results = tr.autocomplete(search);
		std::cout << "autocomplete for search '" << search << "':\n";
		for(const auto& result : results)
		{
			std::cout << " - id: " << result.first << " value: " << result.second << '\n';
		}
	}

}

