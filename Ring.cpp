#include<stdexcept>
#include<cassert>
#include<iostream>
#include "Ring.hpp"
#include "DNA.hpp"
using namespace std;

//----------------- BEGIN CUT HERE: should go in Ring.cpp (part B & C)---------------


Ring:: Ring(): n(DEFAULT_RING_SIZE), elementCount(0),referenceIndex(0) {

    // allocate memory for the dynamic arrays:
    elements = new DNA[n];
    isElementStored = new bool[n];

    // make sure ring is cleared
    clearRing();
}

Ring::Ring(int ringSize): n(ringSize), elementCount(0),referenceIndex(0) {

    // sanity checking ring size
    if( ringSize < 1 ) {
        n = DEFAULT_RING_SIZE;
    }

    // allocate memory
    elements = new DNA[n];
    isElementStored = new bool[n];

    // make sure ring is cleared
    clearRing();
}

void Ring::set(const DNA& value) {
    // if nothing was stored at the location before
    // only then increase count

    if( isElementStored[referenceIndex] == false ) {
        elementCount++;
        isElementStored[referenceIndex] = true;
    }
    elements[referenceIndex] = value;

}

DNA Ring::get() const {
    if( isElementStored[referenceIndex] == true ) {
        return elements[referenceIndex];
    } else {
        throw std::runtime_error("no value at reference");
    }
}

/** this is added by me for debugging purpose */
int Ring::getReferenceIndex() const
{
    return referenceIndex;
}

bool Ring::remove() {
    bool result = true;

    if( isElementStored[referenceIndex] == false ) {
        result = false;
    } else {
        isElementStored[referenceIndex] = false;
        elementCount--;
    }

    return result;
}

void Ring::moveReference(int positions) {
    if( positions != 0 ) {

        if( positions > 0 ) {
            // +ve increment: the mod operation ensures wrapping
            referenceIndex = (referenceIndex + positions) % n;
        } else {
            // negative increment:
            referenceIndex = referenceIndex + (positions % n);
            // correction if the reference index is still -ve
            if( referenceIndex < 0 ) {
                referenceIndex = n + referenceIndex;
            }

        }

    }
}

void Ring::moveNext() {
    moveReference(1);
}

void Ring::movePrevious() {
    moveReference(-1);
}

int Ring::getElementCount() const {
    return elementCount;
}

int Ring::getRingSize() const {
    return n;
}

void Ring::clearRing() {
    for( int i = 0; i < n ; i++ ) {
        isElementStored[i] = false;
    }
    elementCount = 0;
}

void Ring::moveTokthLargestDNA(int first, int last, int k)
{

    int pivot = (first + last)/2;
    /** array[pivot] will have the DNA Object inside.
    So, pivotValue is of type DNA*/
    DNA pivotValue = elements[pivot];

    DNA* s1 = new DNA[last-first];
    DNA* s2 = new DNA[last-first];

    int s1Size = 0,
        s2Size = 0;

    /** partitioning s1 and s2 */
    for(int i = first, indexS1 = 0, indexS2 = 0; i <= last; i++)
    {
        if(i == pivot)
            /** we don't want to include the pivot value, So skip it!!! */
            continue;
        if(elements[i].getWeight() >= pivotValue.getWeight()) //comparing by weights
        {
            /** loading s1 with DNA objects that larger weights than the DNA
            object at pivot. */
            s1[indexS1] = elements[i];
            indexS1++;
            s1Size++;
        }
        else
        {
            /** loading s2 with DNA objects that smaller weights than the DNA
            object at pivot. */
            s2[indexS2] = elements[i];
            indexS2++;
            s2Size++;
        }
    }

    /** putting s1 into array[]
    @note this rearranges the original array (element)*/
    for(int arrayIndex = first, s1Index = 0; s1Index < s1Size; s1Index++, arrayIndex++)
        elements[arrayIndex] = s1[s1Index];

    /** putting the pivot value which is of type DNA after s1 in array[] */
    elements[first+s1Size] = pivotValue;
    /** pivot is changed due to rearrangement */
    pivot = first+s1Size;

    /** putting s2 into array[] after pivot. */
    for(int arrayIndex = first+s1Size+1, s2Index = 0; s2Index < s2Size; s2Index++, arrayIndex++)
        elements[arrayIndex] = s2[s2Index];

    if(k < pivot - first + 1)
        /** this means the size of the s1 array is greater than
        the size of k which in turn means that the kth largest
        value resides on the left portion of the pivot. So we call
        the function again on the array, but this on all the values
        from first to pivot-1. */
        moveTokthLargestDNA(first, pivot-1, k);

    else if(k == pivot - first + 1) //base case
    {
        /** kth largest DNA is at pivot. Now we just use a loop
        to traverse the elements array and compare the weights in
        order to move the reference to the correct position. */
        for(int i = 0; i < elementCount; i++)
        {
            if(get().getWeight() == pivotValue.getWeight())
                /** the reference index is at the pivot. So, exit
                from the loop!!! */
                break;
            else
                /** otherwise keep moving next. */
                moveNext();
        }
    }
    else
        /** this means the size of the s2 array is smaller than
        the size of k which in turn means that the kth largest
        value resides on the right portion of the pivot. So we call
        the function again on the array, but this on all the values
        from pivot+1 to last.
        @note - notice that the largest value we are looking for has been
        adjusted. This because th larger value on the left portion
        of array are not taken into into account anymore. That is reason we
        subtract them from k.*/
        moveTokthLargestDNA(pivot+1, last, k-(pivot- first+1));
}

Ring::~Ring() {
    delete[] elements;
    delete[] isElementStored;
}

