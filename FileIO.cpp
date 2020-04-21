#include "FileIO.h"
#include <fstream>
#include <string>
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

using namespace std;

FileIO::FileIO()
{
  //default constructor
}

FileIO::~FileIO()
{
  //deconstructor
}

void FileIO::openFile(string f)
{
  ifstream inputFile(f);
  if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
      cout << line << '\n';
    }
    inputFile.close();
  }

  else cout << "Unable to open file";
}
