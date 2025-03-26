WARNFLAG := -Wall -Wextra -Wpedantic

# Library =====================================================================================================

mistercomplete.a: ./src/node/node.o ./src/trie/trie.o ./src/mistercomplete/mistercomplete.o
	@echo " - Archiving into a library"
	ar rcs ./lib/mistercomplete.a ./src/node/node.o ./src/trie/trie.o ./src/mistercomplete/mistercomplete.o

mistercomplete.o: ./src/mistercomplete/mistercomplete.cpp ./src/mistercomplete/mistercomplete.h
	@echo " - Compiling mistercomplete.cpp"
	g++ $(WARNFLAG) -c ./src/mistercomplete/mistercomplete.cpp -o ./src/mistercomplete/mistercomplete.o

trie.o: ./src/trie/trie.cpp ./src/trie/trie.h
	@echo " - Compiling trie.cpp"
	g++ $(WARNFLAG) -c ./src/trie/trie.cpp -o ./src/trie/trie.o

node.o: ./src/node/node.cpp ./src/node/node.h
	@echo " - Compiling node.cpp"
	g++ $(WARNFLAG) -c ./src/node/node.cpp -o ./src/node/node.o

# Test Classes =====================================================================================================

testtrie.o: ./test/testtrie.cpp ./test/testtrie.h
	@echo " - Compiling testtrie.cpp"
	g++ $(WARNFLAG) -c ./test/testtrie.cpp -o ./test/testtrie.o

# Testing =====================================================================================================

test: testing.out
	@echo " - Running tests"
	./test/testing.out

testing.out: ./test/testing.o ./lib/mistercomplete.a ./test/testtrie.o
	g++ -c ./test/testing.cpp -o ./test/testing.o
	g++ ./test/testing.o ./test/testtrie.o -static ./lib/mistercomplete.a -o ./test/testing.out

testing.o: ./test/testing.cpp
	g++ $(WARNFLAG) -c ./test/testing.cpp -o ./testing/testing.o

# Clean =====================================================================================================

clean:
	@echo " - Cleaning up the object files and the compiled library"
	rm -f ./lib/mistercomplete.a ./src/*/*.o ./test/*.out ./test/*.o
