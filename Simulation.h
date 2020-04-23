//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef SIMULATION_H
#define SIMULATION_H
#include "Registar.h"
#include "FileIO.h"

class Simulation{
public:
    Simulation();
    ~Simulation();

    void run(string fileName);

private:
    int clockTick;

    float meanWait;
    int medianWait;
    int longestWait;
    int longWaits;
    float meanIdle;
    int longestIdle;
    int longIdle;

    Registar *myRegistar;
};

#endif
