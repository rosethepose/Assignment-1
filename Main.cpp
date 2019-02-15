#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "DNA.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc >= 2)
  {
    char option;
    char* path = argv[1];                                                         //text file path name
    ofstream out;                                                                 //create the out stream
    out.open("rose.out", ofstream::trunc);                                        //open the file, delete contents
    out << "Name: Rose Ramirez" << endl;
    out << "ID: 2317195" << endl;
    out << "Email: roramirez@chapman.edu" << endl;
    do
    {
      //read text file
      string readLine;                                                            //char* holding place when reading line
      ifstream read;                                                              //create the input stream
      read.open(path, ifstream::in);                                              //open file
      getline(read, readLine);                                                    //read line into readLine
      int lineCount = 0;                                                          //count keeps track of line number, for looping
      string lines = "";                                                          //lines will hold all nucleotide values

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

      out << strand.print() << endl;                                              //print the contents of the strand
      out << "Length: " << strand.length() << endl;                               //print the length of the strand

      out << "Probability of A: " << strand.probNucleotide('a') << endl;          //probability of eac nucleotide
      out << "Probability of C: " << strand.probNucleotide('c') << endl;
      out << "Probability of T: " << strand.probNucleotide('t') << endl;
      out << "Probability of G: " << strand.probNucleotide('g') << endl;

      out << "Probability of AA: " << strand.probBigram("aa") << endl;            //probability of each bigram
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
      srand(time(0));                                                             //seed random values
      double a, b;                                                                //placeholders for random values
      string s = "";                                                              //string to become the new strand
      for(int i = 0; i < 1000; ++i)
      {
        a = (double)rand() / RAND_MAX;                                            //calcuate random numbers, 0 < rand / rand_max < 1
        b = (double)rand() / RAND_MAX;
        s += strand.generate(a, b) + "\n";                                        //append to strand
      }
      DNA strand2 = DNA(s);                                                       //create the new DNA strand
      out << strand2.print();                                                     //print thenew strand
      out << "Probability of A: " << strand2.probNucleotide('a') << endl;         //calc new probabilities to compare
      out << "Probability of C: " << strand2.probNucleotide('c') << endl;
      out << "Probability of T: " << strand2.probNucleotide('t') << endl;
      out << "Probability of G: " << strand2.probNucleotide('g') << endl;

      cout << "Would you like to read another file? (Y/N) ";                      //option to read another file
      cin >> option;
      if(option == 'n' || option == 'N')                                          //if no, exit and close out stream
      {
        out.close();
        return 0;
      }
      if(option == 'Y' || option == 'y')                                          //if user says yes, ask for file name
      {
        cout << "File Name: ";
        cin >> path;
      }
    } while(option != 'n' || option != 'N');
  }
  return 0;
}
