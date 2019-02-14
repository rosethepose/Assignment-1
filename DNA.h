#include <string>
using namespace std;
class DNA
{
  private:
    string sequence;
    string delimetedseq;
  public:
    DNA();
    DNA(string seq);
    double sum();
    double mean();
    double variance();
    double deviation();
    int length();
    double probNucleotide(char n);
    double probBigram(string b);
    string print();
};
