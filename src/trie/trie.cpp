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
		if(current_node->children[char_index] == nullptr) return; 		// The word is not present in the trie
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

Node* Trie::get_node_by_prefix(const std::string& prefix)
{
	Node* current_node = root;
	for(int i=0; i<prefix.size(); i++)
	{
		int char_index = (int)prefix[i]-97;
		if(current_node->children[char_index] == nullptr) return nullptr;	// The prefix is not present in the trie
		current_node = current_node->children[char_index];
	}
	return current_node;
}

std::vector<std::pair<int, std::string>> Trie::get_all_from_node(Node* node)
{
	std::vector<std::pair<int, std::string>> results;
	std::string current_word;
	get_all_from_node_recursive(node, results, current_word);
	return results;
}

void Trie::get_all_from_node_recursive(Node* node, std::vector<std::pair<int, std::string>>& results, std::string& current_word)
{
	if(node->ending)
	{
		results.push_back(make_pair(node->id, current_word));
	}
	for(int i=0; i<26; i++)
	{
		if(node->children[i] == nullptr) continue;
		current_word += (char)((int)'a'+ i);
		get_all_from_node_recursive(node->children[i], results, current_word);
		current_word.pop_back();
	}
	return;
}

std::vector<std::pair<int, std::string>> Trie::autocomplete(const std::string& prefix)
{
	Node* prefix_end = get_node_by_prefix(prefix);
	std::vector<std::pair<int, std::string>> results;
	if(prefix_end == nullptr) return results;
	results = get_all_from_node(prefix_end);
	for(auto& result : results)
	{
		result.second = prefix + result.second;
	}
	return results;
}