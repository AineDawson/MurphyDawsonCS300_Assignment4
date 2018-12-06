#ifndef UPCFUNCTIONS_H_
#define UPCFUNCTIONS_H_
#include <iostream>
#include "BinarySearchTree.h"
#include "UPC.h"
using namespace std;
//Dawson Murphy
//This program holds the methods to be used in BarcodeBSTScanner.cpp. Holds methods for reading data from a file
//into a Binary Search Tree, and for finding items based on their UPC code and printing their information.

template <class T>
class UPCBSTFunctions: public BinarySearchTree<T>{
    public:
        //Search function the user uses, only taking in the key of the item they wish to search for
        T search(string key){
            return search(this->root,key);
        }
        void readData(UPCBSTFunctions<UPC>&, int); //Creates BST from data in a file
    private:
        //The private search function which uses the Binary Trees Root
        T search(node<T>*, string);
};
//Searches for an item in a nodes subtree, recursively calling 
//itself until it reaches the child of a leaf of the tree,
//or the item is found. Returns the item.
template <class T>
T UPCBSTFunctions<T>::search(node<T>* p, string key){
	if(p == NULL) //item was not found
		throw 343;
	else if(key<p->data) //item is smaller than current node
		return search(p->left, key);
	else if(key>p->data) //item is larger than current node
		return search(p->right, key);
	return p->data; //The current node holds the item
}

//Reads data from the file upc_corpus.txt, and takes its first 120000 entries into
//a binary search tree. 
//Entire file was not written into tree due to hardware constraints.
template <class T>
void UPCBSTFunctions<T>::readData(UPCBSTFunctions<UPC>& dB, int numb){
    string id, data;
    ifstream upcfile;
    upcfile.open("upc_corpus.txt"); //opens the file
    getline(upcfile, id); //Gets past first line, which holds header info
    for(int i=0; i<=numb;i++){ //Gets first 120000 entries
        getline(upcfile,id, ',');
        getline(upcfile, data);
        UPC temp(id,data); //Takes data from the line to create temporary UPC object
        dB.insert(temp); //Inserts item into tree
    }
}

#endif