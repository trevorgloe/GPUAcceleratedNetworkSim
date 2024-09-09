// #include <iostream>
#include "gans_fnc.h"

extern "C"{
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
}

extern "C"{
    // GraphNode create_node(int idx, int connects[5]) {
    //     GraphNode node(idx);

    //     node.print_node();
    //     // create the vector of connections
    //     for (int i=0; i < 5; i++) {
    //         // node.connects.push_back(connects[i]);
    //         node.add_connection(connects[i]);
    //     }
    //     // print some information for debugging
    //     node.print_node();

    //     return node;
    // }

    GraphNode* create_node(int idx, int connects[5]){

        GraphNode * node = new GraphNode(1);

        // node.print_node();
        for (int i = 0; i < 5; i++) {
            node->add_connection(connects[i]);
            // std::cout << array[i] << ' ';
        }
        // node.add_connection(array[1]);

        node->print_node();
        return node;
    }

    int get_index (GraphNode* node){
        // get the index for the node referenced by the pointer passed into the function
        return node->index;
    }

    int get_connects_size(GraphNode* node){
        // get the size of the connections vector for the node referenced by the pointer node
        return node->connects.size();
    }

    void get_connects_vector(GraphNode* node, int out[]){
        // return the full vector of connects for the node referenced by the pointer node
        int sz = node->connects.size();
        // int out[sz] = new int[sz];
        
        // iterate through the elements
        for (int i=0; i < sz; i++){
            out[i] = node->connects[i];
        }
        // return a pointer to the array
        // return out;
    }
}