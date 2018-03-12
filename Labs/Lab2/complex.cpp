//
// Created by william on 1/28/18.
//

#include "complex.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;
using namespace william_lab_2;

complex::complex(double r, double c)
{
    real = r;
    compnum = c;

}

double complex::get_real() const
{
    return real;
}

double complex::get_complex() const
{
    return compnum;
}

void complex::display()
{
    cout << real << " + " << compnum << "i" << endl;
}


complex william_lab_2::operator+(const complex &r1, const complex &r2)
{
    double r = r1.get_real() + r2.get_real();
    double c = r1.get_complex() + r2.get_complex();
    return complex(r, c);

}

complex william_lab_2::operator-(const complex &r1, const complex &r2)
{
    double r = r1.get_real() - (r2.get_real());
    double c = r1.get_complex() - (r2.get_complex());
    return complex(r, c);
}

complex william_lab_2::operator*(const complex &r1, const complex &r2)
{
    double r = r1.get_real() * r2.get_real();
    double c = r1.get_complex() * r2.get_complex();
    return complex(r * c);
}

complex william_lab_2::operator/(const complex &r1, const complex &r2)
{
    assert (r1.get_complex() != 0 && r2.get_complex() != 0);
    double r = r1.get_real() * r2.get_complex();
    double c = r2.get_real() * r1.get_complex();
    return complex(r / c);
}
