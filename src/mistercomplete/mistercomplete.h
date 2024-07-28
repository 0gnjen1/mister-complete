#pragma once
#include <vector>
#include <string>
#include <utility>
#include "../trie/trie.h"

class Mistercomplete {

public:
        Mistercomplete();
        void add_entry(const int id, const std::string& text);
        [[nodiscard]] std::vector<std::pair<int, std::string>> suggest(const std::string& text);

private:
        Trie trie;

};
