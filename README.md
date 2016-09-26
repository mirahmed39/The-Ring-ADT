# The-Ring-ADT
@class Ring
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
