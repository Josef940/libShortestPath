#include "ShortestPath.hpp"
using namespace std;

enum{
    DIJKSTRA
};

list<int> ShortestPath::computeShortestPath(){
    list<int> test;
    test.push_back(DIJKSTRA);
    test.push_back(10);
    return test;
}
