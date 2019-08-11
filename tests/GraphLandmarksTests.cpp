#include "GraphLandmarksTests.hpp"

TEST_F(GraphLandmarksTests, tmp){
    graphLandmarks->generateLandmarks();
    graphLandmarks->createLandmarksFile();
}