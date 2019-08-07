#include "ShortestPathTests.hpp"
TEST_F(ShortestPathTests, computeShortestPath_should_return_correct_path_v0_to_v9){
    // Shortest path should be 0->1->5->4->9
    list<Vertex*> shortestPath = graph->computeShortestPath(vertex0, vertex9);
    
    list<Vertex*>::iterator it = shortestPath.begin();
    ASSERT_EQ(*it, vertex0);
    it++;
    ASSERT_EQ(*it, vertex1);
    it++;
    ASSERT_EQ(*it, vertex5);
    it++;
    ASSERT_EQ(*it, vertex4);
    it++;
    ASSERT_EQ(*it, vertex9);
}

TEST_F(ShortestPathTests, computeShortestPath_should_return_correct_path_v2_to_v1){
    // Shortest path should be 2->6->5->4->3->1
    list<Vertex*> shortestPath = graph->computeShortestPath(vertex2, vertex1);
    
    list<Vertex*>::iterator it = shortestPath.begin();
    ASSERT_EQ(*it, vertex2);
    it++;
    ASSERT_EQ(*it, vertex6);
    it++;
    ASSERT_EQ(*it, vertex5);
    it++;
    ASSERT_EQ(*it, vertex4);
    it++;
    ASSERT_EQ(*it, vertex3);
    it++;
    ASSERT_EQ(*it, vertex1);
}