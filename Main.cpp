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
    char* path = argv[1];                                                       //text file path name
    string readLine;                                                            //char* holding place when reading line
    ifstream read;
    read.open(path, ifstream::in);                                              //open file
    getline(read, readLine);                                                    //read line into readLine
    int lineCount = 0;                                                          //count keeps track of line number, for looping
    string lines = "";

    if(read.eof())
      cout << "error" << endl;
    while(!read.eof())                                                          //read file until finished
    {
      if(readLine.back() == '\r')
        readLine.pop_back();                                                    //thanks jin, give him some extra credit :)
      lines += readLine;                                                        //string holding all lines, delimeted by \n
      lineCount++;                                                              //increment line count
      getline(read, readLine);                                                  //read next line
    }
    read.close();                                                               //close stream
    DNA strand = DNA(lines);
    for(int i = 0; i < lineCount; i++)
    {

    }
    cout << "Length: " << strand.length() << endl;
    cout << "Probablity of A: " << strand.probNucleotide('a') << endl;
    cout << "Probablity of C: " << strand.probNucleotide('c') << endl;
    cout << "Probablity of T: " << strand.probNucleotide('t') << endl;
    cout << "Probablity of G: " << strand.probNucleotide('g') << endl;

  }
  return 0;

}
