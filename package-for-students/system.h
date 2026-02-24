#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "disk.h"

class System {
public:
    std::vector<Disk> disks;
    double boxSize;
    double displacement;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dist;

    // N disks in a square of length bo_size
    System(int N, double displacement, double radius, double box_size, int seed);
    
    // Move forward 1 timestep
    void step();

    // Saves the step
    void save(const std::string &filename);
    bool overlap(int i);

    // Resets the disk if it goes out of bounds
    void enforceBoundaries(Disk & disk);

    // takes a random value between the min and max
    double uniform(double min, double max);
};

#endif