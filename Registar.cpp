//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Registar.h"

//default constructor
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

void Registar::increaseTimes(){


    GenQueue<Student> *holdingS = new GenQueue<Student>();
    // increase wait times
    while(!myStudents->isEmpty()){

        Student temp = Student();
        temp = myStudents->remove();
        temp.plusWaitTime();
        holdingS->insert(temp);
    }
    while(!holdingS->isEmpty()){
        myStudents->insert(holdingS->remove());
    }
    delete holdingS;

    GenQueue<Window> *holdingW = new GenQueue<Window>();
    // increase idle times
    while(!idleWindows->isEmpty()){
        Window temp = Window();
        temp = idleWindows->remove();
        temp.plusIdleTime();
        holdingW->insert(temp);
    }
    while(!holdingW->isEmpty()){
        idleWindows->insert(holdingW->remove());
    }

    // update idle windows
    while(!workingWindows->isEmpty()){
        Window temp = Window();
        temp = workingWindows->remove();
        if(temp.reduceTime() == 0){

            idleWindows->insert(temp);
        }
        else
            holdingW->insert(temp);
    }

    while(!holdingW->isEmpty()){
        workingWindows->insert(holdingW->remove());
    }
    delete holdingW;
}

bool Registar::checkWindows(){
    return (!idleWindows->isEmpty());
}

bool Registar::allOpen(){
    return (workingWindows->isEmpty());
}

bool Registar::checkLine(){
    return (!myStudents->isEmpty());
}

int Registar::clearWindows(){
    int num = 0;
    if(!idleWindows->isEmpty()){
        num = idleWindows->remove().getIdleTime();
    }
    return num;
}
