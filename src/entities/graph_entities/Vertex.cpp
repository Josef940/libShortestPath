#include "Vertex.hpp"
#include <iostream>

void Vertex::addNeighbourEdge(Edge* edge){
    _edgesToNeighbours.push_back(edge);
}

void Vertex::setDistanceFromStart(double newDistanceFromStart){
     _distanceFromStart = newDistanceFromStart;
}

void Vertex::setPreviousVertex(Vertex* previousVertex){
    _previousVertex = previousVertex;
}

void Vertex::resetVertex(){
    setDistanceFromStart(numeric_limits<double>::max());
    setPreviousVertex(NULL);
}