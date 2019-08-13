#include "Graph.hpp"
#include <queue>

Graph::~Graph(){
    for(Vertex* vertex : _vertices){
        delete vertex;
    }
    for(Edge* edge : _edges){
        delete edge;
    }
}

void Graph::cleanup(){
    for(Vertex* vertex : _vertices){
        vertex->resetVertex();
    }
}

Vertex* Graph::addVertex(void* userObject, unsigned long long vertexID){
        Vertex* vertex = new Vertex(userObject, vertexID);
        _vertices.push_back(vertex);
        return vertex;
}

Edge* Graph::addEdge(Vertex* vertex1, Vertex* vertex2, double weight){
    Edge* edge = new Edge(vertex1, vertex2, weight);
    _edges.push_back(edge);
    vertex1->addEdgeFromVertex(edge);
    return edge;
}

list<Vertex*> Graph::computeShortestPath(Vertex* startVertex, Vertex* targetVertex){
    cleanup();
    
    vertex_priority_queue queue;
    startVertex->setDistanceFromStart(0);
    queue.push(startVertex);

    while(!queue.empty()){
        Vertex* vertexFromQueue = queue.top();
        queue.pop();
        vertexFromQueue->setVisited(true);
        if(vertexFromQueue == targetVertex){
            list<Vertex*> shortestPath = extractShortestPath(targetVertex);
            return shortestPath;
        }
        relax(vertexFromQueue, queue);
    }
    // If no path found, return empty list.
    list<Vertex*> shortestPath;
    return shortestPath;
}

void Graph::relax(Vertex* vertex, vertex_priority_queue& priorityQueue){
    for(Edge* edge : vertex->edgesFromVertex()){
        double newDistance = vertex->distanceFromStart() + edge->weight();
        Vertex* toVertex = edge->vertex2();
        if(newDistance < toVertex->distanceFromStart()){
            toVertex->setDistanceFromStart(newDistance);
            priorityQueue.push(toVertex);
            toVertex->setPreviousVertex(vertex);
        }
    }
}

list<Vertex*> Graph::extractShortestPath(Vertex* targetVertex){
    list<Vertex*> shortestPath;
    Vertex* traverserVertex = targetVertex;
    while(traverserVertex != NULL){
        shortestPath.push_front(traverserVertex);
        traverserVertex = traverserVertex->previousVertex();
    }
    return shortestPath;
}