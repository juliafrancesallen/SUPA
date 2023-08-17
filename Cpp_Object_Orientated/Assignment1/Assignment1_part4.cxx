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
#include <cstdlib>
using namespace std;
// header file
#include "COO_Assignment1_JuliaMarsh.h"

// definition of function 
double vectorMagnitude_2D(double i, double j){
    // returns 2D vector magnitude 
    return (sqrt(i*i + j*j));
}

// main function 
int main(){

    // create an ifstream object 
    ifstream inputFile;

    // open the existing file 
    inputFile.open("input2D_float.txt");
    
    // check the operation worked
    if (inputFile.fail()) {
        cout << "Unable to open file!" << endl;
        // from cstdlib 
        exit(1); 
    } // end 

    // extract data from text file - only want first 5 lines 
    double x, y;

    // ask user to provide number of lines 
    int numLines;
    cout << "Please state the number of lines to read: ";
    cin >> numLines;

    // if numLines = 0 or > 100 want to just read 20 lines 
    if (numLines==0 || numLines > 100){
        numLines = 20;
        cout << "You entered either 0 or >100 (larger than lines in the file) so 20 lines will be read from file...\n" << endl;
        // loop over number of lines == 20 
        for (int i=1; i<=numLines; i++){
            // read x and y values 
            inputFile >> x >> y; 
            // Vector magnitude calculated using function
            double magnitude = vectorMagnitude_2D(x,y);
            // print x, y and magnitude 
            cout << "x component: " << x << ", y component: " << y << ", vector magnitude " << magnitude << endl;
        }// end of loop 

    }// end of if statement 
    else{

        // loop over number of lines 
        for (int i=1; i<=numLines; i++){
            // read x and y values 
            inputFile >> x >> y; 
            // Vector magnitude calculated using function
            double magnitude = vectorMagnitude_2D(x,y);
            // print x, y and magnitude 
            cout << "x component: " << x << ", y component: " << y << ", vector magnitude " << magnitude << endl;
        }// end of loop 

        // print number of lines read 
        cout << numLines << " lines read from file" << endl;

    }// end of else statement 

    // close file once finished 
    inputFile.close();

    return 0;

}// end of main 