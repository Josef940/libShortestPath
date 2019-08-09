#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <queue>
#include "./entities/graph_entities/Vertex.hpp"
#include "./entities/graph_entities/Edge.hpp"
class Graph{
    protected:
        list<Vertex*> _vertices;
        list<Edge*> _edges;
    public:
        Graph(){}
        ~Graph();
        Vertex* addVertex(void* userObject, unsigned long long vertexID);
        Edge* addEdge(Vertex* vertex1, Vertex* vertex2, double weight);

        list<Vertex*> computeShortestPath(Vertex* startVertex, Vertex* targetVertex);
        void cleanup();

        list<Edge*> edges() { return _edges; };
        list<Vertex*> vertices(){ return _vertices; };

        class VertexPointerComparator{
            public:
                bool operator()(Vertex* vertex1, Vertex* vertex2){
                    return vertex2->distanceFromStart() < vertex1->distanceFromStart();
                }
        };

        typedef priority_queue<Vertex*, vector<Vertex*>, VertexPointerComparator> vertex_priority_queue;
        void relax(Vertex* vertex, vertex_priority_queue& priorityQueue);
        list<Vertex*> extractShortestPath(Vertex* targetVertex);

};

#endif