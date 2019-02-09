#include <iostream>
#include <fstream>
#include <string>
#include "DNA.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc >= 2)
  {
    //read text file
    //string path = "dna.txt";
    char* path = argv[1];                                                       //text file path name
    char* readLine;                                                             //char* holding place when reading line
    ifstream read;
    read.open(path, ifstream::in);                                              //open file
    read.getline(readLine, 256);                                                //read line into readLine
    int lineCount = 0;                                                          //count keeps track of line number, for looping
    char* lines = (char*) malloc(100000);
    while(read.good())                                                          //read file until finished
    {
      lines += (readLine, '\n');                                                 //string holding all lines, delimeted by \n
      cout << readLine << endl;
      lineCount++;                                                              //increment line count
      read.getline(readLine, 256);                                              //read next line
    }
    read.close();                                                               //close stream
    for(int i = 0; i < lineCount; i++)
    {

    }
    return 0;
  }
}
