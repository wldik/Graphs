#include "graph.h"

namespace graphs{

    template <class T> void Graph<T>::addVertex (Vertex v){
        if(!isVertexValid(v)){map_graph[v] = std::unordered_set<Vertex>();}
        else {std::cout<< "The vertex already exists." << std::endl;}
    }

    template <class T> bool Graph<T>::isVertexValid (Vertex v) const {
        return map_graph.find(v) != map_graph.end();
    }

    template <class T> void Graph<T>::addEdge (Vertex v1, Vertex v2){
        if (isVertexValid(v1) && isVertexValid(v2)){
            if(v1 == v2){
                std::cout<< "Self-loops aren't allowed. The edge wasn't added." << std::endl;
            }
            else{
            map_graph[v1].insert(v2);
            map_graph[v2].insert(v1);
            }
        }
        else{
            std::cout<< "Invalid vertices. The edge wasn't added." << std::endl;
        }
    }

    template <class T> std::unordered_set<typename Graph<T>::Vertex> Graph<T>::getVertices () const {
        std::unordered_set<Vertex> vertices;
        for ( const auto &vert:map_graph ){
            vertices.insert(vert.first);
        }
        return vertices;
    }

template <class T> std::vector<typename Graph<T>::Edge> Graph<T>::getEdges () const {
    std::vector<Edge> edges;
    for (const auto &vert : map_graph) {
        for (const auto &adjacent : vert.second) {
            Edge edge = (vert.first < adjacent) ? std::make_pair(vert.first, adjacent) : std::make_pair(adjacent, vert.first);
            // checking for duplicates
            auto it = std::find(edges.begin(), edges.end(), edge);
            if (it == edges.end()) {
                edges.push_back(edge);
            }
        }
    }
    return edges;
}

    template <class T> void Graph<T>::printVertex(Vertex v) const{
        std::cout<< "Vertex " << v << ": ";
        for (const auto &adj:map_graph.find(v)->second){
            std::cout<< adj << " ";
        }
        std::cout<< "" << std::endl;
    }

    template <class T> void Graph<T>::printFull() const{
        for (const auto &vert:map_graph){
            printVertex(vert.first);
        }
    }

}

template class graphs::Graph<int>;
