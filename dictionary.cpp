#include <iostream>
#include <iomanip>

#include "bitarray.h"
#include "set.h"
#include "dictionary.h"

Dictionary::Dictionary(){

}

Dictionary::~Dictionary(){
    
}

void Dictionary::fillDic(){
    for(int x = 0; x <= 255; x++){
        int numOnes = 0;
        for(int j = (x*8); j < (j+8); j++){
          if(data.get(j) == 1){
              numOnes ++;
          }
      }
      stored[x] = numOnes;
    }
}

void Dictionary::initialize(char * charArray){
  data.initialize(charArray);
}

// computes how many of the bit b are in the interval [i,j), defaults to (b=1)
int Dictionary::rank_range(int i, int j, int b){
    //j is the start of the interval
    //i is the end of the interval
    int temp = 0;
    for(int x = i; x < j; x++){
        if(b == 0 && data.get(x) == 0){
            temp ++;
        }
        if(b == 1 && data.get(x) == 1){
            temp ++;
        }
    }
    return temp;
}

// returns the position of the kth bit b in the interval [i,j), defaults to (b=1)
int Dictionary::select_range(int i, int j, int k, int b){
    //find the kth number 1 in the string
    //(what number is the (5th) number for example)
    int temp = 0;
    int start = i;
    while (temp!=k){
        for (int x = i; x < j; x++){
            if (b == 0 && data.get(x) == 0){
                temp ++;
            }
            else if (b == 1 && data.get(x) == 1){
                temp ++;
            }
        }
    }
    // is this right?
    // do you want the position of the bit in the range or the position of the bit in the entire
    // array
    return start + temp;
}

 // computes how many of the bit b are in the interval [0,j), defaults to (b=1)
int Dictionary::rank(int j, int b){

    int temp = 0;
    for(int x = 0; x < j; x += 8){
        if(b == 0 && data.get8(x) == 0){
            temp ++;
        }
        if(b == 1 && data.get8(x) == 1){
            temp ++;
        }
    }
    return temp;
}

// returns the position of the kth bit b in the dictionary, defaults to (b=1)
int Dictionary::select(int k, int b){
    int position = 0;
    while(k>0){
        k -= stored[position];
        position ++;
    }
    return position;
}

/*
Suppose you have the following sequence of bits:
0101010101011101010100100101101010
The positions in the range default to the standard array conventions starting from 0.
rank_range(3, 10, 1) = 4
select_range(3, 10, 3) = 7
rank(10) = rank(0, 10) = 5
select(3, 0) = 4 
*/
