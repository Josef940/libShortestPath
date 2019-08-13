#include "GraphLandmarksTests.hpp"
#include <iterator>

TEST_F(GraphLandmarksTests, vertices_amount_are_still_correct_after_cast){
    ASSERT_EQ(graph->vertices().size(), graphLandmarks->vertices().size());
}

TEST_F(GraphLandmarksTests, vertices_are_equal_after_cast){
    auto graphIterator = graph->verticesBegin();
    auto graphIteratorEnd = graph->verticesEnd();
    auto graphLandmarksIterator = graphLandmarks->verticesBegin();
    auto graphLandmarksIteratorEnd = graphLandmarks->verticesEnd();
    while(graphIterator != graphIteratorEnd && graphLandmarksIterator != graphLandmarksIteratorEnd){
        ASSERT_EQ(*graphIterator, *graphLandmarksIterator);
        advance(graphIterator,1);
        advance(graphLandmarksIterator,1);
    }
}

TEST_F(GraphLandmarksTests, edges_amount_are_still_correct_after_cast){
    ASSERT_EQ(graph->edges().size(), graphLandmarks->edges().size());
}

TEST_F(GraphLandmarksTests, edges_are_equal_after_cast){
    auto graphIterator = graph->edgesBegin();
    auto graphIteratorEnd = graph->edgesEnd();
    auto graphLandmarksIterator = graphLandmarks->edgesBegin();
    auto graphLandmarksIteratorEnd = graphLandmarks->edgesEnd();
    while(graphIterator != graphIteratorEnd && graphLandmarksIterator != graphLandmarksIteratorEnd){
        ASSERT_EQ(*graphIterator, *graphLandmarksIterator);
        advance(graphIterator,1);
        advance(graphLandmarksIterator,1);
    }
}

TEST_F(GraphLandmarksTests, throw_when_trying_to_create_more_landmarks_than_amount_of_vertices){
    auto graphLandmarks2 = new GraphLandmarks("landmarksTest2.txt",4);
    auto vertex1 = graphLandmarks2->addVertex(NULL,0);
    auto vertex2 = graphLandmarks2->addVertex(NULL,1);
    auto vertex3 = graphLandmarks2->addVertex(NULL,2);
    ASSERT_ANY_THROW(graphLandmarks2->generateLandmarks());
}

TEST_F(GraphLandmarksTests, do_not_throw_when_trying_to_create_equal_amount_of_landmarks_and_vertices){
    auto graphLandmarks2 = new GraphLandmarks("landmarksTest2.txt",3);
    auto vertex1 = graphLandmarks2->addVertex(NULL,0);
    auto vertex2 = graphLandmarks2->addVertex(NULL,1);
    auto vertex3 = graphLandmarks2->addVertex(NULL,2);
    ASSERT_NO_THROW(graphLandmarks2->generateLandmarks());
}

TEST_F(GraphLandmarksTests, tmp){
    graphLandmarks->generateLandmarks();
    //graphLandmarks->createLandmarksFile();
}