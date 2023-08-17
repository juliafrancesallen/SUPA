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
#include "HelloWorld.h"
#include <cmath>

// definition of function 
double vectorMagnitude_2D(double i, double j){

    return (sqrt(i*i + j*j));
}

// main function 
int main(){

    // print hello world 
    std::cout << "Hello World!" << std::endl; 

    // define two variables (x and y) - x and y components of a 2D vector 
    double x, y;
    x = 2.3;
    y = 4.5; 

    // Vector magnitude calculated using function
    double magnitude = vectorMagnitude_2D(x,y);

    // print value to terminal 
    std::cout << "Calculated vector magnitude: " << magnitude << std::endl;

    return 0;
    
}