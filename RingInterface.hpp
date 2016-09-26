#ifndef RING_INTERFACE
#define RING_INTERFACE

#include "DNA.hpp"


class RingInterface
{
public:
  virtual void set(const DNA& value) = 0;
  virtual DNA get() = 0;
  virtual int getReferenceIndex() const = 0;
  virtual bool remove() = 0;
  virtual void moveReference(int positions) = 0;
  virtual void moveNext() = 0;
  virtual void movePrevious() = 0;
  virtual int getElementCount() const = 0;
  virtual int getRingSize() const = 0;
  virtual void clearRing() = 0;

 /**
     - finds the kth largest weight from the DNA array and then moves the reference
     to the corresponding DNA Object.
     @param
        k- indicates what largest value user wants to search for.
        first - the first index of the array
        last - the last index of the array.
     @post  it is very very important to know for the PROGRAMMER
        that this algorithm rearranges the original array(elements in this case).
        So, when checking(programmer) if the algorithm actually works, in this case, looking
        at the kth largest dna sequence by the weight provided by the algorithm in the ORIGINAL
        ARRAY will most likely not match. Even if it matches, it's nothing other than a coincidence.*/
  virtual void moveTokthLargestDNA(int first, int last, int k) = 0;

};
#endif
