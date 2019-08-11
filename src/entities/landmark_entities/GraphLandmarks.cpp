#include "GraphLandmarks.hpp"
#include <iostream>
#include <fstream>

void GraphLandmarks::generateLandmarks(){
    list<Vertex*> selectedVertexLandmarks = selectLandmarks();
    for(Vertex* vertexLandmark : selectedVertexLandmarks){
        addLandmark(vertexLandmark);
    }
}

void GraphLandmarks::createLandmarksFile(){
    ofstream file;
    file.open(_fileName);
    for(Landmark* landmark : _landmarks){
        auto landmarksSize = landmark->toDistances().size();
        auto toDistances = landmark->toDistances();
        auto fromDistances = landmark->fromDistances();
        for(int i = 0; i < landmarksSize; i++){
            file << toDistances.at(i) <<":" << fromDistances.at(i) << ";" << endl;
        }
    }
    file.close();
}

list<Vertex*> GraphLandmarks::selectLandmarks(){ //TEMP, select randomly
    list<Vertex*> selectedLandmarks;
    /*Vertex* unreachableVertex = new Vertex(NULL,numeric_limits<unsigned long long>::max());
    computeShortestPath(randomVertex(), unreachableVertex);*/
    for(int i = 1; i <= amountOfLandmarks(); i++){
        selectedLandmarks.push_back( *(vertices().begin()) );
    }
    return selectedLandmarks;
}

Vertex* GraphLandmarks::randomVertex(){
    auto begin = vertices().begin();
    auto end = vertices().end();
    const unsigned long long n = distance(begin,end);
    auto max = RAND_MAX;
    const unsigned long long divisor = (max + 1) / n;
    unsigned long long k;
    do{
        k = rand()/divisor;
    } while(k>=n);
    advance(begin,k);
    return *begin;
}

void GraphLandmarks::addLandmark(Vertex* landmarkVertex){
    Vertex* unreachableVertex = new Vertex(NULL,numeric_limits<unsigned long long>::max());
    computeShortestPath(landmarkVertex, unreachableVertex);
    delete unreachableVertex;
    Landmark* landmark = new Landmark();
    for(Vertex* vertex : vertices()){
        double fromDistance = vertex->distanceFromStart();
        if(fromDistance == numeric_limits<double>::max())
            fromDistance = -1;
        landmark->addFromDistance(fromDistance);
        landmark->addToDistance(0);
    }
    _landmarks.push_back(landmark);
}