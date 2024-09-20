// file for the graph functions and graph object definitions

#include "graph.h"

// constructor
Graph::Graph(char* namestr) {
    // set the name for the graph
    name = namestr;
}

// print diognostic information for debugging
void Graph::print(void) {
    // print some information about the graph for debugging purposes
    std::cout << "A graph named: " << name << "\n";
    std::cout << "With nodes: " << "\n";
    // loop through all the nodes and print their info
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].print_node();
    }
}

// function to add a node to the graph
void Graph::addNode(GraphNode node) {
    // just throw that node onto the end of the nodes vector
    nodes.push_back(node);
    validateConnections();
}

// Validate all the connections to make sure nothing is wrong
void Graph::validateConnections(void) {
    // loop through all nodes
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << "Checking node : " << nodes[i].index << "\n";
        // now loop through the nodes connections 
        for (int j = 0; j < nodes[i].connects.size(); j++) {
            // 
            if (!checkNodeExistance(nodes[i].connects[j])) {
                // add 1 to the indices when you display to make it more readable
                std::cout << "WARNING: node " << nodes[i].index << " has a connection to node " << nodes[i].connects[j] << " which does not exist \n";
            }
        }
        // std::cout << "Checked node: "<< nodes[i].index << "\n";
    }
}

// check if a node of a certain index exists
bool Graph::checkNodeExistance(int idx) {
    // loop through all nodes until you find the one with the right index
    bool exists = false;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].index == idx) {
            exists = true;
        }
    }

    return exists;
}

// initialize all the pointers linking connected nodes so they can see each others values
void Graph::initConnectsPtrs(void) {
    // validate that all the connections are ok before trying to get pointers, otherwise 
    // we will probably get a null pointer
    std::cout << "Validating connections... \n";
    validateConnections();
    std::cout << "Generating connection pointers\n";
    // first loop through all nodes
    for (int i = 0; i < nodes.size(); i++) {
        // create an array of GraphNode pointers
        int num_ptrs = nodes[i].connects.size();
        GraphNode* connect_ptrs[num_ptrs];
        // loop through connections
        for (int j = 0; j < nodes[i].connects.size(); j++) {
            // get the array index for the node connected
            int arrayIdx = nodeIndex2ArrayIndex(nodes[i].connects[j]);
            GraphNode connection = nodes[arrayIdx];
            connect_ptrs[j] = &connection;
        }
        // give that array of pointers to the node
        nodes[i].init_connect_ptrs(connect_ptrs, num_ptrs);
    }
}

// get the array index for a node with a certain node index
int Graph::nodeIndex2ArrayIndex(int nodeIdx) {
    int arrayIdx = -1;
    // loop through all nodes until you find the one with the right index
    bool found = false;
    int i = 0;
    while ((i < nodes.size()) && (!found)) {
        if (nodes[i].index == nodeIdx) {
            arrayIdx = i;
            found = true;
        } else {
            i++;
        }
        // std::cout << "Loopered through node index converter \n";
    }
    return arrayIdx;
}