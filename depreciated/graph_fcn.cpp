// This file contains definitions for graph related classes and functions
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include "graph_fcn.h"

// class TimeNode {
//     public:
//         int index; // index of this node
//         float t; // current time for the node
//         float value; // value for the function on that node
//         std::vector<int> connections; // list of indices of all other nodes this node is connected to

//         TimeNode(int idx, std::vector<int>& connects){
//             // creates an instance of the TimeNode class
//             index = idx;
//             for (int i=0; i < connects.size(); i++) {
//                 connections.push_back(connects[i]);
//             }
//         }
// };

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
