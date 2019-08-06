#include "GraphTests.hpp"
using namespace std;

TEST_F(GraphTests, vertices_size_should_be_two){
    ASSERT_EQ(graph->vertices().size(),2);
}

TEST_F(GraphTests, correct_vertex_IDs_from_vertices_in_graph){
    list<Vertex*>::iterator it = graph->vertices().begin();
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