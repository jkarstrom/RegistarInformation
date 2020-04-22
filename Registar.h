//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef REGISTAR_H
#define REGISTAR_H
#include "GenQueue.h"

template<class T>
class Registar{
public:
    Registar();
    ~Registar();

private:
    GenQueue *myStudents;
};

#endif
