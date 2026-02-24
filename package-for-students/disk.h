#pragma once
#ifndef DISK_H
#define DISK_H

class Disk {
public:
    // Centre coordinates (x,y) and the radius of the disk
    double x, y, radius;

    explicit Disk(double x, double y, double r);

    // Translates the disks centre
    void move(double dx, double dy);

    // Calculates the euclidean distance between disk centres
    double distance(Disk& d);
};

#endif