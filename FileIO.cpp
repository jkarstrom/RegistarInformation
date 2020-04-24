//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "FileIO.h"

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
  int temp = 0;
  if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
      int i = std::stoi(line);
      data[temp] = i;
      cout << line << '\n';
      temp++;
    }
    inputFile.close();
  }
  else cout << "Unable to open file";
}
