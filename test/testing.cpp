#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "../include/completer.h"

#include "../include/trie.h"
#include "./testtrie.h"

int main(){

	Mistercomplete::Trie tr;

	tr.remove("");
	tr.remove("a");
	tr.remove("aaaaaa"); //6a
	tr.remove("aaaaaaa"); //7a

	std::vector<std::string> searches;
	searches.push_back("");
	searches.push_back("a");
	searches.push_back("aaaaa"); //5a
	searches.push_back("aaaaaa"); //6a
	searches.push_back("aaaaaaa"); //7a

	std::cout << "What Trie says:\n";
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

	std::cout << "What TestTrie says:\n";
	Mistercomplete::TestTrie ttr;
	auto everything = ttr.get_all_entries(tr);
	for(const auto& path : everything)
	{
		std::cout << " - id: " << path.first << " value: " << path.second << '\n';
	}

	tr.insert(1, "a");
	tr.insert(2, "aa");
	tr.insert(3, "aaa");
	tr.insert(4, "aaaa");
	tr.insert(5, "aaaaa");
	tr.insert(6, "aaaaaa");
	std::cout << "AFTER INSERTION ----------- \n";

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

	tr.remove("");
	tr.remove("a");
	tr.remove("aaaaaa"); //6a
	tr.remove("aaaaaaa"); //7a
	std::cout << "AFTER REMOVAL ----------- \n";
	
	std::cout << "What Trie says:\n";
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

	std::cout << "What TestTrie says:\n";
	everything = ttr.get_all_entries(tr);
	for(const auto& path : everything)
	{
		std::cout << " - id: " << path.first << " value: " << path.second << '\n';
	}
	
}
