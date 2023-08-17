/* ---------------------------------------------------------- *
 *                                                            *
 *                  Title: Assignment 3                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 17th Nov 2021                *
 *                                                            *
 *                  Cauchy Source File                        * 
 * ---------------------------------------------------------- */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <fstream>                      
#include "cauchy.h"
using namespace std;   

// constructor that only requires xmin and xmax as arguments 
CauchyIntegral::CauchyIntegral(float xmin, float xmax){
    m_xmin = xmin;
    m_xmax = xmax;
}

// constructor that takes xmin, xmax and a string 
CauchyIntegral::CauchyIntegral(float xmin, float xmax, std::string filename){
    m_xmin = xmin;
    m_xmax = xmax;
    m_filename = filename;
}

// function to calculate the integral 
double CauchyIntegral::getIntegral(){

    // determine the range 
    float Range = m_xmax - m_xmin;

    // initialise random seed using the current time
    float random;
    srand (time(NULL));

    // number of iterations 
    int N = 10000;
    // define float to sum over 
    float sum;

    // loop over 10000 iterations
    for (int i=0; i<N; i++){
        // generate random number between 0 and 1 
        random = ((float) rand() / (float) (RAND_MAX));
        // scale random number to between -5 and 5
        float randomScaled = m_xmax - (Range*random);
        sum += cauchyFunction(randomScaled);
    }
    return Range * (sum/N);
}

void CauchyIntegral::getMetropolis() {

    ofstream myOutput;
    // open a new file 
    myOutput.open(m_filename);
    // check the operation worked 
    if ( myOutput.fail() ){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    myOutput << "File containing x_(t+1) values" << endl;
    
    // set the range 
    float Range = m_xmax - m_xmin;
    // define two random numbers 
    float random1, random2;
    // set the random seed 
    srand (time(NULL));
    // random number between 0 and 1 
    random1 = ((float) rand() / (float) (RAND_MAX));
    // scale random number to between -5 and 5 
    float xRandom = m_xmax - (Range*random1);
    // number of iterations
    int N = 100;

    // loop over N
    for (int i=0; i<N; i++){

        // generate random number between 0 and 1 
        random2 = ((float) rand() / (float) (RAND_MAX));

        // scale random number to between -5 and 5
        float yRandom = m_xmax - (Range*random2);

        // generate random number between 0 and 1 
        float u = ((float) rand() / (float) (RAND_MAX));

        // determine ratio A
        float A = cauchyFunction(yRandom)/cauchyFunction(xRandom);

        if (A > u){
            // update x_(t+1) with accepted y value 
            xRandom = yRandom;
            myOutput << "x_(t+1) = " << xRandom << " (y accepted)" << endl;
        } else {
            // x_(t+1) stays the same as x_t
            myOutput << "x_(t+1) = " << xRandom << " (y not accepted)" << endl;
        }
    }
}

// Cauchy integral function 
double CauchyIntegral::cauchyFunction(float x) {
    return (1 / (M_PI * (1 + pow(x,2))));
}