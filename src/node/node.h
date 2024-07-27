#pragma once

struct Node {
        Node* parent;
        char character;
        bool ending;
        int id; // represents id of the entry, only if ending is true
        Node* children[26]; // [0]-a, [1]-b, ...
};
