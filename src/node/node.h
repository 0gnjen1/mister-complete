#pragma once

struct Node {
        Node* parent;
        char character;
        bool ending = false;
        int id = -1; 				// represents id of the entry, only if ending is true
        Node* children[26] = { nullptr }; 	// [0]-a, [1]-b, ...
};
