#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "../include/completer.h"

#include "../include/trie.h"
#include "./testtrie.h"

int main(){

	Completer mc;
	mc.add_entry(1, "a");
	mc.add_entry(2, "aa");
	mc.add_entry(3, "xyz");
	mc.add_entry(4, "aaaa");
	mc.add_entry(5, "aaaaa");
	mc.add_entry(6, "aaaaaa");

	std::vector<std::string> searches;
	searches.push_back("");
	searches.push_back("a");
	searches.push_back("aaaaa");

	for(const std::string& search : searches)
	{
		std::cout << "autocomplete for search '" << search << "':\n";
		std::vector<std::pair<int, std::string>> results;
		results = mc.suggest(search);
		for(const auto& result : results)
		{
			std::cout << " - id: " << result.first << " value: " << result.second << '\n';
		}
	}

	/*
	std::cout << "AFTER REMOVAL\n";
	tr.remove("");
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
	*/

}

