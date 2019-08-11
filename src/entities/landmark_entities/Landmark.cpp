#include "Landmark.hpp"

void Landmark::addToDistance(double distance){
    _toDistances.push_back(distance);
}
void Landmark::addFromDistance(double distance){
    _fromDistances.push_back(distance);
}