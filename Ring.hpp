#ifndef RING_HPP
#define RING_HPP

//----------------- BEGIN CUT HERE: should go in Ring.hpp (part B & C)---------------
/**
 * @class Ring
 * @brief An ADT that mimics a circular buffer of type T
 * @details
 * An instance of this Ring ADT will have n elements of
 * type T (using generics). The default constructor sets
 * n=10. Once created, a special pointer, called reference
 * points to the first element of the Ring. The reference
 * can be moved to either the next or the previous element
 * locations. Because of circular nature of the ADT, the
 * previous element of the first element is the last element
 * and the next element of the last element is the first
 * element. Once at a reference, values of type T can be
 * stored, retreived, and deleted. The Ring can provide
 * a count of the actual number of values stored.
 */

#include "RingInterface.hpp"
#include "DNA.hpp"


class Ring{
private:
    static const int DEFAULT_RING_SIZE = 20;
    int n;                   // this is the ring's size as noted above
    int elementCount;        // number of elements actually stored
    DNA* elements;             // dynamic array that holds the actual elements
    bool* isElementStored;   // dynamic array that keeps tab whether element is stored
    int referenceIndex;      // index to the dynamic arrays

public:

    /**
     * Default constructor.
     * @post a ring of size DEFAULT_RING_SIZE (10) created.
     *  there are no elements and reference is at the beginning
     */
    Ring();

    /**
     * Parameterized constructor.
     * @param ringSize size of the new ring
     * @post a ring of size ringSize is created.
     *  if ringSize is an invalid size, it is set to DEFAULT_RING_SIZE,
     *  there are no elements, and reference is at the beginning
     */
    Ring(int ringSize);

    /**
     * Stores a value at the current reference
     * @param value a value of type T
     * @post
     *  if the value is non-null, it is stored at the current reference
     *  if the value is null, the element at reference is effectively removed
     *  if there was no previous value at the current reference, the
     *   number of elements is increased by 1
     */
    void set(const DNA& value);

    /**
     * Retrieves the value stored at current reference
     * @post no internal state is modified
     * @return value stored at current reference
     *   if no values were stored at current reference, returns NULL
     */
    DNA get() const;

    /**
     gets the reference Index of its current position. */
    int getReferenceIndex() const;

    /**
     * Removes value stored at current reference
     * @post the element at reference is removed and
     *  element count is decremented
     *  if there was no previous element at reference
     *  element count remains the same
     * @return true if an element was actually
     *  removed; false, otherwise
     */
    bool remove();

    /**
     * Moves reference in either direction
     * @param positions a positive or negative value
     * @post if positions is positive, reference is moved
     * forward and if positions is negative, the reference
     * is moved backward. If positions is 0, nothing is done
     * The new reference is guaranteed to obey circularity
     * @details
     * If positions is +ve, the new index is easily computed
     * by mod'ing the sum of current index and positions.
     * The mod'ing operation guarantees wrap-around across the
     * end of n items.
     * If positions is -ve, computing the new index is a bit
     * more involved. First, large size of positions is adjusted
     * by mod'ing it with n, and then it is added to old index
     * The result might still be negative, which indicates
     * crossing the left border.
     */
    void moveReference(int positions);

    /**
     * Convenience method that moves reference to next element
     * @detail simply calls Ring::moveReference(1)
     * @see Ring::moveReference()
     */
    void moveNext();

    /**
     * Convenience method that moves reference to previous element
     * @detail simply calls Ring::moveReference(-1)
     * @see Ring::moveReference()
     */
    void movePrevious();

    /**
     * Returns the number of elements stored in the ring
     * @return number of elements actually stored
     * @note not to be confused with the size of the ring
     */
    int getElementCount() const;

    /**
     * Returns the size of the ring
     * @return maximum number of elements that can be stored
     */
    int getRingSize() const;

    /**
     * Clears all data stored in the ring
     * @post
     *   attempts to get values from any reference
     *   will throw exception
     *   element count is set 0
     */
    void clearRing();

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
    void moveTokthLargestDNA(int first, int last, int k);

    /**
     * Destructor frees all dynamically allocated memory
     */
    ~Ring();
};


//------------------- END CUT HERE: should go in Ring.hpp (part B & C)---------------

#endif
