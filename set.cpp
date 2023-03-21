#include "bitarray.h"
#include "set.h"

#include <iostream>
#include <fstream>
using namespace std;

Set::Set(int size) : data(size){
    CARDINALITY = 0;
}

Set::~Set(){
    //empty
}

BitArray Set::getData(){
  return data;
}

void Set::initialize(char * charArray){
  data.initialize(charArray);
}

// computes the union with the input set and stores it here
// union is the elements that are in EITHER set
bool Set::setUnion(Set & otherSet){
  if(data.length() == otherSet.data.length()){
    for(int x = 0; x < data.length(); x++) {
      if(data.get(x) == 1 || otherSet.data.get(x) == 1) {
        data.set(x,1);
        CARDINALITY++;
      } else {
        data.set(x,0);
      }
    }
  }
  cout << data << endl;
  return true;
}

// computes the intersection with the input set and stores it here
// intersection is the elements that are in BOTH sets
// intersection would be and
bool Set::setIntersection(Set & otherSet) {
  if(data.length() == otherSet.data.length()){
    for(int x = 0; x < data.length(); x++){
      if(data.get(x) == 1 && otherSet.data.get(x) == 1){
        CARDINALITY++;
      } else {
        data.set(x,0);
      }
    }
  }
  cout << data << endl;
  return true;
}

// computes the relative difference between this set and the input set and stores it here
// this would be the elements in otherSet but no in the original set
bool Set::setDifference(Set & otherSet){
  if(data.length() == otherSet.data.length()){
    for(int x = 0; x < data.length(); x++){
      if(data.get(x) == 0 && otherSet.data.get(x) == 1){
        data.set(x,1);
        CARDINALITY++;
      } else {
        data.set(x,0);
      }
    }
  }
  cout << data << endl;
  return true;
}
