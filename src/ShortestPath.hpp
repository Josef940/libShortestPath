#include "./entities/graph_entities/Graph.hpp"
using namespace std;

class ShortestPath{
    public:
        ShortestPath(Graph graph){}
        list<int> computeShortestPath();
    private:
        void relax();
};