#pragma once
#include <vector>
#include <string>
#include <utility>
#include "../trie/trie.h"

class Mistercomplete {

public:
        Mistercomplete();
        void add_entry(int id, std::string text);
        std::vector<std::pair<int, std::string>> suggest(std::string text);

private:
        Trie trie;

};
