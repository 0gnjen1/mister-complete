#pragma once
#include <string>
#include "../node/node.h"

class Trie {

public:
        Trie();
        Node* children[26] = { nullptr };
	void insert(std::string entry);	

private:

};
