#include <iostream>
#include <fstream>
#include <ctime>
#include "UPCBSTFunctions.h"
using namespace std;
//Dawson Murphy
//This program reads in information for items (UPC code and descriptions) and stores it into a binary search tree. It 
//then allows the user to input UPC codes, and returns the corresponding item description if there is one. The program
//also returns the time it took to complete the queuery.

int main(){
    UPCBSTFunctions<UPC> UPCTree;
    UPCTree.readData(UPCTree); //Reads data from the file into the tree
    cout<<"Welcome to Barcode BST Scanner. Enter UPC barcode to retrieve data for an item."<<endl;
    cout<<"Enter Q to leave the program."<<endl;
    string entry;
    cout<<"Please enter a UPC code: "<<endl;
    cin>>entry; //Takes first user entered code
    while(entry!="Q"){ //Continues until user enters Q
        cout<<"UPC Code: "<<entry<<endl;
        try{ //Attempts to find the item
            clock_t begin=clock(); //Gets start time
            UPC result=UPCTree.search(entry); //Searches for and returns the item
            clock_t end=clock(); //Gets end time
            double timeTaken=double(end-begin);
            cout<<result<<endl; //Prints the item description
            cout<<"Time in microseconds: "<<timeTaken<<endl; //Prints the time it took to find the item
        }catch(int e){ //If the item was not found
            cout<<"Could not find an item matching that UPC Code."<<endl;
        }
        //Asks for and accepts the next user entered code
        cout<<"Please enter a UPC code: "<<endl; 
        cin>>entry;
    }
    //When the user exits the program
    cout<<"Good Bye"<<endl;
}