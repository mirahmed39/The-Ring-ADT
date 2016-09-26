#include <iostream>
#include <string>
#include "Ring.hpp"
#include "RingInterface.hpp"
#include "DNA.hpp"
#include "Weighable.hpp"
#include "WeighableInterface.hpp"
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    Ring DNA_Container(20);
    string dna; // holds the sequence from an external file.

    ifstream myFile("dna_sequences.txt");
    //filling the DNA_Container with DNA objects.
    while(!myFile.eof() && myFile >> dna)
    {
        DNA DNA_Object;
        DNA_Object.setSequence(dna);
        DNA_Object.setWeight(dna);
        DNA_Container.set(DNA_Object);
        DNA_Container.moveNext();
    }
    myFile.close();

    DNA_Container.moveTokthLargestDNA(0, DNA_Container.getElementCount()-1, 5);
    cout << "The  5th largest DNA sequence is : ";
    DNA_Container.get().printBrief();


    DNA_Container.moveTokthLargestDNA(0, DNA_Container.getElementCount()-1, 10);
    cout << "\nThe 10th largest DNA sequence is : ";
    DNA_Container.get().printBrief();

    DNA_Container.moveTokthLargestDNA(0, DNA_Container.getElementCount()-1, 15);
    cout << "\nThe 15th largest DNA sequence is : ";
    DNA_Container.get().printBrief();

    return 0;
}

