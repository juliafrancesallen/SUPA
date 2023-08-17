/* ---------------------------------------------------------- *
 *                                                            *
 *                  Title: Assignment 3                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 30th Nov 2021                *
 *                                                            *
 *                      Main file                             * 
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

int main(void){

    // generate object from class CauchyIntegral - constructor for xmin, xmax arguments 
    CauchyIntegral c(-5.0, 5.0);

    // perform cauchy integral 
    double cIntegral = c.getIntegral();

    // print integral result 
    cout << "Integral = " << cIntegral << endl;

    // generate new object from class - constructor for xmin, xmax and string 
    CauchyIntegral c2(-5.0, 5.0, "outputFile.txt");

    // perform Metropolis Algorithm 
    c2.getMetropolis();

    return 0;
}