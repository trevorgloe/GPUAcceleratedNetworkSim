#ifndef GANS_FNC_H
#define GANS_FNC_H

#include <vector>
#include <iostream>

extern "C"{
class GraphNode {
    // a single node for the graph, containing the self-identifying information for the node
    public:
        int index;  // the nodes index/label
        float val;  // the value for the function at that node. Here we are simplifying the case to each node iterating a one-parameter function
        float t;    // each node tracks its own time independently
        std::vector<int> connects; // a list of all the connected nodes

        GraphNode(int idx); // constructor
        void add_connection(int target); // adds a single connection from the node to 'target'
        void print_node(void);  // prints out the basic info about the node
};
}

extern "C"{
    // GraphNode create_node(int idx, int connects[5]);

    GraphNode* create_node(int idx, int connects[5]);

    int get_index (GraphNode* node);

    int get_connects_size(GraphNode* node);

    void get_connects_vector(GraphNode* node, int out[]);
}
#endif