#include "polynomial.h"
#include <iostream>
#include <sstream>

std::string PolynomialTerm::toString()
{
    std::stringstream ss; 
    if (_exponent == 0) 
        ss << _coefficient;
    else {
        if (_coefficient != 1) ss << _coefficient;
        ss << "x";
        if (_exponent != 1) ss << "^" << _exponent;       
    }
    return ss.str();
} 


std::string Polynomial::toString()
{
    std::stringstream ss; 
    Node* iter = _head;
    ss << iter->toString();
    iter = iter->next();
    while (iter) {
        ss << " + " << iter->toString();
        iter = iter->next();
    }
    return ss.str();
}


PolynomialTerm::~PolynomialTerm() {}


bool PolynomialTerm::operator==(const Node& other)
{
    auto other_p = dynamic_cast<const PolynomialTerm*>(&other);
    if (!other_p) return false; 
    // TODO: finish this function



}


/*
** TODO: Finish this file.
*/