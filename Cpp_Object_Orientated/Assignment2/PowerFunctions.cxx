/* ---------------------------------------------------------- *
 *                                                            *
 *                  Title: Assignment 2                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 17th Nov 2021                *
 *                                                            *
 * ---------------------------------------------------------- */

// libraries 
#include <iostream>                      // cout/cin 
#include <fstream>                       // ifstream 
#include <string>                        // string 
#include <cmath>                         // math libary       
using namespace std;                     // remove prefix std:: 
#include "Assignment2_JuliaMarsh.h"      // header file 

// ------------------------------------------------------------
// main function 
int main(){

    // ask user to provide the base and exponent as input 
    int base, exponent;
    cout << "\nThis program is going to determine the power of a number...\n" << endl;
    cout << "Please input an integer value for the base: ";
    cin >> base;
    cout << "Please input an integer value for the exponent: ";
    cin >> exponent;
    
    float calc_power = power (base, exponent);
    cout << "\n" << base << " to the power of " << exponent << " is " << calc_power << "\n" << endl; 

} // END of main function
// ------------------------------------------------------------

// function to calculate the power of a number 
float power (int a, int b){

    if (b==0){ 
        return 1;
    }
    else{
        return ( a * power(a, b-1) );
    }
}// END

// function to calculate the power of a number 
double power (double a, double b){

    if (b==0){ 
        return 1;
    }
    else{
        return pow (a, 1/b);
    }
}// END