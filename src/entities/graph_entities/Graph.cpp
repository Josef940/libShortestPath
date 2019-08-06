#include "Graph.hpp"

Vertex* Graph::addVertex(void* userObject, unsigned long long vertexID){
        Vertex* vertex = new Vertex(userObject, vertexID);
        _vertices.push_back(vertex);
        return vertex;
};

Edge* Graph::addEdge(Vertex* vertex1, Vertex* vertex2, double weight){
    Edge* edge = new Edge(vertex1, vertex2, weight);
    _edges.push_back(edge);
    vertex1->addNeighbourEdge(edge);
    return edge;
}