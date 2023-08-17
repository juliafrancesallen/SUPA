/* ---------------------------------------------------------- *
 *                  Title: Assignment 4                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 20th Dec 2021                *
 *                                                            *
 *               Solar Planet Class Source File               * 
 * ---------------------------------------------------------- */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <fstream>                      
#include "SolarPlanet.h"
using namespace std;  

// constructor 
SolarPlanet::SolarPlanet(std::string word, double b, double c, double d) : Planet(word, b, c, d){}

/* ------------------------- * 
 *      Getter Functions     *
 * ------------------------- */
float SolarPlanet::getTime() {
    return (2*M_PI) / this->getAngularSpeed();
}   

double SolarPlanet::getG() {
    return m_G;
}          

double SolarPlanet::getSunMass() {
    return m_sunMass;
}

double SolarPlanet::getRadiusFromSun() {
    return m_radiusFromSun;
} 

double SolarPlanet::getAngularSpeed() {
    return sqrt((m_G * m_sunMass) / pow(m_radiusFromSun,3)) ;
}  

void SolarPlanet::Evolve(double dt) {
    double delta_angle =  this->getAngularSpeed() * dt;
    m_x = m_radiusFromSun * sin(delta_angle);
    m_y = m_radiusFromSun * cos(delta_angle);
}

/* ------------------------- * 
 *      Setter Functions     *
 * ------------------------- */
void SolarPlanet::setG() {
    m_G = 6.673e-20;
}

void SolarPlanet::setSunMass() {
    m_sunMass = 1.9890e30;
}    

void SolarPlanet::setRadiusFromSun(double radiusFromSun) {
    m_radiusFromSun = radiusFromSun;
}

