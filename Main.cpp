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
    string lines = "";                                                          //lines will hold all nucleotide values

    if(read.eof())
      cout << "error" << endl;
    while(!read.eof())                                                          //read file until finished
    {
      if(readLine.back() == '\r')                                               //pop carriage returns from text file
        readLine.pop_back();                                                    //thanks jin, give him some extra credit :)
      lines += readLine + ",";                                                  //string holding all lines, delimeted by ','
      lineCount++;                                                              //increment line count
      getline(read, readLine);                                                  //read next line
    }
    read.close();                                                               //close stream
    DNA strand = DNA(lines);                                                    //initialize DNA strand
    for(int i = 0; i < lineCount; i++)
    {

    }
    cout << "Length: " << strand.length() << endl;

    cout << "Probablity of A: " << strand.probNucleotide('a') << endl;
    cout << "Probablity of C: " << strand.probNucleotide('c') << endl;
    cout << "Probablity of T: " << strand.probNucleotide('t') << endl;
    cout << "Probablity of G: " << strand.probNucleotide('g') << endl;

    cout << "Probablity of AA: " << strand.probBigram("aa") << endl;
    cout << "Probablity of AC: " << strand.probBigram("ac") << endl;
    cout << "Probablity of AT: " << strand.probBigram("at") << endl;
    cout << "Probablity of AG: " << strand.probBigram("ag") << endl;
    cout << "Probablity of CA: " << strand.probBigram("ca") << endl;
    cout << "Probablity of CC: " << strand.probBigram("cc") << endl;
    cout << "Probablity of CT: " << strand.probBigram("ct") << endl;
    cout << "Probablity of CG: " << strand.probBigram("cg") << endl;
    cout << "Probablity of TA: " << strand.probBigram("ta") << endl;
    cout << "Probablity of TC: " << strand.probBigram("tc") << endl;
    cout << "Probablity of TT: " << strand.probBigram("tt") << endl;
    cout << "Probablity of TG: " << strand.probBigram("tg") << endl;
    cout << "Probablity of GA: " << strand.probBigram("ga") << endl;
    cout << "Probablity of GC: " << strand.probBigram("gc") << endl;
    cout << "Probablity of GT: " << strand.probBigram("gt") << endl;
    cout << "Probablity of GG: " << strand.probBigram("gg") << endl;

    cout << "Mean: " << strand.mean() << endl;
    cout << "Standard Deviation: " << strand.deviation() << endl;
    cout << "Variance: " << strand.variance() << endl;
    cout << "Sum: " << strand.sum() << endl;
  }
  return 0;

}
