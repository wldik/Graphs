#include <iostream>
#include "graph.h"

using namespace std;
using namespace graphs;

int main()
{
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(5);
    graph.addEdge(0, 5);
    graph.addVertex(4);
    graph.addVertex(7);
    graph.addEdge(4, 7);
    graph.addEdge(4, 0);
    graph.addEdge(4, 9);
    graph.addVertex(0);
    graph.printFull();

    for(auto &edge:graph.getEdges()){
        cout<< edge.first << ", " << edge.second << endl;
    }

    return 0;
}
