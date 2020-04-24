//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "Student.h"
using namespace std;

class Window{
public:

    Window();
    ~Window();

    bool isOccupied();
    void getStudent(Student myStudent);
    int reduceTime();
    int getIdleTime();
    void plusIdleTime();

    bool equals(Window other);

private:
    bool student;
    int timeLeft;
    int idleTime;

};

#endif
