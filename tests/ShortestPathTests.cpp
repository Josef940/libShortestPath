/*#include "ShortestPathTests.hpp"

TEST_F(ShortestPathTests, mapnode_initialized_correctly){
    ASSERT_EQ(node->ID(), 1);
}
 */
#include "ShortestPathTests.hpp"
#include <gtest/gtest.h>
TEST(ShortestPathTests, computeShortestPath_should_return_correct_path){
    Graph* graph = new Graph();
    Vertex* vertex1 = graph->addVertex(NULL, 1);
    Vertex* vertex2 = graph->addVertex(NULL, 2);
    Vertex* vertex3 = graph->addVertex(NULL, 3);
    Vertex* vertex4 = graph->addVertex(NULL, 4);
    Vertex* vertex5 = graph->addVertex(NULL, 5);
    Vertex* vertex6 = graph->addVertex(NULL, 6);
    
    graph->addEdge(vertex1, vertex2, 2);
    graph->addEdge(vertex2, vertex4, 1);
    graph->addEdge(vertex4, vertex3, 1);
    graph->addEdge(vertex2, vertex3, 3);
    graph->addEdge(vertex3, vertex2, 1);
    graph->addEdge(vertex3, vertex5, 2);
    graph->addEdge(vertex5, vertex6, 4);
    list<Vertex*> shortestPath = graph->computeShortestPath(vertex1, vertex5);
    ASSERT_EQ(shortestPath.size(),5);
    
    list<Vertex*>::iterator it = shortestPath.begin();
    ASSERT_EQ(*it, vertex1);
    it++;
    ASSERT_EQ(*it, vertex2);
    it++;
    ASSERT_EQ(*it, vertex4);
    it++;
    ASSERT_EQ(*it, vertex3);
    it++;
    ASSERT_EQ(*it, vertex5);
    

}