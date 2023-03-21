 // Author(s): Ankur Gupta
// File: bitarray.h
// Compiler: g++
// Contents: A standard bit array, supporting set and unset.
//           Also includes functions as if it were a finite subset of
//           integers from 0...n.
// The BitArray class represents an integer element as a single bit in a long character array of bits.
// The idea is that the number 23, for example, is represented as either 0 (not in the array) or 1 (in the array)
// The value of such a data structure is to save space used. A normal int typically requires 32 bits, but we are now
// writing each number down in just one bit. So much win!

#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>
using namespace std;

class BitArray {

    protected:
       int LENGTH;                              // length of bit array in terms of bits
       int BYTES;                               // number of bytes required for bit array
       char * data;                             // the bit array itself

    public:
       // Class maintenance details
       BitArray(int = 0);                       // constructor, input number of bits (default = 0)
       void clear();                            // set all bits to 0
       void initialize(char *);                 // given a character string, copy its contents to the BitArray

       ~BitArray();                             // default destructor

       // Allow read access to protected variable names
       inline int length() const {return LENGTH;}
       inline int bytes() const {return BYTES;}

       // This function allows easy printing of a bit array
       // This is an overloaded operator for the <<, so that you can cout a BitArray
       // You may wish to write a separate print function if you find this one is not very helpful.
       friend ostream & operator << (ostream &, BitArray &);

       // Bit read/write functions
       char get(int p);                        // returns the value of the bit at position p 
       bool set(int p, int b=1);               // sets a bit b (default 1) at position p. You cannot use get inside this function!
       bool flip(int p);                       // flips the bit at position p
       
       // Functions that operate on the whole array
       void complement();                      // flips 1's and 0's in bit array

       // Implement this function in the phase where it instructs you to do so. Until then, leave it unwritten.
       char get8(int p);      // return a char that contains the decimal version of the bit interval [p,p+8).
       // Hint: You may need to recast the return value of get to treat it like an unsigned int, but the char return value will be useful.
       
}; // end class BitArray

#endif
