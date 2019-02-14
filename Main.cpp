#include <iostream>
#include <fstream>
#include <string>
#include "DNA.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc >= 2)
  {
    char option;
    char* path = argv[1];                                                       //text file path name
    ofstream out;
    out.open("rose.out", ofstream::trunc);
    out << "Name: Rose Ramirez" << endl;
    out << "ID: 2317195" << endl;
    out << "Email: roramirez@chapman.edu" << endl;
    do
    {
      //read text file
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


      out << strand.print() << endl;
      out << "Length: " << strand.length() << endl;

      out << "Probability of A: " << strand.probNucleotide('a') << endl;
      out << "Probability of C: " << strand.probNucleotide('c') << endl;
      out << "Probability of T: " << strand.probNucleotide('t') << endl;
      out << "Probability of G: " << strand.probNucleotide('g') << endl;

      out << "Probability of AA: " << strand.probBigram("aa") << endl;
      out << "Probability of AC: " << strand.probBigram("ac") << endl;
      out << "Probability of AT: " << strand.probBigram("at") << endl;
      out << "Probability of AG: " << strand.probBigram("ag") << endl;
      out << "Probability of CA: " << strand.probBigram("ca") << endl;
      out << "Probability of CC: " << strand.probBigram("cc") << endl;
      out << "Probability of CT: " << strand.probBigram("ct") << endl;
      out << "Probability of CG: " << strand.probBigram("cg") << endl;
      out << "Probability of TA: " << strand.probBigram("ta") << endl;
      out << "Probability of TC: " << strand.probBigram("tc") << endl;
      out << "Probability of TT: " << strand.probBigram("tt") << endl;
      out << "Probability of TG: " << strand.probBigram("tg") << endl;
      out << "Probability of GA: " << strand.probBigram("ga") << endl;
      out << "Probability of GC: " << strand.probBigram("gc") << endl;
      out << "Probability of GT: " << strand.probBigram("gt") << endl;
      out << "Probability of GG: " << strand.probBigram("gg") << endl;

      out << "Mean: " << strand.mean() << endl;
      out << "Standard Deviation: " << strand.deviation() << endl;
      out << "Variance: " << strand.variance() << endl;
      out << "Sum: " << strand.sum() << endl;
      cout << "Would you like to read another file? (Y/N) ";
      cin >> option;
      if(option == 'n' || option == 'N')
      {
        out.close();
        return 0;
      }
      if(option == 'Y' || option == 'y')
      {
        cout << "File Name: ";
        cin >> path;
      }
    } while(option != 'n' || option != 'N');
  }
  return 0;

}
