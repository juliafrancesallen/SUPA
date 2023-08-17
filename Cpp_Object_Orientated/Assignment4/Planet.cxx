/* ---------------------------------------------------------- *
 *                  Title: Assignment 4                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 20th Dec 2021                *
 *                                                            *
 *                  Planet Class Source File                  * 
 * ---------------------------------------------------------- */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <fstream>                      
#include "Planet.h"
using namespace std;  

// intialise static data memeber
int Planet::m_counter = 0;

// constructor 
Planet::Planet(std::string name, double mass, double x, double y){
    m_x = x;
    m_y = y;
    m_mass = mass;
    m_name = name;
    m_counter++;
}

/* ------------------------- * 
 *      Getter Functions     *
 * ------------------------- */
double Planet::getX() {
    return m_x;
}

double Planet::getY() {
    return m_y;
}

double Planet::getMass() {
    return m_mass;
}
std::string Planet::getName() {
    return m_name;
}

/* ------------------------- * 
 *      Setter Functions     *
 * ------------------------- */
void Planet::setX( double x ) {
    m_x = x;
} 

void Planet::setY( double y ) {
    m_y = y;
}

void Planet::setMass( double mass ) {
    m_mass = mass;
}

void Planet::setName( string name ) {
    m_name = name;
} 

// Static member function 
int Planet::totalPlanets() {
    return m_counter;
}