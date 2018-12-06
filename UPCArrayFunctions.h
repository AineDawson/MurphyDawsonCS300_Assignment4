#ifndef UPCARRAYFUNCTIONS_H_
#define UPCARRAYFUNCTIONS_H_
#include <iostream>
#include "UPC.h"
using namespace std;
//Dawson Murphy
//This program holds methods to be used in BarcodeArrayScanner.cpp. Holds methods for reading data from a file into an array,
//and searching the array for a UPC object based on its code.


class UPCArrayFunctions{
    public:
        int readData(UPC[], int numb);
        UPC search(UPC[], string, int x);
};
//Reads data from the file upc_corpus.txt into an array, and returns the number of items in the array.
//The number of items in array will be used for search function.
int UPCArrayFunctions::readData(UPC dB[], int numb){
    string id, data;
    int size; //For the size of the array
    ifstream upcfile;
    upcfile.open("upc_corpus.txt"); //Opens the file
    getline(upcfile, id); //Gets past the line holding header information
    for(int i=0; i<=numb;i++){ //Reads in first 120,000 items in file
        getline(upcfile,id, ',');
        getline(upcfile, data);
        UPC temp(id,data); //Creates temporary UPC object
        dB[size]=temp; //Adds object into array 
        size++;
    }
    return size;
}

//This function searches through an array of UPC objects for an item matching a given
//UPC code. Takes size as number of items in array.
UPC UPCArrayFunctions::search(UPC dB[], string entry, int size){
    for(int i=0; i<size-1;i++){ //Searches through array for item
        if(dB[i]==entry){
            return dB[i]; //If item is found, returns it.
        }
    }
    throw 343; //If not found, throws an int.
}

#endif