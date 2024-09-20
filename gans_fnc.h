#ifndef GANS_FNC_H
#define GANS_FNC_H

#include <vector>
#include <iostream>

enum node_fnc {
    SUM_NODE_VALS_THRESHOLD, // sum values of connected nodes and see if its above a threshold
    PROBABILITY
};

extern "C"{
class GraphNode {
    // a single node for the graph, containing the self-identifying information for the node
    public:
        int index;  // the nodes index/label
        float val;  // the value for the function at that node. Here we are simplifying the case to each node iterating a one-parameter function
        float t;    // each node tracks its own time independently
        std::vector<int> connects; // a list of all the connected nodes
        node_fnc fnc_type; // which function will the node use to propogate "val"
        std::vector<GraphNode*>connects_ptrs; // vector of pointers to the nodes that this node is connected to, so it can query the values from those nodes

        GraphNode(int idx, int fnc_idx); // constructor
        void add_connection(int target); // adds a single connection from the node to 'target'
        void print_node(void);  // prints out the basic info about the node
        void propogate(float delta_t); // propogates the val forward in time by delta t
        void init_connect_ptrs(GraphNode* connects[], int num_ptrs);
};
}

extern "C"{
    // GraphNode create_node(int idx, int connects[5]);

    GraphNode* create_node(int idx, int connects[], int num_connects);

    int get_index (GraphNode* node);

    int get_connects_size(GraphNode* node);

    void get_connects_vector(GraphNode* node, int out[]);

    void extern_propogate_node(GraphNode* node, float delta_t);

    float get_val(GraphNode* node);
}
#endif