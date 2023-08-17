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
#include <cstdlib>                       // exit 
#include <string>                        // string 
#include <cmath>                         // math libary       
#include <stdio.h>                       // NULL
#include <stdlib.h>                      // srand, rand 
#include <time.h>                        // time 
#include <algorithm>                     // shuffle 
#include <random>                        // default_random_engine 
#include <vector>                        // vector 
#include <chrono>                        // system_clock
using namespace std;                     // remove prefix std:: 
#include "Assignment2_JuliaMarsh.h"      // header file 

// ------------------------------------------------------------
// main function 
int main(){

    // call function to print instructions to terminal 
    instructions(); 

    //  ---------------- PLAYER A ---------------------

    // define vector containing player A's selection 
    std::vector<string> playerA;
    // call function to randomly pick four balls 
    playerA = playerA_random();

    //  ---------------- PLAYER B ---------------------

    ofstream myOutput;
    // open a new file 
    myOutput.open("playerB_output.txt");
    // check the operation worked 
    if ( myOutput.fail() ){
        cout << "Unable to open file!" << endl;
        exit(1);
    }

    myOutput << "Text file containing all combinations player B used to guess the four balls...\n" << endl;

    // define string to take input from terminal 
    string guess1, guess2, guess3, guess4; 

    cout << "\nROUND 1 ..." << endl; 
    int round = 1;

    while (true) {

        // GUESS BALL 1 
        cout << "\nPlease enter a guess for the first ball: ";
        cin >> guess1; 
        first_ball(guess1, playerA); 


        // GUESS BALL 2 
        cout << "... and the second ball: ";
        cin >> guess2; 
        second_ball(guess2, playerA); 


        // GUESS BALL 3 
        cout << "... and the third ball: ";
        cin >> guess3; 
        third_ball(guess3, playerA); 


        // GUESS BALL 4 
        cout << "... and the fourth ball: ";
        cin >> guess4; 
        fourth_ball(guess4, playerA); 

        myOutput << "Round " << round << ": " << guess1 << " " << guess2 << " " << guess3 << " " << guess4 << endl;

        // start the game again
        if (guess1 != playerA[0] || guess2 != playerA[1] || guess3 != playerA[2] || guess4 != playerA[3] ){
            ++round;
            cout << "\n*******************************************************************" << endl;
            cout << "ROUND " << round << " ... Guess again!" << endl;
        }

        // END THE GAME 
        if (guess1 == playerA[0] && guess2 == playerA[1] && guess3 == playerA[2] && guess4 == playerA[3] ){
            cout << "*******************************************************************" << endl;
            cout << "*                                                                 *" << endl;
            cout << "*                           GAME OVER!                            *" << endl;
            cout << "*                                                                 *" << endl;
            cout << "*******************************************************************" << endl;
            cout << "\nCongratulations! You correctly guessed the combination " << guess1 << ", " << guess2;
            cout << ", " << guess3 << ", " << guess4 << " in " << round << " rounds.\n" << endl;
            myOutput << "\nGame over!" << "\n\nPlayer B took " << round << " rounds to guess the correct combinations." << endl; 
            break;
        }

    }// END of while loop 

    return 0;

} // END of main function
// ------------------------------------------------------------

