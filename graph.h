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
        void print(void);

        // add node
        void addNode(GraphNode* node); // add a single node to the graph
        void initConnectsPtrs(void); // initialize the pointers linking nodes

    private:
        void validateConnections(void); // make sure no connection is specifying a node that doesn't exist
        bool checkNodeExistance(int idx); // quick function to check if a node exists
        int nodeIndex2ArrayIndex(int nodeIdx); // get the index in the nodes vector corresponding to a node with a specified index
};

#endif