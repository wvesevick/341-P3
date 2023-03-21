// Author(s): Will Vesevick & David Fugate
// File: set.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A set class that supports union, intersection, and relative complement.

#ifndef SET_H
#define SET_H

#include "bitarray.h"

class Set {

    protected:
       BitArray data;
       int CARDINALITY;
       
    public:
       // Class maintenance details
       Set(int = 0);                            // constructor that builds a BitArray of the indicated size (0 is default)
       void initialize(char *);                 // given a character array, set the data appropriately to match the input character array

       ~Set();                                  // default destructor

       // get/set functions
       inline int cardinality() const;
       BitArray getData();

       // Core functionality
       bool setUnion(Set &);                    // computes the union with the input set and stores it here
       bool setIntersection(Set &);             // computes the intersection with the input set and stores it here
       bool setDifference(Set &);               // computes the relative difference between this set and the input set and stores it here

}; // end class Set

#endif
