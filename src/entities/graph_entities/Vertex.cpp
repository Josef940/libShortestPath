#include "Vertex.hpp"
#include <iostream>

void Vertex::addEdgeFromVertex(Edge* edge){
    _edgesFromVertex.push_back(edge);
}

void Vertex::setDistanceFromStart(double newDistanceFromStart){
     _distanceFromStart = newDistanceFromStart;
}

void Vertex::setPreviousVertex(Vertex* previousVertex){
    _previousVertex = previousVertex;
}

void Vertex::setVisited(bool visited){
    _visited = visited;
}

void Vertex::resetVertex(){
    setDistanceFromStart(numeric_limits<double>::max());
    setPreviousVertex(NULL);
    setVisited(false);
}