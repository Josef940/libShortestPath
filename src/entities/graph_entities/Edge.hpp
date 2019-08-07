#ifndef EDGE_HPP
#define EDGE_HPP

/*
* Directed edge
*/
class Vertex;
class Edge{
    private:
        Vertex* _vertex1; // From
        Vertex* _vertex2; // To
        const double _weight;
    public:
        Edge(Vertex* vertex1, Vertex* vertex2, double weight):_vertex1(vertex1),_vertex2(vertex2),_weight(weight)
        {}
        Vertex* vertex1(){ return _vertex1; }
        Vertex* vertex2(){ return _vertex2; }
        const double weight(){ return _weight;}
};

#endif