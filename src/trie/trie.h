#pragma once
#include <string>
#include "../node/node.h"

class Trie {

public:
        Trie();
	void insert(const int id, const std::string& entry);
        void remove(const std::string& entry);

private:
        Node* root;

friend class TestTrie;

};
