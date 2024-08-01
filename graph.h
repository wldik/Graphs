#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

// This graph is made using adjacency list, the latter is implemented via unordered set.
// The choice for DSes was made with a need to get rid off repeating values of vertices and edges.
// Graph is undirected, simple and unweighted.

namespace graphs{

    template <class T>
    class Graph {

    public:

        using Vertex = T;
        using Edge = std::pair<Vertex, Vertex>;

    private:

        std::unordered_map<Vertex, std::unordered_set<Vertex>> map_graph;

    public:

        Graph() = default;
        Graph(const Graph &) = delete;
        Graph(const Graph &&) = delete;
        Graph &operator=(const Graph &) = delete;
        Graph &operator=(const Graph &&) = delete;
        ~Graph() = default;

        void addVertex(Vertex);
        void addEdge(Vertex, Vertex);

        std::unordered_set<Vertex> getVertices() const;
        std::vector<Edge> getEdges() const;

        bool isVertexValid(Vertex) const;

        void printVertex(Vertex) const;
        void printFull() const;

    };

}
