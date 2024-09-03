// This file contains definitions for graph related classes and functions
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include "graph_fcn.h"


TimeNode::TimeNode(int idx, std::vector<int>& connects){
    // creates an instance of the TimeNode class
    index = idx;
    for (int i=0; i < connects.size(); i++) {
        connections.push_back(connects[i]);
    }
}

// class GraphConnect {
//     public:
//         int source_node;
//         int connected_node;

//         void print(){
//             std::cout << "Source:";
//             std::cout << source_node;
//             std::cout << " Target:";
//             std::cout << connected_node << '\n';
//         }
// };

void GraphConnect::print(){
    std::cout << "Source:";
    std::cout << source_node;
    std::cout << " Target:";
    std::cout << connected_node << '\n';
}

extern "C" {
    int test_print(void){
        // this function will do a little test to make sure I can call stuff from python
        GraphConnect c;
        c.source_node = 3;
        c.connected_node = 4;
        c.print();

        return c.source_node;
    }
}