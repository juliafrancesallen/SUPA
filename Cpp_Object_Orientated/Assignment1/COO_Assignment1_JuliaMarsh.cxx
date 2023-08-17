/* 
 * Title: Assignment 1 
 * Author: Julia Marsh 
 * Date of creation: 5th November 2021 
 * -------------------------------------
 * Reminder for me:
 * How to compile C++ code in bash:
 * $ g++ ProgramName.cpp -o name 
 * $ ./name 
 * Note: -o name creates an executable file 
 */  

// include <> - standard header files 
#include <iostream> 
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
// header file
#include "COO_Assignment1_JuliaMarsh.h"

// definition of function 
double vectorMagnitude_2D(double i, double j){
    // returns 2D vector magnitude 
    return (sqrt(i*i + j*j));
}

// prototype 
bool fileOpen(string, ifstream&);
void printFile(fstream&);
void fileClose(ifstream&);

// main function 
int main(){

    // create an ifstream object 
    ifstream fin;

    // boolean for opening the file 
    bool isOpen;
    isOpen = fileOpen("input2D_float.txt", fin);

    // loop over open file 
    if (isOpen){

        // call printFile function 
        printFile(fin);

        // call closefile function 
        fileClose(fin);
    }
    else{
        cout << "Error!\n" << endl;
    }

    // ask user to provide number of lines 
    //int numLines;
    //cout << "Please state the number of lines to read: ";
    //cin >> numLines;

    return 0;

}// end of main 

// function to open the file - returns boolean 
bool fileOpen(string s, ifstream& f){
    f.open(s);
    if(f.is_open())
        return true;
    else
        return false;
}

// arguments are the text file (f) and the number of lines (N)
void printFile(fstream& f){
    float x, y;    
    while(f >> x >> y)
        cout << x << ", " << y << endl;
}

// function to close the file
void fileClose(ifstream& f){
    f.close();
}