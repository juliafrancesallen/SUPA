/* ---------------------------------------------------------- *
 *                                                            *
 *                   Title: Assignment 1                      *
 *                   Author: Julia Marsh                      *
 *                   Date of creation: 5th Nov. 2021          *
 *                                                            *
 * ---------------------------------------------------------- */

// libraries 
#include <iostream>              // cout/cin 
#include <fstream>               // ifstream 
#include <string>                // string 
#include <cmath>                 // math libary       
using namespace std;             // remove prefix std:: 
#include "functionExample.h"     // header file 

// ------------------------------------------------------------
// main function 
int main(){

    // input file called fin 
    ifstream fin; 

    // boolean for opening the file 
    bool isOpen;
    isOpen = fileOpen("input2D_float.txt", fin);

    // ask user to provide number of lines 
    int numLines;
    cout << "\nPlease state the number of lines to read: ";
    cin >> numLines;

    // If statement - if the file is open...
    if (isOpen){

        // call printFile function - prints x, y and vector magnitude for given number of lines  
        printFile(fin, numLines);
        fileClose(fin);     // close the file 
        
        // call dataAnalysis function to perform least squares and chi squared 
        // this function reopens the file - see comment in function 
        dataAnalysis("input2D_float.txt", fin);
        fileClose(fin);     // close the file 

    }// end of if statement 
    else{

        // print 'Error!' if unable to open the file 
        cout << "Error!\n" << endl;

    }// end of else statement 

} // END of main function
// ------------------------------------------------------------

/* ------------------------------------------------------------ *
 * Boolean function to open the file. Returns 'true' if opened  *
 * and 'false' if unable to open                                *
 * ------------------------------------------------------------ */ 
// boolean function to open the file 
bool fileOpen(string s, ifstream& f){
    
    // open the file 
    f.open(s);
    
    // perform check - 'true' if file opened, 'false' if file did not open
    if(f.is_open())
        return true;
    else
        return false;
}// END

/* ------------------------------------------------------------ *
 * Function to close the file                                   *
 * ------------------------------------------------------------ */ 
void fileClose(ifstream& f){
    f.close();
}// END

/* ----------------------------------------------------------- *
 * Function to print the contents of the file (x and y) and    * 
 * calculate the vector magnitude for a given number of lines  *
 * ----------------------------------------------------------- */ 
// function to print the contents of the file 
void printFile(ifstream& f, int nLines){
    
    // initialise x and y 
    float x, y;    

    // if number of lines is 0 or >100 set default number of lines to be read to 20 
    if ( nLines == 0 || nLines > 100 ){
        cout << "\nYou entered either 0 or >100 number of lines so reading 20 lines by default..." << endl;
        nLines = 20;
    } // end of if 
    else{
        cout << "\nReading " << nLines << " lines..." << endl;
    }// end of else 

    // loop over the number of lines 
    for (int i=1; i<=nLines; i++){
        // read x and y values 
        f >> x >> y; 
        // Vector magnitude calculated using function
        double magnitude = (sqrt(x*x + y*y));
        // print x, y and magnitude 
        cout << "x component: " << x << ", y component: " << y << ", vector magnitude " << magnitude << endl;
    }// end of for loop
}// END 

/* ------------------------------------------------------------ *
 * Function to perform least squares fit and determine chi2     *
 * ------------------------------------------------------------ */ 
void dataAnalysis(string s, ifstream& f){

    /* Reopened the file as the previous functions called (e.g. printFile) 'edited' file. 
     * For example, after stating that I wanted to read 40 lines, when I called this function
     * and printed N after the while loop it would state that N was 60 (e.g. only 60 of the 
     * 100 lines left). If I read 100 lines in the printFile function, it would then print 
     * N = 0 in this function (i.e. all the lines have been 'used' in the previous function 
     * and there are none left). 
     */ 
    f.open(s);

    // print statement stating that the code is now performing the least squares method 
    cout << "\nPeforming Least Squares (on all lines)..." << endl;

    float x, y;                     // define floats x, y
    int N = 0;                      // Number of lines (N)
    float x_sum = 0;                // sum of x values 
    float x2_sum = 0;               // sum of x^2 values 
    float y_sum = 0;                // sum of y values 
    float xy_sum = 0;               // sum of x*y values 

    // loop over file  
    while ( !f.eof() ){
        f >> x >> y;
        if ( !f.eof() ){
            N++;                    // add 1 to N over each iteration 
            x_sum += x;             // sum x 
            x2_sum += (x*x);        // sum x^2
            y_sum += y;             // sum y 
            xy_sum += (x*y);        // sum x*y
        }// end of if 
    }// end of while loop 
    
    // determine p and q 
    float p = (N*xy_sum - x_sum*y_sum) / (N*x2_sum - x_sum*x_sum);
    float q = (x2_sum*y_sum - xy_sum*x_sum) / (N*x2_sum - x_sum*x_sum);

    // print equation of the line 
    cout << "Equation of the line : y = " << p << " * x + " << q << "\n" << endl;

    f.close();                      // close the file 
    f.open(s);                      // reopen the file - now have all 100 lines again 

    // print that code is now calculating chi2
    cout << "Calcualting Chi2..." << endl;
    float chi2 = 0;                 // float to sum chi2
    float error = 0.5;              // error on every point 

    // loop over file  
    while ( !f.eof() ){
        f >> x >> y;
        if ( !f.eof() ){
            float y_exp = p * x - q;                        // calculate y expected 
            float y_diff = y - y_exp;                       // calculate difference in y and y expected 
            chi2 += (y_diff*y_diff) / (error*error);        // calculate chi2 and sum 
            // cout << y << ", " << y_exp << ", " << y_diff << endl;
        }// end of if 
    }// end of while loop 

    // print chi2/N
    float chi2_N = chi2/N; 
    cout << "Chi2/N (number of points): " << chi2_N << "\n" << endl;

}// END 

