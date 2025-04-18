#pragma once

class Node {

public:
        Node* parent;
        char character;
        bool ending = false;
        int id = -1; 				// Represents the ID of the entry. Set to a positive value only if ending is true.
        Node* children[26] = { nullptr }; 	// [0]-a, [1]-b, ...

        int child_count();
        
};
