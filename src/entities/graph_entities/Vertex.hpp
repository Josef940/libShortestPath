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
        list<Edge*> _edgesToNeighbours;
        double _distanceFromStart = numeric_limits<double>::max(); // I.e. tentative distance.
        Vertex* _previousVertex = NULL; // Previous Vertex in the shortest path to this Vertex.
    public:
        Vertex(void* userObject, unsigned long long ID): _ID(ID), _userObject(userObject)
        {}
        void resetVertex();
        void addNeighbourEdge(Edge* edge);
        
        void* userObject(){ return _userObject; }
        unsigned long long ID(){ return _ID; }
        list<Edge*> connectedEdges(){ return _edgesToNeighbours; }
        double distanceFromStart(){ return _distanceFromStart; }
        Vertex* previousVertex(){ return _previousVertex; }
        void setPreviousVertex(Vertex* previousVertex);
        void setDistanceFromStart(double newDistanceFromStart);
};

#endif