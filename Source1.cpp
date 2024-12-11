#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial; // Forward declaration

class Term {
    friend class Polynomial;
    friend ostream& operator<<(ostream& os, const Polynomial& poly); // Output operator
    friend istream& operator>>(istream& is, Polynomial& poly);       // Input operator

private:
    float coef; // Coefficient
    int exp;    // Exponent
};

class Polynomial {
public:
    Polynomial(int capacity = 10); // Constructor with default capacity
    ~Polynomial();                 // Destructor

    friend ostream& operator<<(ostream& os, const Polynomial& poly); // Output operator
    friend istream& operator>>(istream& is, Polynomial& poly);       // Input operator

private:
    Term* termArray; // Array of non-zero terms
    int capacity;    // Size of the term array
    int terms;       // Number of non-zero terms

    void Expand();   // Expand the capacity of the term array
};

#endif // POLYNOMIAL_H
