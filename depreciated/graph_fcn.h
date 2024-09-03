#ifndef GRAPH_FCN_H
#define GRAPH_FCN_H

#include <vector>

class TimeNode {
    public:
        int index; // index of this node
        float t; // current time for the node
        float value; // value for the function on that node
        std::vector<int> connections; // list of indices of all other nodes this node is connected to

        TimeNode(int idx, std::vector<int>& connects);
};

class GraphConnect {
    public:
        int source_node;
        int connected_node;

        void print(void);
};

#endif