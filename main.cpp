#include <iostream>
#include <fstream>

#include "dictionary.h"
#include "bitarray.h"
#include "set.h"

using namespace std;

// git add *.cpp *.h *.txt makefile
// git commit -m "finished phase(s)"
// git push origin master

int main () {


    char * charArray = new char[5];
    for(int x=0; x<5; x++){
        charArray[x] = 'a';
    }
    BitArray * testing = new BitArray(40);
    testing->initialize(charArray);
    cout << "Testing Initialize" << endl;
    cout << *testing << endl;
    testing->clear();
    cout << "After Clearing" << endl;
    cout << *testing << endl;
    cout << "After Flips/Sets" << endl;
    testing->set(2);
    testing->flip(3);
    testing->set(5);
    testing->set(28);
    //if testing works it implies get works
    cout << *testing << endl;
    testing->clear();
    cout << endl << *testing << endl;
    testing->complement();
    cout <<"After Complement" << endl;
    cout << *testing << endl;

       Set mySet = Set(24);
    Set otherSet = Set(24);

    char * charArray1 = new char[3];
    for(int x = 0; x < 3; x++){
        charArray1[x] = 0;
    }
    char * charArray2 = new char[3];
    for(int x = 0; x < 3; x++){
        charArray2[x] = 0;
    }


    // **** LOOKUP TABLE *******
    BitArray * dict = new BitArray(2048);
    char * dictArray = new char[256];
    for(int x = 0; x < 256; x++){
        dictArray[x] = x;
    }
    dict -> initialize(dictArray);
    //cout << *dict << endl;

    Dictionary diction = Dictionary();
    diction.initialize(dictArray);
    // **************************

    //diction.rank_range(20, 5, 1);
    //diction.select_range(0, 100, 10, 1);

    return 0;
}

    /*
    Set mySet = Set(24);
    Set otherSet = Set(24);
    char * charArray1 = new char[3];
    for(int x = 0; x < 3; x++){
        charArray1[x] = 0;
    }
    char * charArray2 = new char[3];
    for(int x = 0; x < 3; x++){
        charArray2[x] = 0;
    }
    //char c = '0';
    //for(int x = 0; x < 255; x++){
        //cout << c << endl;
        //c ++;
    //}
    mySet.initialize(charArray1);
    otherSet.initialize(charArray2);
    //mySet.getData().set(4,1);
    //mySet.getData().set(12,1);
    mySet.setIntersection(otherSet);
    char * charArray = new char[5];
    for(int x=0; x<5; x++){
        charArray[x] = 'a';
    }
    BitArray * testing = new BitArray(40);
    testing->initialize(charArray);
    cout << "Testing Initialize" << endl;
    cout << *testing << endl;
    testing->clear();
    cout << "After Clearing" << endl;
    cout << *testing << endl;
    cout << "After Flips/Sets" << endl;
    testing->set(2);
    testing->flip(3);
    testing->set(5);
    testing->set(28);
    //if testing works it implies get works
    cout << *testing << endl;
    testing->clear();
    cout << endl << *testing << endl;
    testing->complement();
    cout <<"After Complement" << endl;
    cout << *testing << endl;
    return 0;
    */
