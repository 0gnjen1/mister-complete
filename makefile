# WARNFLAG := -Wall -Werror -Wextra -Wpedantic

STATIC_OPTION := -static #Linux
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin) #MacOS
	STATIC_OPTION := ""
endif


# Library =====================================================================================================

mistercomplete.a: lib node.o trie.o mistercomplete.o
	@echo " - Archiving into a library"
	ar rcs ./lib/mistercomplete.a ./lib/node.o ./lib/trie.o ./lib/mistercomplete.o

mistercomplete.o: ./src/mistercomplete.cpp ./include/mistercomplete.h
	@echo " - Compiling mistercomplete.cpp"
	g++ $(WARNFLAG) -c ./src/mistercomplete.cpp -o ./lib/mistercomplete.o

trie.o: ./src/trie.cpp ./include/trie.h
	@echo " - Compiling trie.cpp"
	g++ $(WARNFLAG) -c ./src/trie.cpp -o ./lib/trie.o

node.o: ./src/node.cpp ./include/node.h
	@echo " - Compiling node.cpp"
	g++ $(WARNFLAG) -c ./src/node.cpp -o ./lib/node.o

lib:
	mkdir lib

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
	g++ ./test/testing.o ./test/testtrie.o $(STATIC_OPTION) ./lib/mistercomplete.a -o ./test/testing.out

testing.o: ./test/testing.cpp
	g++ $(WARNFLAG) -c ./test/testing.cpp -o ./testing/testing.o

# Clean =====================================================================================================

clean:
	@echo " - Cleaning up the object files and the compiled library"
	rm -f ./test/*.out ./test/*.o
	rm -rf ./lib/
