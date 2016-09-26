#ifndef WEIGHABLE_INTERFACE
#define WEIGHABLE_INTERFACE
/**
 * @author sadat.chowdhury@hunter.cuny.edu
 * @class WeighableInterface
 * @brief An interface for things that have weight
 * @detail
 * Weighable is an interface that defines just  a single method 
 * that returns a weight (in double)
 * 
 * Any concrete class that implements the Weihable interface must 
 * provide its own appropriate overriden version
 */

class WeighableInterface {
  /**
   *@return returns a double value that represents weight
   */ 
  virtual double getWeight() = 0;
};

#endif
