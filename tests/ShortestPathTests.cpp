#include "ShortestPathTests.hpp"
#include "../src/entities/graph_entities/Vertex.hpp"
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

TEST_F(ShortestPathTests, vertices_on_shortest_path_has_correct_distanceFromStart){
    // Shortest path should be 0->1->5->4->9
    graph->computeShortestPath(vertex0, vertex9);
    EXPECT_EQ(vertex0->distanceFromStart(),0);
    EXPECT_EQ(vertex1->distanceFromStart(),1);
    EXPECT_EQ(vertex5->distanceFromStart(),7);
    EXPECT_EQ(vertex4->distanceFromStart(),9);
    EXPECT_EQ(vertex9->distanceFromStart(),13);
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
TEST_F(ShortestPathTests, computeShortestPath_correctly_twice_in_a_row){
    // Shortest path should be 0->1->5->4->9
    list<Vertex*> shortestPath1 = graph->computeShortestPath(vertex0, vertex9);
    
    list<Vertex*>::iterator it1 = shortestPath1.begin();
    ASSERT_EQ(*it1, vertex0);
    it1++;
    ASSERT_EQ(*it1, vertex1);
    it1++;
    ASSERT_EQ(*it1, vertex5);
    it1++;
    ASSERT_EQ(*it1, vertex4);
    it1++;
    ASSERT_EQ(*it1, vertex9);
    // Shortest path should be 2->6->5->4->3->1
    list<Vertex*> shortestPath2 = graph->computeShortestPath(vertex2, vertex1);
    
    list<Vertex*>::iterator it2 = shortestPath2.begin();
    ASSERT_EQ(*it2, vertex2);
    it2++;
    ASSERT_EQ(*it2, vertex6);
    it2++;
    ASSERT_EQ(*it2, vertex5);
    it2++;
    ASSERT_EQ(*it2, vertex4);
    it2++;
    ASSERT_EQ(*it2, vertex3);
    it2++;
    ASSERT_EQ(*it2, vertex1);
}