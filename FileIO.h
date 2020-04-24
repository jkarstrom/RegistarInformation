//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class FileIO
{
public:

  FileIO();//default constructor
  ~FileIO();//deconstructor

  //core functions
  void openFile(string f);

  //aux functions
  int getNext();
  bool moreLines();

private:
  //vars
  string line = "";
  int idx = 0;
  int curr = 0;
  int data[100];
};
