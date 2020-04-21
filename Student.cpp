#include "Student.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

using namespace std;

//default constructor
Student::Student()
{

}

//overload constructor
Student::Student(int winT, int waitT)
{
  windowTime = winT;
  waitTime = waitT;
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
