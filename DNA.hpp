#ifndef DNA_H
#define DNA_H
/**
 @author: Mir Ahmed.
 @class DNA
 @details: The DNA class is made to hold DNA sequence. The
 private data member sequence which is of type string will store
 DNA sequences collected from an external file. Each sequence in the
 DNA object will have corresponding weights.
*/

#include<string>
#include "Weighable.hpp"
using namespace std;

class DNA : public Weighable
{
public:
    /**
        default constructor. Sets the member variable
        sequence to an empty string an weight of 0.
    */
    DNA();

    /** validates if the sequence conforms the rules
        of writing a sequence
        @param - dnaSequence - a dna sequence of type string
        that has to be checked
        @return - returns true if the sequence is correctly
        written. */
    bool sequenceValidation(const string& dnaSequence);

    /**
        explicit constructor. Sets the member variable
        sequence to string that user inputs.
        @param - dnaSequence sets the member variable
        sequence to dnaSequence.
    */
    DNA(const string& dnaSequence);

    /**
        Tells whether the sequence is empty or not.
    */
    bool isEmpty();

    /**
        sets the sequence to a value that user inputs.
        @param - value - string value that user inputs.
    */
    void setSequence(const string& value);


     /**
        sets the weight of the sequence.
    */
    void setWeight(const string& dnaSequence);

    /**
        accesses the sequence.
    */
    string  getSequence()  const;

    /**
        accesses the weight. DNA class inherits this member function
        from the weighable class and overwrites it in DNA implementation.
    */
    double getWeight() const;

    /**
        operator overloading. we will need it in
        recursive algorithm when we set one DNA
        object equal to another.
        @note only for programmers */
    DNA& operator =(const DNA& right);

    /**
        prints the first ten characters of a dnaSequence.
    */
    void printBrief();

    /**
        this clears up the sequence. In other words,
        sets the member variable to an empty string and
        weight to 0.
    */
    void clear();

private:
    //data members
    string sequence;
    double weight;
};

#endif // DNA_H
