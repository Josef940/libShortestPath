#ifndef GRAPHLANDMARKSTESTS_HPP
#define GRAPHLANDMARKSTESTS_HPP

#include "../src/entities/landmark_entities/GraphLandmarks.hpp"
#include "ShortestPathTests.hpp"

class GraphLandmarksTests : public ShortestPathTests{
    public:
        GraphLandmarks* graphLandmarks;
    protected:
        void createGraph () override{
            graph = new GraphLandmarks("landmarksTest.txt", 4);
        }
        void castGraph() override{
            graphLandmarks = static_cast<GraphLandmarks*>(graph);
        }
};

#endif