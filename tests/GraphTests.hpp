#ifndef GRAPHTESTS_HPP
#define GRAPHTESTS_HPP

#include <gtest/gtest.h>
#include "../src/Graph.hpp"
class GraphTests : public::testing::Test{
    
    public:
        class TestUserObject{
            private:
                unsigned long long _ID;
            public:
                TestUserObject(unsigned long long ID){
                    _ID = ID;
                }
                unsigned long long ID(){ return _ID; }
        };
        Edge* edge;
        Vertex* vertex1;
        Vertex* vertex2;
        Graph* graph;
        TestUserObject* testUserObject1;
        TestUserObject* testUserObject2;
    protected:
        void SetUp() override{
            testUserObject1 = new TestUserObject(1);
            testUserObject2 = new TestUserObject(2);
            graph = new Graph();
            vertex1 = graph->addVertex(testUserObject1,testUserObject1->ID());
            vertex2 = graph->addVertex(testUserObject2, testUserObject2->ID());
            edge = graph->addEdge(vertex1, vertex2, 42);
        }
        void TearDown() override{
            delete graph;
        }
};

#endif