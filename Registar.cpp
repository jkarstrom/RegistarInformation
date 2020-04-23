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

void Registar::moveStudent(){
    // remove student from queue, assign to first empty window
    if(!myStudents->isEmpty()){
        Window open = idleWindows->remove();
        Student next = myStudents->remove();
        open->assist(next);
        workingWindows->insert(open);
    }
}

void Registar::openWindow(){
    Window *newWindow = new Window();
    idleWindows->insert(newWindow);
    moveStudent();
}
