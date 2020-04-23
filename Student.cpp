//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Student.h"
using namespace std;

//default constructor
Student::Student()
{
    windowTime = 0;
    waitTime = 0;
    serviced = false;
}

//overload constructor
Student::Student(int winT)
{
  windowTime = winT;
  waitTime = 0;
  serviced = false;
}

//deconstructor
Student::~Student()
{

}

bool Student::isServed()
{
  return serviced;
}

int Student::getWindowTime()
{
  return windowTime;
}

int Student::getWaitTime(){
    return waitTime;
}

bool Student::equals(Student other){
    bool compare = false;
    if(windowTime == other->windowTime){
        compare = true;
    }
    return compare;
}
