#include <fstream>
//HINT: COMPLETE THE INCLUDE STATEMENT
#include "system.h"
#include "disk.h"

System::System(int N, double displacement,double radius, double boxSize, int seed) {

        this->boxSize= boxSize;
        this->  dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        
        int nSide = static_cast<int>(boxSize/ (2*radius));

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   


bool System::overlap(int i){
    for (int j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < (disks[i].radius + disks[j].radius) ) {
            return true;
        }
    }
    return false;
}

void System::step() {
    for (size_t i=0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].x;
        double oldy = disks[selected_disk].y;
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].x = oldx;
            disks[selected_disk].y = oldy;
        }
       
    }
}

// Make disks stay within the box
void System::enforceBoundaries(Disk & disk) {
    if (disk.x < disk.radius) disk.x = disk.radius;
    if (disk.x > boxSize - disk.radius) disk.x = boxSize - disk.radius;
    if (disk.y < disk.radius) disk.y = disk.radius;
    if (disk.y > boxSize - disk.radius) disk.y = boxSize - disk.radius;
}

// HINT: PROVIDE A DEFINITION FOR A MEMBER FUNCTION OF THE SYSTEM CLASS CALLED uniform

// Returns  random distance between the min and max value 
double System::uniform(double min, double max) {
    return min + dist(gen) * (max - min);
}

void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.x<<" "<<disk.y<<" "<<disk.radius<<std::endl;

    }
    outFile.close();
    
}