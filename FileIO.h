#include <iostream>
#include <fstream>
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

using namespace std;

class FileIO
{
public:

  FileIO();//default constructor
  ~FileIO();//deconstructor

  //core functions
  void openFile(string f);

  //aux functions

private:
  //vars
  string line;
};
