#include "DNA.hpp"
#include<cstring>
#include <string>
#include<cctype>
#include<cstdlib>
#include<exception>
#include <iostream>
using namespace std;
DNA::DNA()
{
    sequence = "";
    weight = 0;
}

bool DNA::sequenceValidation(const string& dnaSequence)
{
    /** we need to traverse the sequence to check whether it conforms to all the rules. */
    for(int i = 0; i < dnaSequence.length(); i++)
    {
        while(!isupper(dnaSequence[i]) || (dnaSequence[i] != 'A' && dnaSequence[i] != 'G' && dnaSequence[i] != 'T' && dnaSequence[i] != 'C') || (dnaSequence.length() < 10))
             return false;
    }
    return true;
}

DNA::DNA(const string& dnaSequence)
{
    bool success = sequenceValidation(dnaSequence);
    if(!success)
    {
        cout << "ERROR:: DNA Sequence must be composed of one of the following upper case letters(A,G,T,C)"
             << " and must be consisted of ten characters or more" << endl;
        exit(1);
    }
    sequence = dnaSequence;
}

bool DNA::isEmpty()
{
    return sequence.empty();
}

void DNA::setSequence(const string& strSequence)
{
    bool success = sequenceValidation(strSequence);
    if(!success)
    {
        cout << "ERROR:: DNA Sequence must be composed of one of the following upper case letters(A,G,T,C)"
             << " and must be consisted of ten characters or more" << endl;
        exit(1);
    }
    sequence = strSequence;
}

void DNA:: setWeight(const string& dnaSequence)
{
    double sum = 0;
    for(int i = 0; i < dnaSequence.length(); i++)
    { /** the of the letter are predetermined. */
        if(dnaSequence[i] == 'A')
            sum+= 1.6;
        else if(dnaSequence[i] == 'G')
            sum+= 2.2;
        else if(dnaSequence[i] == 'T')
            sum+= 1.23;
        else if(dnaSequence[i] == 'C')
            sum+= 1.55;
    }
    weight = sum;
}

string DNA:: getSequence() const
{
    return sequence;
}

double DNA::getWeight() const
{
    return weight;
}

DNA& DNA::operator =(const DNA& right)
{
    sequence = right.getSequence();
    weight = right.getWeight();
}

void DNA::printBrief()
{
        cout << sequence.substr(0,10);
}
void DNA::clear()
{
    setSequence("");
    weight = 0;
}












