#include "Vertex.hpp"
/* template<typename UserObjectType>
void Vertex<UserObjectType>::addEdge(Edge<UserObjectType>* edge, unsigned long long){
    edges().push_back(edge);
}*/

void Vertex::addNeighbourEdge(Edge* edge){
    _edgesToNeighbours.push_back(edge);
}