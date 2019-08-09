#ifndef SHORTESTPATHTESTS_HPP
#define SHORTESTPATHTESTS_HPP

#include <gtest/gtest.h>
#include "../src/Graph.hpp"
class ShortestPathTests : public ::testing::Test{
    // Graph designed as https://graphonline.ru/en/?graph=PNUKHFYvJrnwKZST
    public:
        Graph* graph;
        Vertex* vertex0;
        Vertex* vertex1;
        Vertex* vertex2;
        Vertex* vertex3;
        Vertex* vertex4;
        Vertex* vertex5;
        Vertex* vertex6;
        Vertex* vertex7;
        Vertex* vertex8;
        Vertex* vertex9;
        Vertex* vertex10;
    protected:
        void SetUp() override{
            graph = new Graph();
            vertex0 = graph->addVertex(NULL, 0);
            vertex1 = graph->addVertex(NULL, 1);
            vertex2 = graph->addVertex(NULL, 2);
            vertex3 = graph->addVertex(NULL, 3);
            vertex4 = graph->addVertex(NULL, 4);
            vertex5 = graph->addVertex(NULL, 5);
            vertex6 = graph->addVertex(NULL, 6);
            vertex7 = graph->addVertex(NULL, 7);
            vertex8 = graph->addVertex(NULL, 8);
            vertex9 = graph->addVertex(NULL, 9);
            vertex10 = graph->addVertex(NULL, 10);
            
            graph->addEdge(vertex0, vertex2, 3);
            graph->addEdge(vertex0, vertex7, 2);
            graph->addEdge(vertex0, vertex1, 1);
            graph->addEdge(vertex7, vertex0, 2);
            graph->addEdge(vertex2, vertex6, 4.56);
            graph->addEdge(vertex8, vertex1, 1);
            graph->addEdge(vertex8, vertex3, 4);
            graph->addEdge(vertex8, vertex9, 20);
            graph->addEdge(vertex1, vertex0, 1);
            graph->addEdge(vertex1, vertex8, 1);
            graph->addEdge(vertex1, vertex5, 6);
            graph->addEdge(vertex3, vertex1, 1);
            graph->addEdge(vertex3, vertex9, 8);
            graph->addEdge(vertex3, vertex4, 6);
            graph->addEdge(vertex6, vertex2, 4.56);
            graph->addEdge(vertex6, vertex5, 2.5);
            graph->addEdge(vertex5, vertex10, 3.5);
            graph->addEdge(vertex5, vertex6, 2.3);
            graph->addEdge(vertex5, vertex4, 2);
            graph->addEdge(vertex5, vertex1, 6);
            graph->addEdge(vertex4, vertex5, 2);
            graph->addEdge(vertex4, vertex3, 2);
            graph->addEdge(vertex4, vertex9, 4);
            graph->addEdge(vertex9, vertex4, 4);
        }
        void TearDown() override{
        }
};

#endif