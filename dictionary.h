// Author(s): Will Vesevick & David Fugate
// File: dictionary.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A dictionary class that supports rank, select, rank_range, and select_range

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "bitarray.h"

class Dictionary {
    // You will need some private variables to set up the lookup tables when you get to that part.
    private:
      int stored [256];

    protected:
       BitArray data;

    public:
       // Class maintenance details
       Dictionary();                                        // constructor
       void initialize(char *);                             // given a character string, set the data appropriately

       ~Dictionary();                                       // default destructor

       // Core functionality is below this comment
       void fillDic();
       void printDic();
       
       // Some examples of how rank and select functions work are below the #endif.
       // Naive rank/select in a range
       int rank_range(int i, int j, int b = 1);             // computes how many of the bit b are in the interval [i,j), defaults to (b=1)
       int select_range(int i, int j, int k, int b = 1);    // returns the position of the kth bit b in the interval [i,j), defaults to (b=1)
 
       // rank/select using a lookup table
       int rank(int j, int b = 1);                          // computes how many of the bit b are in the interval [0,j), defaults to (b=1)
       int select(int k, int b = 1);                        // returns the position of the kth bit b in the dictionary, defaults to (b=1)

}; // end class Set

#endif

/*
Suppose you have the following sequence of bits:
0101010101011101010100100101101010
The positions in the range default to the standard array conventions starting from 0.
rank_range(3, 10, 1) = 4
select_range(3, 10, 3) = 7
rank(10) = rank(0, 10) = 5
select(3, 0) = 4 
*/
