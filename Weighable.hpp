#ifndef WEIGHABLE_BASE_CLASS
#define WEIGHABLE_BASE_CLASS

#include "WeighableInterface.hpp"

/**
 * @class Weighable is a concrete base implementation of WeighableInterface
 *
 */
class Weighable: public WeighableInterface {
  /**
   * this should be overridden by a child class
   *@return returns a double value that represents weight
   */ 
  virtual double getWeight() { return 0; }
};

#endif
