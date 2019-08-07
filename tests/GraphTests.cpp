#include "GraphTests.hpp"
#include <iostream>
using namespace std;

TEST_F(GraphTests, vertices_size_should_be_two){
    ASSERT_EQ(graph->vertices().size(),2);
}

TEST_F(GraphTests, correct_vertex_IDs_from_vertices_in_graph){
    int k = 1;
    for(auto vertex : graph->vertices()){
        ASSERT_EQ(vertex->ID(), k);
        k++;
    }
}

TEST_F(GraphTests, useobject_should_be_statically_casted_correctly){
    TestUserObject* castedUserObject = static_cast<TestUserObject*>(vertex1->userObject());
    ASSERT_EQ(castedUserObject, testUserObject1);
}

TEST_F(GraphTests, first_and_second_use_object_should_not_be_equal){
    TestUserObject* castedUserObject1 = static_cast<TestUserObject*>(vertex1->userObject());
    TestUserObject* castedUserObject2 = static_cast<TestUserObject*>(vertex2->userObject());
    ASSERT_NE(castedUserObject1, castedUserObject2);
}

TEST_F(GraphTests, should_return_correct_id_with_nullpointer_userobjects){
    graph->addVertex(nullptr,42);
    auto vertexID = graph->vertices().back()->ID();
    ASSERT_EQ(vertexID, 42);
}

TEST_F(GraphTests, added_edge_in_graph_is_equal_to_edge_init_pointer){
    ASSERT_EQ(edge, graph->edges().front());
}
TEST_F(GraphTests, added_edge_returns_correct_weight){
    ASSERT_EQ(edge->weight(), 42);
}

TEST_F(GraphTests, neighbour_edge_added_to_vertex_1_when_added_to_graph){
    Edge* connectedEdge = vertex1->connectedEdges().front();
    ASSERT_EQ(edge, connectedEdge);
}

TEST_F(GraphTests, return_42_after_distanceFromStart_is_set_to_42){
    vertex1->setDistanceFromStart(42);
    ASSERT_EQ(vertex1->distanceFromStart(), 42);
}

TEST_F(GraphTests, vertex_priority_queue_prioritizes_correctly){
    Vertex* vertex3 = new Vertex(NULL, 4);
    Vertex* vertex4 = new Vertex(NULL, 3);
    Vertex* vertex5 = new Vertex(NULL, 6);
    Vertex* vertex6 = new Vertex(NULL, 5);
    Graph::vertex_priority_queue priorityQ;
    vertex1->setDistanceFromStart(0);
    vertex2->setDistanceFromStart(4);
    vertex3->setDistanceFromStart(100);
    vertex4->setDistanceFromStart(80);
    vertex6->setDistanceFromStart(110);
    priorityQ.push(vertex1);
    priorityQ.push(vertex2);
    priorityQ.push(vertex3);
    priorityQ.push(vertex4);
    priorityQ.push(vertex5);
    priorityQ.push(vertex6);
    unsigned long long i = 1;
    while(!priorityQ.empty()){
        ASSERT_EQ(priorityQ.top()->ID(), i);
        priorityQ.pop();
        i++;
    }
}