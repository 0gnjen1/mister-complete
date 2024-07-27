# MisterComplete
### Vision
MisterComplete is a small project that I am working on. The idea is to create a well documented and easily usable static C++ library. The initial plan is not to have a lot of functionality, but to provide a good developer experience and good interfaces for anyone using this library.

### Use case
The goal of the library is to serve as a text autocompletion tool. You set it up with data people could be possibly searching for (e.g. movie names), and then, as the user is typing, MisterComplete would make guesses on what the user might be looking for.

### How to use
``` C++
  #include <mistercomplete>
  
  int main(){

      Mistercomplete mc;
      mc.add_entry(1, "cat buffet");     // MisterComplete takes an id and a string
      mc.add_entry(2, "catzilla");
      mc.add_entry(3, "breaking bad")
      mc.suggest("ca");                  // And MisterComplete would now return a vector<pair<int, string>>
                                         // that represents the autocompleted text
  }
```
