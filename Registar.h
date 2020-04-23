//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef REGISTAR_H
#define REGISTAR_H
#include "GenQueue.h"

class Registar{
public:
    Registar();
    ~Registar();

    void addStudent(); // add student to line
    void moveStudent(); // remove student from line
    void openWindow(); // open new window

private:
    GenQueue *myStudents;
    GenQueue *idleWindows;
    GenQueue *workingWindows;
};

#endif
