/* ---------------------------------------------------------- *
 *                                                            *
 *                  Title: Assignment 2                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 17th Nov 2021                *
 *                                                            *
 *                      Header File                           * 
 * ---------------------------------------------------------- */

// declare functions 
void instructons ();
std::vector<string> playerA_random ();
void first_ball (string, vector<string>);
void second_ball (string, vector<string>);
void third_ball (string, vector<string>);
void fourth_ball (string, vector<string>);

// function to print the instructions to terminal 
void instructions () {
    cout << "*******************************************************************" << endl;
    cout << "*                                                                 *" << endl;
    cout << "*                  Hello and welcome to Mastermind!               *" << endl;
    cout << "*                                                                 *" << endl;
    cout << "* In this version of the game, the computer is player A and will  *" << endl;
    cout << "* randomly select four out of six coloured balls. You are player  *" << endl;
    cout << "* B and it is your job to correctly guess the chosen combination. *" << endl;
    cout << "* The 6 colours are red, blue, green, yellow, purple and orange.  *" << endl;
    cout << "*                                                                 *" << endl;    
    cout << "*                      Let's play... Good luck!                   *" << endl;
    cout << "*                                                                 *" << endl;
    cout << "*******************************************************************" << endl;
}// END

// function to shuffle vector containing colours and select first four
std::vector<string> playerA_random () {

    // array containing the 6 colours 
    string colour_ball[] = {"red", "blue", "green", "yellow", "purple", "orange"};

    // create vectors containing the colours 
    vector<string> colours(6);
    for (int i=0; i<6; i++){
        colours[i] = colour_ball[i];
    }

    // obtain a time based random seed 
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // shuffle the array of colours randomly - third argument is a uniform random number generator 
    shuffle (colours.begin(), colours.end(), default_random_engine(seed));

    // select the first four colours for player A 
    vector<string> playerA(4);
    for (int i=0; i<4; i++){
        playerA[i] = colours[i];
    }

    return playerA;

}// END 


void first_ball (string guess, vector<string> colour){
    if ( guess == colour[0] ){
        cout << "Good guess... you get a BLACK ball\n" << endl;
    }
    else if ( guess == colour[1] || guess == colour[2] || guess == colour[3] ){
        cout << "Good guess... you get a WHITE ball\n" << endl;
    }
    else{
        cout << "Better luck next time...\n" << endl;
    }
}// END

void second_ball (string guess, vector<string> colour){
    if ( guess == colour[1] ){
        cout << "Good guess... you get a BLACK ball\n" << endl;
    }
    else if ( guess == colour[0] || guess == colour[2] || guess == colour[3] ){
        cout << "Good guess... you get a WHITE ball\n" << endl;
    }
    else{
        cout << "Better luck next time...\n" << endl;
    }
}// END

void third_ball (string guess, vector<string> colour){
    if ( guess == colour[2] ){
        cout << "Good guess... you get a BLACK ball\n" << endl;
    }
    else if ( guess == colour[0] || guess == colour[1] || guess == colour[3] ){
        cout << "Good guess... you get a WHITE ball\n" << endl;
    }
    else{
        cout << "Better luck next time...\n" << endl;
    }
}// END

void fourth_ball (string guess, vector<string> colour){
    if ( guess == colour[3] ){
        cout << "Good guess... you get a BLACK ball\n" << endl;
    }
    else if ( guess == colour[0] || guess == colour[1] || guess == colour[2] ){
        cout << "Good guess... you get a WHITE ball\n" << endl;
    }
    else{
        cout << "Better luck next time..." << endl;
    }
}// END 

