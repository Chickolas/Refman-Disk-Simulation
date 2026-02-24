#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){

    // HINT: COMPLETE THE CALCULATION OF THE DISTANCE BETWEEN this DISK AND THE DISK other
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx*dx + dy*dy);
}