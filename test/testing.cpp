#include <vector>
#include <utility>
#include <string>
#include "../src/mistercomplete/mistercomplete.h"

#include "../src/trie/trie.h"
#include "./testtrie.h"

int main(){

	Trie tr;
	tr.insert(1, "aaaaa");
	tr.insert(2, "a");
	tr.insert(3, "ab");
	tr.insert(4, "aaab");
	tr.insert(4, "xzy");
	
	TestTrie ttr;
	ttr.get_all_entries(tr);
	

}

