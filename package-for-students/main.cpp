#include <iostream>
#include <string>
// HINT: COMPLETE THE INCLUDE STATEMENT
#include "system.h"


/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */

static void usage(const char* prog) {
    std::cout << "Command Usage: " << prog <<" NumberOfDisks maxDisplacement Radius BoxSize \n";
}

 // Added CLI's
int main(int argc, char *argv[]) {
    // number of disks
    int N = 20;
    double maxDisplacement  = 0.6;
    double radius = 0.5;
    double L = 20.0;

    // Parse in arguements
    try {
        if (argc > 1) N = std::stoi(argv[1]);
        if (argc > 2) maxDisplacement = std::stod(argv[2]);
        if (argc > 3) radius = std::stod(argv[3]);
        if (argc > 4) L = std::stod(argv[4]);
        if (argc > 5) {
            // If too many provide error message telling how to use the program
            usage(argv[0]); 
            return 1;
        }
    } catch (...) {
        // If too many provide error message telling how to use the program
        usage(argv[0]);
        return 1;
    }

    // Check if the values make sense, revert if not
    if (N <= 0) N = 20;
    if (maxDisplacement < 0) maxDisplacement = 0.6;
    if (radius <= 0) radius = 0.5;
    if (L <= 0) L = 20.0;

    // initialise the system
    System system(N, maxDisplacement,radius,L,1234);

    // total number of iterations
    int iterations = N*500;

    for (int i = 0; i < iterations; ++i) {
        // move one disk
        system.step();
        // save a configuration
        system.save("confs/conf"+std::to_string(i));
    }
    return 0;
}