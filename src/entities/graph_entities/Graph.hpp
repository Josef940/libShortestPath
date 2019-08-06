#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include "Vertex.hpp"
#include "Edge.hpp"
class Graph{
    protected:
        list<Edge*> _edges;
        list<Vertex*> _vertices;
    public:
        Graph(){}
        Vertex* addVertex(void* userObject, unsigned long long vertexID);
        Edge* addEdge(Vertex* vertex1, Vertex* vertex2, double weight);

        list<Edge*> edges() { return _edges; };
        list<Vertex*> vertices(){ return _vertices; };
};

#endif