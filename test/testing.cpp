#include <vector>
#include <utility>
#include <string>
#include "../src/mistercomplete/mistercomplete.h"

int main(){

	Mistercomplete mc;
	mc.add_entry(1, "test 1");
	std::vector<std::pair<int, std::string>> suggestions;
	suggestions = mc.suggest("test 2");
	mc.suggest("test 3");

}

