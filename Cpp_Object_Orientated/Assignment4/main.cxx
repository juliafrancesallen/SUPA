/* ---------------------------------------------------------- *
 *                  Title: Assignment 4                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 20th Dec 2021                *
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
#include <string>      
#include <vector>      
#include "Planet.h"
#include "SolarPlanet.h"

using namespace std;

int main(void){

    /* ---------------------------------------------------------- *
     *                         PARTS 1-3                          *
     * ---------------------------------------------------------- */ 

    // create an ifstream object and open file 
    ifstream myInput;
    myInput.open("Planets_data.txt");
    
    // define variables name, mass and x,y coordinates 
    std::string name;
    double mass, x, y;   
    
    // create vector store all the planets 
    vector<SolarPlanet> planetsVector;

    // print to terminal 
    cout << "\nReading lines from file...\n" << endl;

    // loop over all lines in the file 
    while ( !myInput.eof() ){
        myInput >> name >> mass >> x >> y;
        if ( !myInput.eof() ){
            //instantiate a new object 
            SolarPlanet newPlanet(name, mass, x, y);
            // add new object (planet) as an element to the vector whilst reading the file 
            planetsVector.push_back(newPlanet);
        }
    }
    
    // print to terminal 
    cout << "Printing information stored for each planet...\n" << endl;

    // loop over vector containing all planet objects and print the information stored on each planet 
    for(std::vector<int>::size_type i = 0; i != planetsVector.size(); i++){
        cout << planetsVector[i].getName() << " has a mass of " << planetsVector[i].getMass() << " and (x,y) coordinates (" << planetsVector[i].getX() << ", " << planetsVector[i].getY() << ")" << endl;
        // call setter functions to set my constant values for later use 
        planetsVector[i].setRadiusFromSun(planetsVector[i].getX());     // notice that initial position of planets (x, 0) --> x_intital = radiusFromSun
        planetsVector[i].setSunMass();
        planetsVector[i].setG();
    }

    // close input file 
    myInput.close();

    cout << "\n------------------------------------------------------------------------- " << endl;
    /* ---------------------------------------------------------- *
     *               PARTS 4 & 5: Iterations using Evolve         *
     * ---------------------------------------------------------- */ 
    
    // define variables for time interval and total time 
    double dt, total_time;

    // ask for the interval dt and time total_t as terminal inputs 
    cout << "\nPlease input a value for the time interval dt: "; 
    cin >> dt;
    cout << "Please input a value for the total time: ";
    cin >> total_time; 

    // The timestep is the time interval given as input - time_step used to increase dt 
    double time_step = dt;
    int iterations = 0;        // setup variable used to count iterations 

    // print to terminal 
    cout << "\nPerforming iterations..." << endl; 

    // for loop over vector containing all planet objects - iterate over each object 
    for (std::vector<int>::size_type i = 0; i != planetsVector.size(); i++) {

        // write to file 
        ofstream myOutput;
        // format the output file name 
        std::string str = planetsVector[i].getName();
        str.append(".csv"); 
        // open the file 
        myOutput.open(str); 
        // print column names to csv file 
        myOutput << "dt, x, y" << endl;

        // while loop - keep iterating while the increasing dt is less than total time 
        while (dt <= total_time) {
            iterations++;
            // call evolve function 
            planetsVector[i].Evolve(dt);
            // write to output file 
            myOutput << dt << ", " << planetsVector[i].getX() << ", " << planetsVector[i].getY() << ", " << endl;
            // increase dt with the time_step for next iteration 
            dt += time_step;
        }

        // print to terminal when iterations are finished 
        cout << iterations << " iterations completed for " << planetsVector[i].getName() << endl;

        // close file
        myOutput.close();

        // reset dt and # iterations for next planet 
        iterations = 0;
        dt = time_step;
    }

    cout << "\n------------------------------------------------------------------------- " << endl;
    /* --------------------------------------------------- *
     *               PART 6: Find orbit times              *
     * --------------------------------------------------- */ 

    // print to terminal 
    cout << "\nNow determining the total orbit times...\n" << endl;

    // loop over vector containing planet objects 
    for(std::vector<int>::size_type i = 0; i != planetsVector.size(); i++){
        // call the getTime function and print orbit time for each planet 
        cout << planetsVector[i].getName() << " has an orbit time of " << planetsVector[i].getTime() << " seconds" << endl;
    }

    // print to terminal that the simulation has finished 
    cout << "\nSimulation finished.\n" << endl;
    return 0;
}





