#ifndef LANDMARK_HPP
#define LANDMARK_HPP
#include <string>
#include <vector>
using namespace std;
class Landmark{
    private:
        vector<double> _toDistances;
        vector<double> _fromDistances;
    public:
        vector<double> toDistances(){ return _toDistances; }
        vector<double> fromDistances(){ return _fromDistances; }
        void addToDistance(double distance);
        void addFromDistance(double distance);
};

#endif