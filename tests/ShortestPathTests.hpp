#ifndef SHORTESTPATHTESTS_HPP
#define SHORTESTPATHTESTS_HPP

#include <gtest/gtest.h>
#include "../src/ShortestPath.hpp"
class ShortestPathTests : public ::testing::Test{
    public:
        class TestMapNode{
            private:
                const unsigned long long _ID;
                const double _xCoord;
                const double _yCoord;
            public:
                TestMapNode(unsigned long long ID, double xCoord, double yCoord):_ID(ID),_xCoord(xCoord),_yCoord(yCoord)
                {}
                unsigned long long ID(){ return _ID; }
                double xCoord(){ return _xCoord; }
                double yCoord(){ return _yCoord; }
        };
    TestMapNode* node;
    protected:
        void SetUp() override{
            node = new TestMapNode(1,10,15);
        }
};

#endif