//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Registar.h"

Registar::Registar(){
    myStudents = new GenQueue<Student>();
    idleWindows = new GenQueue<Window>();
    workingWindows = new GenQueue<Window>();
}

void Registar::addStudent(Student newStudent){
    myStudents->insert(newStudent);
}

int Registar::moveStudent(){
    Window open = idleWindows->remove();
    Student next = myStudents->remove();
    open.getStudent(next);
    workingWindows->insert(open);
    return open.getIdleTime();
}

int Registar::studentStats(){
    Student first = myStudents->peek();
    return first.getWaitTime();
}

void Registar::openWindow(){
    Window *newWindow = new Window();
    idleWindows->insert(*newWindow);
}

bool Registar::checkWindows(){
    return (!idleWindows->isEmpty());
}

bool Registar::checkLine(){
    return (!myStudents->isEmpty());
}
