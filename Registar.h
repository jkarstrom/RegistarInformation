//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef REGISTAR_H
#define REGISTAR_H
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"

class Registar{
public:
    Registar();//default constructor
    ~Registar();//deconstructor

    void addStudent(Student newStudent); // add student to line
    int moveStudent(); // remove student from line
    int studentStats(); // update stats with first student in line
    void openWindow(); // open new window

    bool checkWindows(); // see if there are any windows open
    bool checkLine(); // see if there are any students in line

private:
    //vars
    GenQueue<Student> *myStudents;
    GenQueue<Window> *idleWindows;
    GenQueue<Window> *workingWindows;
};

#endif
