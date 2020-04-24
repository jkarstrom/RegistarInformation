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
  if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
      int i = std::stoi(line);
      data[idx] = i;
      idx++;
      if(isDidget(data[idx] == false))
      {
        cout << "file contained char that is not an int";
        inputFile.close();
      }
    }
    inputFile.close();
  }
  else cout << "Unable to open file";
}

int FileIO::getNext(){
    return data[curr++];
}

bool FileIO::moreLines(){
    return !(curr == idx);
}
