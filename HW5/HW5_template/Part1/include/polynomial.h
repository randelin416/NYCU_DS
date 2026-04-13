#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <string>
#include "list.h"


class Polynomial : public List
{
public:
    Polynomial() {}

    void insert(int cofficient, int exponent);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    Polynomial& operator=(const Polynomial& other);
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);
    bool operator==(const Polynomial& other);
    bool operator!=(const Polynomial& other);

    std::string toString();
};


class PolynomialTerm : public Node 
{
private:
    int _exponent;
    int _coefficient;

public:
    PolynomialTerm(int coefficient, int exponent) : Node(), _coefficient(coefficient), _exponent(exponent) {}
    virtual ~PolynomialTerm() override;

    inline int coefficient() { return _coefficient; }
    inline int exponent() { return _exponent; }
    inline void operator=(int coefficient) { _coefficient = coefficient; }
    inline void operator+=(int coefficient) { _coefficient += coefficient; }
    bool operator==(const Node& other) override;
    bool operator!=(const Node& other) override;
    std::string toString() override;
};  


#endif