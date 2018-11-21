#include <iostream>
#include <fstream>
#include <ctime>
#include "UPCArrayFunctions.h"
using namespace std;
//Dawson Murphy
//This program reads in information for items (UPC code and descriptions) and stores it into an array. It 
//then allows the user to input UPC codes, and returns the corresponding item description if there is one. The program
//also returns the time it took to complete the queuery.

int main(){
    UPCArrayFunctions upcaf; 
    UPC dB[130000]; //Creates array to hold UPC objects
    int size=upcaf.readData(dB); //Reads the data in from the file, and returns number of items entered
    cout<<"Welcome to Barcode Array Scanner. Enter UPC barcode to retrieve data for an item."<<endl;
    cout<<"Enter Q to leave the program."<<endl;
    string entry;
    cout<<"Please enter a UPC code: "<<endl;
    cin>>entry; //Takes users first input code
    while(entry!="Q"){ //Until the user enters Q
        cout<<"UPC Code: "<<entry<<endl;
        try{ //Attempts to find the item matching the input code
            clock_t begin=clock(); //Gets start time
            UPC result=upcaf.search(dB, entry, size); //Searches for and returns the object
            clock_t end=clock(); //Gets the end time
            double timeTaken=double(end-begin);//Gets the time taken to find the object
            cout<<result<<endl; //Prints the objects information
            cout<<"Time in microseconds: "<<timeTaken<<endl; //Prints the time taken
        }catch(int e){ //If an object matching the input code was not found in the array
            cout<<"Could not find an item matching that UPC Code."<<endl;
        }
        //Asks for and accepts the users next input code
        cout<<"Please enter a UPC code: "<<endl;
        cin>>entry;
    }
    //User exits the program
    cout<<"Good Bye"<<endl;
}