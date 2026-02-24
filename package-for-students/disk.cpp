#include "disk.h"
#include <cmath>

// Constructor for the class
Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

// Increment's the disks position by (dx, dy)
void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

// Calculates the euclidean distance between the current and other disks
double Disk::distance(Disk& other){

    // HINT: COMPLETE THE CALCULATION OF THE DISTANCE BETWEEN this DISK AND THE DISK other
    const double dx = x - other.x;
    const double dy = y - other.y;
    return std::sqrt(dx*dx + dy*dy);
}