#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <limits>
#include <list>
#include "Edge.hpp"
using namespace std;

class Vertex{
    protected:;
        void* _userObject;
        const unsigned long long _ID;
        list<Edge*> _edgesFromVertex;
        list<Edge*> _reversedEdgesFromVertex;
        double _distanceFromStart = numeric_limits<double>::max(); // I.e. tentative distance.
        Vertex* _previousVertex = NULL; // Previous Vertex in the shortest path to this Vertex.
        bool _visited = false;
    public:
        Vertex(void* userObject, unsigned long long ID): _ID(ID), _userObject(userObject)
        {}
        void resetVertex();
        void addEdgeFromVertex(Edge* edge);
        
        void* userObject(){ return _userObject; }
        unsigned long long ID(){ return _ID; }
        list<Edge*> edgesFromVertex(){ return _edgesFromVertex; }
        list<Edge*> reversedEdgesFromVertex(){ return _reversedEdgesFromVertex; }
        double distanceFromStart(){ return _distanceFromStart; }
        Vertex* previousVertex(){ return _previousVertex; }
        bool visited() { return _visited; }

        void setPreviousVertex(Vertex* previousVertex);
        void setDistanceFromStart(double newDistanceFromStart);
        void setVisited(bool visited);
};

#endif