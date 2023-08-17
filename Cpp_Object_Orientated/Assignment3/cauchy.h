/* ---------------------------------------------------------- *
 *                                                            *
 *                  Title: Assignment 3                       *
 *                  Author: Julia Marsh                       *
 *             Date of creation: 17th Nov 2021                *
 *                                                            *
 *                  Cauchy Header File                        * 
 * ---------------------------------------------------------- */

#ifndef CAUCHY_H
#define CAUCHY_H

// Class 
class CauchyIntegral {

public:
    // constructors 
    CauchyIntegral(float xmin, float xmax);
    CauchyIntegral(float xmin, float xmax, std::string filename);
    // member functions 
    double getIntegral();
    void getMetropolis();

private:
    // private members
    float m_xmin;
    float m_xmax;
    std::string m_filename;
    // private memeber function 
    double cauchyFunction(float x);
};

#endif