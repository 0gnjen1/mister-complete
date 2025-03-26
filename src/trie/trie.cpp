#include "../trie/trie.h"
#include "../node/node.h"
#include <iostream>
#include <string>
#include <vector>

Trie::Trie() {
	root = new Node();
}

void Trie::insert(const int id, const std::string& entry)
{
	Node* current_node = root;
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
		}
		if(i == (entry.size()-1))
		{
			next_node->ending = true;
			next_node->id = id;
			return;
		}
		current_node = next_node;
	}
}

void Trie::remove(const std::string& entry)
{
	std::vector<Node*> node_path;
	Node* current_node = root;
	for(int i=0; i<entry.size(); i++)
	{
		int char_index = (int)entry[i]-97;
		if(current_node->children[char_index] == nullptr) return; 	// The word is not present in the trie
		current_node = current_node->children[char_index];
		node_path.push_back(current_node);
	}
	if(current_node->child_count());
	{
		current_node->id = -1;
		current_node->ending = false;
		return;
	}
	for(int i=entry.size(); i>=0; i--)
	{
		if(node_path[i]->child_count()) return;
		int char_index = (int)entry[i]-97;
		node_path[i]->parent->children[char_index] = nullptr;
		delete node_path[i];
	}

}