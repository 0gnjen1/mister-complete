#pragma once
#include <vector>
#include <string>
#include <utility>
#include "trie.h"

class mistercomplete {

public:
        mistercomplete();
        void add_entry(int id, std::string text);
        std::vector<std::pair<int, std::string>> suggest(std::string text);

private:
        Trie trie;

};
