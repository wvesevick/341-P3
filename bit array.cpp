#include "bitarray.h"

#include <iostream>
#include <fstream>
using namespace std;

BitArray::BitArray(int size){
   // is size supposed to be the maximum number you eventually want
   // BitArray only holds numbers?
    LENGTH = size;
    BYTES = LENGTH/8;
    data = new char [BYTES];
}

BitArray::~BitArray(){
    delete [] data;
}

//return any char like 00000001 or 00010000 to show that it is in the array
char BitArray::get(int p){
   int byte = p/8;
   int bit = p%8;

   uint8_t mask = (1 << (8 - bit - 1));

   return (data[byte] & mask);
}

void BitArray::clear(){
   for(int x=0; x < BYTES; x++){
      data[x] = 0;
   }
}

void BitArray::initialize(char * tempArray){
   for(int x=0; x<BYTES; x++){
      data[x] = tempArray[x];
   }
}

bool BitArray::set(int p, int b){
   int byte = p/8;
   int bit = p%8;
   uint8_t mask = (1 << (8 - bit - 1 ));

   data[byte] = (data[byte] | mask);

   return true;
}

bool BitArray::flip(int p){
   int byte = p/8;
   int bit = p%8;

   uint8_t mask = (1 << (8 - bit - 1 ));
   
   data[byte] = (data[byte] ^ mask);

   return true;
}

void BitArray::complement(){
   for(int x = 0; x < BYTES; x++){
      data[x] = ~data[x];
   }
}

//supposed to get 8 bits and return the char that it makes
char BitArray::get8(int p){
   int byte = p/8;

   return data[byte];
}

// Move this to bitarray.cpp. It won't work until you've written the get function.

ostream& operator << (ostream& out, BitArray & array) {
   int NUMPERLINE = 6;
   int numPrinted = 0;
   for (int x = 0; x < array.length(); x++) {
      if (array.get(x)) {
         out.width(4);
         out << x;
         numPrinted++;
         if (numPrinted % NUMPERLINE == 0)
            out << "\n";
      } // end if
   } // end for
   return out;
} // end ostream & operator <<
