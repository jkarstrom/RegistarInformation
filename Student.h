//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include <iostream>
using namespace std;

class Student
{
public:
  Student();//default constructor
  Student(int winT);//overload constructor
  ~Student();//deconstructor

  //core functions
  bool isServed();

  //aux functions
  int getWindowTime();
  int getWaitTime();
  void plusWaitTime();
  bool equals(Student other);

private:
  //vars
  int windowTime;
  int waitTime;
  bool serviced;
};
