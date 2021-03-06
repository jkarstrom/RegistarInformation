//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Window.h"

//default constructor
Window::Window(){
    student = false;
    timeLeft = 0;
    idleTime = 0;
}

//deconstructor
Window::~Window(){

}

bool Window::isOccupied(){
    return student;
}

void Window::getStudent(Student myStudent){
    student = true;
    timeLeft = myStudent.getWindowTime();
    idleTime = 0;
}

int Window::reduceTime(){
    return --timeLeft;
}

int Window::getIdleTime(){
    return idleTime;
}

void Window::plusIdleTime(){
    idleTime++;
}

bool Window::equals(Window other){
    bool compare = false;
    if(timeLeft == other.timeLeft){
        compare = true;
    }
    return compare;
}
