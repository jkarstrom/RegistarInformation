//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Window.h"

Window::Window(){
    student = false;
    timeLeft = 0;
    idleTime = 0;
}

Window::~Window(){

}

bool Window::isOccupied(){
    return student;
}

void Window::getStudent(Student myStudent){
    student = true;
    timeLeft = myStudent.getWindowTime;
}

int Window::getIdleTime(){
    return idleTime;
}

bool Window::equals(Window other){
    bool compare = false;
    if(timeLeft == other->timeLeft){
        compare = true;
    }
    return compare;
}
