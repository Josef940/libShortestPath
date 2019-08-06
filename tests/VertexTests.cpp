/* #include <gtest/gtest.h>
#include "../src/ShortestPath.hpp"
using namespace std;

TEST(VertextTest, pointer_returns_correct_ID){
    Vertex* v = new Vertex(NULL,1);
    ASSERT_EQ(v->ID(),1);
}

TEST(VertextTest, reference_returns_correct_ID){
    Vertex v = Vertex(NULL,1);
    ASSERT_EQ(v.ID(),1);
}

TEST(VertexText, userObject_points_correctly){
    Vertex* userObject = new Vertex(NULL,42);
    Vertex* v = new Vertex(&userObject,0);
    Vertex* userObject2 = static_cast<Vertex*>(v->userObject());
    ASSERT_EQ(userObject2->ID(), 42);
}

TEST(VertexText, vertex_distance_is_max){
    Vertex* v = new Vertex(NULL,0);
    ASSERT_EQ(v->distanceFromStart(), numeric_limits<double>::max());
}

TEST(VertexTest, edges_and_vertices_relations_are_correct){
    Vertex* v1 = new Vertex(NULL,1);
    Vertex* v2 = new Vertex(NULL,2);
    v1->addEdge(v2,42);
    list<Edge*> edges = v1->edges();
    ASSERT_EQ(edges.front()->vertex1()->ID(), 1);
}
*/