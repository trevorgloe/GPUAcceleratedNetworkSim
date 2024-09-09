// #include <iostream>
#include "gans_fnc.h"

extern "C"{
// constructor for a node
GraphNode::GraphNode(int idx, int fnc_idx) {
    index = idx;    // set the node's index
    val = 0;        // initialize the function value to 0
    t = 0;          // always initialize the time to 0
    fnc_type = static_cast<node_fnc>(fnc_idx);

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

void GraphNode::propogate(float delta_t){
    // this function will call whatever propogate function is set by the enum fnc_type and propogate the value forward
    if (fnc_type == SUM_NODE_VALS_THRESHOLD) {
        // sum the values of the different nodes its connected to
        float sum = 0;
        for (int i = 0; i < connects.size(); i++){
            sum = sum + 1.0; // just do this for now, for testing
        }
        float threshold = 3.5; // arbitrary threshold for now
        
        if (sum > threshold) {
            val = 1.0;
        } else {
            val = 0.0;
        }
    }

    t = t + delta_t;
}
}

extern "C"{

    GraphNode* create_node(int idx, int connects[], int num_connects){
        // create a node object with the index idx and connects given by the input array. num_connects is the length of the input array
        GraphNode * node = new GraphNode(1, 1);

        // node.print_node();
        for (int i = 0; i < num_connects; i++) {
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

    void extern_propogate_node(GraphNode* node, float delta_t){
        // propogate the node referenced by the pointer node forward by delta_t
        node->propogate(delta_t);
    }

    float get_val(GraphNode* node){
        // return the val for the node referenced by the pointer node
        return node->val;
    }
}