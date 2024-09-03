// This is an initial script to create a model for networks

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include "graph_fcn.h"

void print_float_vec(std::vector<float>& vec);
void init_test_graph(std::vector<GraphConnect>& G);

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

// class GraphConnect {
//     public:
//         int source_node;
//         int connected_node;
// };

int main() {
    // std::vector<float> t;
    // t.reserve(100);
    // float max = 10;

    // for (int n=0; n < 100; n++) {
    //     float curr_t = (((float) n)/ 100.0) * max;
    //     t.push_back(curr_t);
    // }

    // print_float_vec(t);
    std::vector<GraphConnect> graph;
    // GraphConnect c;
    // c.source_node = 1;
    // c.connected_node = 2;
    // graph.push_back(c);
    init_test_graph(graph);
    std::cout << graph[1].source_node << ' ';
    std::cout << graph[1].connected_node;
    // graph[1].print();
    GraphConnect c;
    c.source_node = 1;
    c.connected_node = 2;
    c.print();
}

void print_float_vec(std::vector<float>& vec) {
    std::cout << vec[0];
    printf("Vector is size %d", (int) vec.size());
    for (float val : vec) {
        std::cout << val << ' ';
    }
}

void init_test_graph(std::vector<GraphConnect>& G) {
    std::cout << "Initializing graph...";
    int sources[10] = {1,2,2,3,4,4,5,5,5,6};    // the sources for the graph connections
    int connects[10] = {2,3,4,1,2,5,3,4,1,2};   // the things the sources connect to
    for (int i=0; i < 10; i++) {
        GraphConnect c;
        c.source_node = sources[i];
        c.connected_node = connects[i];
        G.push_back(c);
    }
}