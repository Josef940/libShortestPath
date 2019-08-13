#include "GraphLandmarks.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

void GraphLandmarks::generateLandmarks(){
    list<Vertex*> selectedVertexLandmarks = selectLandmarksRandomly();
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


list<Vertex*> GraphLandmarks::selectLandmarksRandomly(){ //TEMP, select randomly
    list<Vertex*> selectedLandmarks;
    /*Vertex* unreachableVertex = new Vertex(NULL,numeric_limits<unsigned long long>::max());
    computeShortestPath(randomVertex(), unreachableVertex);*/
    for(int i = 1; i <= amountOfLandmarks(); i++){
        selectedLandmarks.push_back(randomVertex(selectedLandmarks));
    }
    return selectedLandmarks;
}

/*
*  Not uniformly random picking, but the precision does not matter at all in this case.
*/
Vertex* GraphLandmarks::randomVertex(list<Vertex*> alreadySelected){
    auto vertices_size = vertices().size();
    if(alreadySelected.size() >= vertices_size){
        throw "Cannot find random vertex from the vertices list! All vertices are already selected.";
    }else if(vertices_size == 0){
        throw "No vertices to pick a random vertex from.";
    }

    Vertex* selectedVertex;
    auto begin_alreadySelected = alreadySelected.begin();
    auto end_alreadySelected = alreadySelected.end();
    do{
        list<Vertex*>::iterator vertices_iterator = verticesBegin();

        int random_num = rand() % vertices_size;
        advance(vertices_iterator, random_num);
        selectedVertex = *vertices_iterator;
    }while(find(begin_alreadySelected, end_alreadySelected, selectedVertex) != end_alreadySelected);

    return selectedVertex;
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