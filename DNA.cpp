#include <string>
#include <ctype.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "DNA.h"
using namespace std;
DNA::DNA() { }
DNA::DNA(string seq)
{
  delimetedseq = seq;
  for(int i = 0; i < seq.length(); ++i)
    if(seq[i] != ',')
      sequence += seq[i];                                                  //remove delimeters
}
double DNA::sum()
{
  return length();
}
double DNA::mean()
{
  int temp = 0;                                                            //keep track of number of delimeters
  for(int i = 0; i < delimetedseq.length(); ++i)                           //parse thru delimeted sequence, dummy
    if(delimetedseq[i] == ',')
      temp++;
  return (double)length() / temp;                                          //mean = number of elements / number of lines
}
double DNA::variance()
{
  return pow(deviation(), 2);                                              //variance^2 = standard deviation
}
double DNA::deviation()
{
  int count = 0;                                                           //count keeps track of the length of a line
  double sum = 0;                                                          //stores the sum
  double m = mean();                                                       //store the mean so I only need to comupte once
  for(int i = 0; i < delimetedseq.length(); ++i)
  {
    if(delimetedseq[i] != ',')
      count++;                                                             //increment the line length
    else                                                                   //count now stores the value of the length of a line
      sum += pow(count - m, 2);                                            //add the mean - length^2 to the sum
  }
  return sqrt(sum / length());
}
int DNA::length()
{
  return sequence.length();                                                //since sequence holds only nucleotides, we can use that length
}
double DNA::probNucleotide(char n)
{
  toupper(n);
  int count = 0;                                                           //keeps track of occurrences of the nucleotide
  for(int i = 0; i < length(); ++i)
    if(sequence[i] == n || toupper(sequence[i]) == toupper(n))
      count++;                                                             //increment occurences
  return (double)count / length();                                         //prob = number of occurences / number of elements
}
double DNA::probBigram(string b)
{
  int count = 0;                                                           //keep track of bigram occurences
  for(int i = 0; i < length()-1; i+=2)                                     //loop thru every other nuceleotide
    if(sequence[i] == b[0] && sequence[i+1] == b[1]
      || toupper(sequence[i]) == toupper(b[0]) && toupper(sequence[i+1]) == toupper(b[1]))
      count++;                                                             //increment occurences
  return (double)count / length();                                         //prob = number of occurences / number of elements
}
string DNA::print()
{
  string s;
  for(int i = 0; i < delimetedseq.length(); ++i)
  {
    if(delimetedseq[i] == ',')                                             //replace delimeters with new line
      s += "\n";
    else
      s += delimetedseq[i];
  }
  return s;
}
double DNA::gaussian(double a, double b)
{
  double g = sqrt(-2 * log(a) * cos(2*M_PI*b));                            //C = sqrt(-2 ln (a)) * cos(2πb)
  if(g < 0)
    return g * -1;
  return g;
}
int DNA::calcLength(double a, double b)
{
  return (deviation() * gaussian(a, b)) + mean();                          //D = deviation*gaussian / mean
}
string DNA::generate(double a, double b)
{
  string line = "";
  double length = calcLength(a, b);                                        //calculate length only once
  int numA = 0;                                                            //keep track of amnt of each nucleotide
  int numC = 0;
  int numT = 0;
  int numG = 0;
  double probA = probNucleotide('a');                                      //keep track of probabilities, so I only have to calcuate once
  double probC = probNucleotide('c');
  double probT = probNucleotide('t');
  double probG = probNucleotide('g');
  for(int i = 0; i < length; ++i)
  {
    int nucleotide = rand() % 4;                                           //random number from 0-4
    if(nucleotide == 0)
    {
      if(numA / length < probA)                                            //check if probability is valid
      {
        line += "a";                                                       //add the nucleotide to the string
        numA++;                                                            //increment the occurrence
      }
      else
        i--;                                                               //go back an iteration and recalculate
    }
    else if(nucleotide == 1)
    {
      if(numC / length < probC)
      {
        line += "c";
        numC++;
      }
      else
        i--;
    }
    else if(nucleotide == 2)
    {
      if(numT / length < probT)
      {
        line += "t";
        numT++;
      }
      else
        i--;
    }
    else if(nucleotide == 3)
    {
      if(numG / length < probG)
      {
        line += "g";
        numG++;
      }
      else
        i--;
    }
  }
  return line;
}
