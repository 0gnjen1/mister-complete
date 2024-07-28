#include "../trie/trie.h"
#include "../node/node.h"
#include <iostream>
#include <string>

Trie::Trie() {}

void Trie::insert(const int id, const std::string& entry)
{
	std::cout << "trie: inserted " << entry << "\n";
	
	Node* current_node = &node;
	for(int i=0; i<entry.size(); i++)
	{
		int child_index = ((int)entry[i])-97;
		Node* next_node = current_node->children[child_index];
		if(!current_node->children[child_index])
		{
			current_node->children[child_index] = new Node();
			next_node = current_node->children[child_index];
			next_node->parent = current_node;
			next_node->character = entry[i];
			if(i == (entry.size()-1))
			{
				next_node->ending = true;
				next_node->id = id;
			}
		}
		current_node = next_node;
	}
}

