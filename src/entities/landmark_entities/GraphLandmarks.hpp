#ifndef GRAPHLANDMARKS_HPP
#define GRAPHLANDMARKS_HPP

#include "../../Graph.hpp"
#include "Landmark.hpp"

class GraphLandmarks : public Graph{
    private:
        string _fileName;
        const unsigned int _amountOfLandmarks;
        list<Landmark*> _landmarks;
        list<Vertex*> selectLandmarks();
        void addLandmark(Vertex* landmark);
        Vertex* randomVertex();
    public:
        void createLandmarksFile();
        void generateLandmarks();
        void loadLandmarks();
        GraphLandmarks(string fileName, const unsigned int amountOfLandmarks) : _fileName(fileName), _amountOfLandmarks(amountOfLandmarks)
        {}
        const unsigned int amountOfLandmarks(){ return _amountOfLandmarks; }
        list<Landmark*> landmarks(){ return _landmarks; }
};

#endif