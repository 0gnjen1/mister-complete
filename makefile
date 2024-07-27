WARNFLAG = -Wall -Wextra -Wpedantic

mistercomplete.a: ./src/trie/trie.o ./src/mistercomplete/mistercomplete.o
	@echo " - Archiving into a library"
	ar rcs ./lib/mistercomplete.a ./src/trie/trie.o ./src/mistercomplete/mistercomplete.o

mistercomplete.o: ./src/mistercomplete/mistercomplete.cpp ./src/mistercomplete/mistercomplete.h
	@echo " - Compiling mistercomplete.cpp"
	g++ $(WARNFLAG) -c ./src/mistercomplete/mistercomplete.cpp -o ./src/mistercomplete/mistercomplete.o

trie.o: ./src/trie/trie.cpp ./src/trie/trie.h
	@echo " - Compiling trie.cpp"
	g++ $(WARNFLAG) -c ./src/trie/trie.cpp -o ./src/trie/trie.o

test: ./lib/mistercomplete.a
	g++ -c ./test/testing.cpp -o ./test/testing.o
	g++ ./test/testing.o -static ./lib/mistercomplete.a -o ./test/testing.out
	@echo " - Running tests"
	./test/testing.out

clean:
	@echo " - Cleaning up the object files and the compiled library"
	rm -f ./lib/mistercomplete.a ./src/*/*.o ./test/*.out ./test/*.o
