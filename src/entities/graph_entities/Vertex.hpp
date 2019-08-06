#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <limits>
#include <list>
#include "Edge.hpp"
using namespace std;
class Vertex{
    protected:
        void* _userObject;
        const unsigned long long _ID;
        double _distanceFromStart = numeric_limits<double>::max();
        list<Edge*> _edgesToNeighbours;
    public:
        Vertex(void* userObject, unsigned long long ID):_ID(ID){
            _userObject = userObject;
        }
        void addNeighbourEdge(Edge* edge);

        // Getters
        void* userObject(){ return _userObject; }
        unsigned long long ID(){ return _ID; }
        double distanceFromStart(){ return _distanceFromStart; }
        list<Edge*> connectedEdges(){ return _edgesToNeighbours; }
};

#endif