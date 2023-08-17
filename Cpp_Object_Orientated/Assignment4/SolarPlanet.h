/* ---------------------------------------------------------- *
 *                  Title: Assignment 4                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 20th Dec 2021                *
 *                                                            *
 *              Solar Planet Class Header File                * 
 * ---------------------------------------------------------- */
#include "Planet.h"
class SolarPlanet : public Planet {

public:
    // constructor
    SolarPlanet(std::string word, double b, double c, double d);                   
    // member functions
    float getTime();                 // accessor (getter) functions            
    double getG();          
    double getSunMass();
    double getRadiusFromSun();     
    double getAngularSpeed();       
    void setG();                      // setter functions 
    void setSunMass();               
    void setRadiusFromSun(double radiusFromSun);        
    // function to update coordinates
    void Evolve(double dt);

private:    
    double m_time;
    double m_G;
    double m_sunMass;   
    double m_radiusFromSun;
};