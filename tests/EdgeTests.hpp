/*#include <gtest/gtest.h>
class EdgeTests : public ::testing::Test{
    public:
        Edge* edge;
        Vertex* vertex1;
        Vertex* vertex2;
    protected:
        void SetUp() override{
            vertex1 = new Vertex(NULL,1);
            vertex2 = new Vertex(NULL,2);
            vertex1->addEdge(vertex2,42);
            edge = vertex1->edges().front();
        }
        void TearDown() override{
            delete edge;
            delete vertex1;
            delete vertex2;
        }
};
*/