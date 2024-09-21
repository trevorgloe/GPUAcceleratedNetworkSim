// header file for graph functions

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>
#include "gans_fnc.h"

class Graph {
    public: 
        // storage
        std::string name; // descriptive name for graph
        std::vector<GraphNode*> nodes; // all the nodes in a vector

        // methods
        Graph(char* namestr);

        // printing things
        void print(void); // prints all information about the graph
        void print_vals(void); // prints the values for all the nodes in a concise format

        // add node
        void addNode(GraphNode* node); // add a single node to the graph
        void initConnectsPtrs(void); // initialize the pointers linking nodes

        // propogate all nodes by a specfied time
        void propogateAllSerial(float delta_t);

    private:
        void validateConnections(void); // make sure no connection is specifying a node that doesn't exist
        bool checkNodeExistance(int idx); // quick function to check if a node exists
        int nodeIndex2ArrayIndex(int nodeIdx); // get the index in the nodes vector corresponding to a node with a specified index
};

// External python hooks
extern "C" {
    Graph* createGraph(char name[], int nodes[], int num_nodes, int connections[][2], int num_connects, int node_fnc_idx); // create a graph and return the pointer to that graph
    int testHooks(char* name, int namesize, int connections[][2]);
}

#endif