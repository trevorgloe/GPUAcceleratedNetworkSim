// this is a small c++ file to test out the graph functiosn without having to write hooks into python yet

#include "graph.h"

int main() {
    // create a graph object
    char graph_name[] = "Test Graph";
    Graph myGraph = Graph(graph_name);
    // myGraph.print();
    GraphNode* myNode1 = new GraphNode(1, SUM_NODE_VALS_THRESHOLD);
    myNode1->add_connection(2);
    myNode1->add_connection(3);
    GraphNode* myNode2 = new GraphNode(2, SUM_NODE_VALS_THRESHOLD);
    myNode2->add_connection(1);
    GraphNode* myNode3 = new GraphNode(3, SUM_NODE_VALS_THRESHOLD);
    myNode3->add_connection(1);
    myNode3->add_connection(2);
    myGraph.addNode(myNode1);
    myGraph.addNode(myNode2);
    myGraph.addNode(myNode3);
    myGraph.print();
    myGraph.nodes[0]->val = 1.5; // set the value for node 1
    myGraph.nodes[1]->val = 2.4; // set the value for node 2

    myGraph.initConnectsPtrs();
    // myGraph.nodes[2].connects_ptrs[0]->print_node();

    myGraph.nodes[2]->propogate(0.1);
    myGraph.nodes[2]->print_node();

    return 0;
}