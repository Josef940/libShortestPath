#include "GraphLandmarksTests.hpp"

TEST_F(GraphLandmarksTests, vertices_amount_are_still_correct_after_cast){
    ASSERT_EQ(graph->vertices().size(), graphLandmarks->vertices().size());
}
TEST_F(GraphLandmarksTests, vertices_are_equal_after_cast){
    //for(Vertex* v : graphLandmarks.vertices())
}
TEST_F(GraphLandmarksTests, tmp){
    graphLandmarks->generateLandmarks();
    //graphLandmarks->createLandmarksFile();
}