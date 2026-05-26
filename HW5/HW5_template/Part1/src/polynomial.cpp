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

// finished node compared (==)
bool PolynomialTerm::operator==(const Node& other)
{
    auto other_p = dynamic_cast<const PolynomialTerm*>(&other);
    if (!other_p) return false; 
    // TODO: finish this function
    return (_coefficient == other_p->_coefficient &&
            _exponent == other_p->_exponent);
}


/*
** TODO: Finish this file.
*/
// node compared (!=)
bool PolynomialTerm::operator!=(const Node& other)
{
    return !(*this == other);
}

// insert
void Polynomial::insert(int coefficient, int exponent)
{
    if (coefficient == 0) return;

    Node* prev = nullptr;
    Node* curr = _head;

    // sort the location
    while (curr)
    {
        auto term = dynamic_cast<PolynomialTerm*>(curr);

        if (term->exponent() == exponent)
        {
            (*term) += coefficient;

            if (term->coefficient() == 0)
            {
                Node* toDelete = curr;
                curr = curr->next();
                remove(toDelete);
            }
            return;
        }

        // find insert node(>cur)
        if (term->exponent() < exponent)
            break;

        prev = curr;
        curr = curr->next();
    }

    // new node
    Node* newNode = new PolynomialTerm(coefficient, exponent);

    // insert
    if (!prev)
    {
        newNode->setNext(_head);
        _head = newNode;
    }
    else
    {
        newNode->setNext(curr);
        prev->setNext(newNode);
    }
}

// polynomial +
Polynomial Polynomial::operator+(const Polynomial& other) const
{
    Polynomial result;

    Node* curr = _head;
    while (curr) {
        auto t = dynamic_cast<PolynomialTerm*>(curr);
        result.insert(t->coefficient(), t->exponent());
        curr = curr->next();
    }

    curr = other._head;
    while (curr) {
        auto t = dynamic_cast<PolynomialTerm*>(curr);
        result.insert(t->coefficient(), t->exponent());
        curr = curr->next();
    }

    return result;
}

// polynomial *
Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polynomial result;

    Node* a = _head;
    while (a) {
        auto ta = dynamic_cast<PolynomialTerm*>(a);

        Node* b = other._head;
        while (b) {
            auto tb = dynamic_cast<PolynomialTerm*>(b);

            int coef = ta->coefficient() * tb->coefficient();
            int exp  = ta->exponent() + tb->exponent();

            result.insert(coef, exp);

            b = b->next();
        }

        a = a->next();
    }

    return result;
}

// polynomial +=
Polynomial& Polynomial::operator+=(const Polynomial& other)
{
    *this = *this + other;
    return *this;
}

// polynomial *=
Polynomial& Polynomial::operator*=(const Polynomial& other)
{
    *this = *this * other;
    return *this;
}

// polynomial =
Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this == &other) return *this;

    while (_head) {
        remove(_head);
    }

    Node* curr = other._head;
    while (curr) {
        auto t = dynamic_cast<PolynomialTerm*>(curr);
        insert(t->coefficient(), t->exponent());
        curr = curr->next();
    }

    return *this;
}

// polynomial compared (==)
bool Polynomial::operator==(const Polynomial& other)
{
    Node* a = _head;
    Node* b = other._head;

    while (a && b) {
        if (!(*a == *b)) return false;
        a = a->next();
        b = b->next();
    }

    return (a == nullptr && b == nullptr);
}

// polynomial compared (!=)
bool Polynomial::operator!=(const Polynomial& other)
{
    return !(*this == other);
}