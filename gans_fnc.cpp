// #include <iostream>
#include "gans_fnc.h"

// constructor for a node
GraphNode::GraphNode(int idx) {
    index = idx;    // set the node's index
    val = 0;        // initialize the function value to 0
    t = 0;          // always initialize the time to 0

    // don't initialize the vector of connections here, we do that with another function
}

void GraphNode::add_connection(int target) {
    // add a conection to the vector
    connects.push_back(target);
}

void GraphNode::print_node(void) {
    std::cout << "GraphNode object with index ";
    std::cout << index << '\n';
    std::cout << "Connections: ";
    for (int i=0; i < connects.size(); i++) {
        std::cout << connects[i] << ' ';
    }
}

extern "C"{
    GraphNode create_node(int idx, std::vector<int> connects) {
        GraphNode node(idx);

        // create the vector of connections
        for (int i=0; i < connects.size(); i++) {
            node.connects[i] = connects[i];
        }
        // print some information for debugging
        node.print_node();

        return node;
    }
}