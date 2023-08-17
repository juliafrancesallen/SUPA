/* ---------------------------------------------------------- *
 *                  Title: Assignment 4                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 20th Dec 2021                *
 *                                                            *
 *               Planet Class Header File                     * 
 *                                                            *
 * Note: private members are now `protected' to enable the    *
 * derived class (SolarPlanet) access to these members.       * 
 * ---------------------------------------------------------- */
#ifndef PLANET_H
#define PLANET_H

// class - convention: class name starts with a capital letter 
class Planet {

public:
    // constructor
    Planet(std::string name, double mass, double x, double y);
    // member functions - convention: start with lower case 
    double getX();                  // accessor (getter) functions            
    double getY();          
    double getMass();
    std::string getName();             
    void setX(double x);            // setter funcitons 
    void setY(double y);               
    void setMass(double mass); 
    void setName(std::string name);     
    static int totalPlanets();      // static member function         

protected: 
    // private members - conventtion - start with m_variable 
    std::string m_name;             // name of planet 
    double m_mass;                  // mass of planet 
    double m_x;                     // unit [km]
    double m_y;                     // unit [km]
    static int m_counter;           // static data member            
};

#endif