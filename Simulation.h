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
    Simulation();//default constructor
    ~Simulation();//deconstructor

    //core functions
    void run(string fileName);

    //aux functions
    void update();
    void updateStudentStats(int waitTime);
    void updateWindowStats(int idleTime);
    void printStats();

private:
    //vars 
    int clockTick;
    int studentIn;

    int totalStudents;
    float meanWait;
    int allWaits[100];
    int nStudent;
    int medianWait;
    int longestWait;
    int longWaits;

    int totalWindows;
    float meanIdle;
    int longestIdle;
    int longIdle;

    Registar *myRegistar;
};

#endif
