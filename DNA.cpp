#include <string>
#include <ctype.h>
#include <iostream>

#include "DNA.h"
using namespace std;
DNA::DNA()
{

}
DNA::DNA(string seq)
{
  sequence = seq;
  //cout << sequence;
}
double DNA::sum()
{
  return 0;
}
double DNA::mean()
{
  return 0;
}
double DNA::variance()
{
  return 0;
}
double DNA::deviation()
{
  return 0;
}
int DNA::length()
{
  return sequence.length();
}

double DNA::probNucleotide(char n)
{
  int count = 0;
  for(int i = 0; i < length(); ++i)
  {
    if(sequence[i] == n)
    {
      count++;
    }
  }
  return (double)count / length();
}
double DNA::probBigram(string b)
{
  int count = 0;
  for(int i = 0; i < length()-1; i+=2)
  {
    if(sequence[i] == b[0] && sequence[i+1] == b[1])
    {
      count++;
    }
  }
  return (double)count / length();
}
