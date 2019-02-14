#include <string>
#include <ctype.h>
#include <iostream>
#include <cmath>
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
  return (double)length() / temp;
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
  return pow(sum / length(), .5);
}
int DNA::length()
{
  return sequence.length();                                                //since sequence holds only nucleotides, we can use that length
}
double DNA::probNucleotide(char n)
{
  int count = 0;                                                           //keeps track of occurrences of the nucleotide
  for(int i = 0; i < length(); ++i)
    if(sequence[i] == n)
      count++;                                                             //increment occurences
  return (double)count / length();                                         //prob = number of occurences / number of elements
}
double DNA::probBigram(string b)
{
  int count = 0;                                                           //keep track of bigram occurences
  for(int i = 0; i < length()-1; i+=2)                                     //loop thru every other nuceleotide
    if(sequence[i] == b[0] && sequence[i+1] == b[1])
      count++;                                                             //increment occurences
  return (double)count / length();                                         //prob = number of occurences / number of elements
}
