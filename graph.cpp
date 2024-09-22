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
        nodes[i]->print_node();
    }
}

// prints the values for all the nodes concisely
void Graph::print_vals(void) {
    std::cout << "Node values:\n";
    for (int i = 0; i < nodes.size(); i++) {
        float node_val = nodes[i]->val;
        std::cout << "idx: " << nodes[i]->index << " val: " << node_val << "\n";
    }
}

// function to add a node to the graph
void Graph::addNode(GraphNode* node) {
    // just throw that node onto the end of the nodes vector
    // make sure the node doesn't already exist
    if (!checkNodeExistance(node->index)) {
        nodes.push_back(node);
    } else {
        std::cout << "Node already exists! \n";
    }
    // validateConnections();
}

// Validate all the connections to make sure nothing is wrong
void Graph::validateConnections(void) {
    // loop through all nodes
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << "Checking node : " << nodes[i]->index << "\n";
        // now loop through the nodes connections 
        for (int j = 0; j < nodes[i]->connects.size(); j++) {
            // 
            if (!checkNodeExistance(nodes[i]->connects[j])) {
                // add 1 to the indices when you display to make it more readable
                std::cout << "WARNING: node " << nodes[i]->index << " has a connection to node " << nodes[i]->connects[j] << " which does not exist \n";
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
        if (nodes[i]->index == idx) {
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
        int num_ptrs = nodes[i]->connects.size();
        GraphNode* connect_ptrs[num_ptrs];
        // loop through connections
        for (int j = 0; j < nodes[i]->connects.size(); j++) {
            // get the array index for the node connected
            int arrayIdx = nodeIndex2ArrayIndex(nodes[i]->connects[j]);
            GraphNode* connection = nodes[arrayIdx];
            connect_ptrs[j] = connection;
            connect_ptrs[j]->print_node();
        }
        // give that array of pointers to the node
        nodes[i]->init_connect_ptrs(connect_ptrs, num_ptrs);
    }
}

// get the array index for a node with a certain node index
int Graph::nodeIndex2ArrayIndex(int nodeIdx) {
    int arrayIdx = -1;
    // loop through all nodes until you find the one with the right index
    bool found = false;
    int i = 0;
    while ((i < nodes.size()) && (!found)) {
        if (nodes[i]->index == nodeIdx) {
            arrayIdx = i;
            found = true;
        } else {
            i++;
        }
        // std::cout << "Loopered through node index converter \n";
    }
    return arrayIdx;
}

// propogate all the nodes forward in time by delta_t
// this function does the propogation in the serialized fashion, having the CPU iterate through each node in the graph
// and propogating it inidividually
// MUST be done AFTER initializing the pointer arrays for each node
void Graph::propogateAllSerial(float delta_t) {
    // iterate through all nodes and propogate each one
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i]->propogate(delta_t);
    }
    // print out all the values
    print_vals();
}

// converts the numpy array-style array into the structure that can be better used to create the node connections
connects_struct Graph::convert2Struct(int idx, int *connections, int num_connects) {
    // create a connects_struct
    connects_struct connects;
    connects.idx = idx;

    // loop through the connections given
    for (int i = 0; i < num_connects; i++) {
        // only take the tuples that start with the index (only the connections originating for idx)
        
    }
}


/* ============= External Functions for python hooks ==============
Functions that are called external from python
*/
extern "C" {
    // create a graph
    Graph* createGraph(char* name, int *nodes, int num_nodes, int *connections, int num_connects, int node_fnc_idx) {
        // name is the name for the graph
        // nodes is an array of integers representing the nodes' indices
        // connections is an Nx2 array of the connections, where each tuple of integers represents the two nodes connected
        // connections = [[x,y],....] where the first entry represents that x is connected to y
        // node_fnc_idx specifies the function used to propogate the nodes' values

        Graph* G = new Graph(name);

        // first create all the nodes
        for (int i = 0; i < num_nodes; i++){
            // for reasons beyond me, I have to double the index in the numpy array sent into the function
            // numpy seems to put zeros between every value of the array sent in, so I need to take every other one to get the actual values
            GraphNode* node = new GraphNode(nodes[2*i], node_fnc_idx);
            G->addNode(node);
        }

        G->print();

        return G;
    }

    int testHooks(char* name, int namesize, int *connections, int num_connects) {
        std::cout << name;

        for (int i = 0; i < 2*num_connects; i++) {
            // std::cout << "element 1: " << connections[2*i] << " element 2: " << connections[2*i+1] << '\n';
            std::cout << "element: " << connections[2*i] << '\n';
        }
        return 1;
    }
}